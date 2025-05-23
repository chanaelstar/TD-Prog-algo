#include "fonction.hpp"

std::vector<std::string> split_string(std::string const& s)
{
    std::istringstream in(s); // transforme une chaîne en flux de caractères, cela simule un flux comme l'est std::cin
    // l’itérateur va lire chaque element de "in", comme un flux d'entrée, chaque élément est séparé par un espace
    return std::vector<std::string>(std::istream_iterator<std::string>(in), std::istream_iterator<std::string>()); 
}

bool is_floating(std::string const& s){
    for (char c : s){
        if (!std::isdigit(c) && c != '.'){
            return false;
        }
    }
    return true;
}

//EXERCICE 1
float npi_evaluate(std::vector<std::string> const& tokens){
    std::stack<float> stack;
    for (std::string token : tokens){
        if (is_floating(token)){
            stack.push(std::stof(token));
        } else {
            float operand2 = stack.top();
            stack.pop();
            float operand1 = stack.top();
            stack.pop();
            if (token == "+"){
                stack.push(operand1 + operand2);
            } else if (token == "-"){
                stack.push(operand1 - operand2);
            } else if (token == "*"){
                stack.push(operand1 * operand2);
            } else if (token == "/"){
                stack.push(operand1 / operand2);
            }else if (token == "^"){
                stack.push(std::pow(operand1, operand2));
            } else {
                throw std::runtime_error("Operateur inconnu : " + token);
        }
    }
}
return stack.top();
throw std::runtime_error("Pas de token a evaluer");
return 0.f;
}


//EXERCICE 2
Token make_token(float value){
    return {TokenType::OPERAND, value};
}
Token make_token(Operator op){
    return {TokenType::OPERATOR,0.f, op};
}

std::vector<Token> tokenize(std::vector<std::string> const& words){
    std::vector<Token> tokens;
    for (std::string word : words){
        if (is_floating(word)){
            tokens.push_back(make_token(std::stof(word)));
        } else {
            if (word == "+"){
                tokens.push_back(make_token(Operator::ADD));
            } else if (word == "-"){
                tokens.push_back(make_token(Operator::SUB));
            } else if (word == "*"){
                tokens.push_back(make_token(Operator::MUL));
            } else if (word == "/"){
                tokens.push_back(make_token(Operator::DIV));
            } else if (word == "^"){
                tokens.push_back(make_token(Operator::POW));
            } else if (word == "(" ){
                tokens.push_back(make_token(Operator::OPEN_PAREN));
            } else if (word == ")" ){
                tokens.push_back(make_token(Operator::CLOSE_PAREN));
            
            } else {
                throw std::runtime_error("Operateur inconnu : " + word);
            }
        }
    }
    return tokens;
}

float npi_evaluate(std::vector<Token> const& tokens){
    std::stack<float> stack;
    for (Token token : tokens){
        if (token.type == TokenType::OPERAND){
            stack.push(token.value);
        } else {
            float operand2 = stack.top();
            stack.pop();
            float operand1 = stack.top();
            stack.pop();
            if (token.op == Operator::ADD){
                stack.push(operand1 + operand2);
            } else if (token.op == Operator::SUB){
                stack.push(operand1 - operand2);
            } else if (token.op == Operator::MUL){
                stack.push(operand1 * operand2);
            } else if (token.op == Operator::DIV){
                stack.push(operand1 / operand2);
            } else if (token.op == Operator::POW){
                stack.push(std::pow(operand1, operand2));
            } else {
                throw std::runtime_error("Operateur inconnu");
            }
        }
    }
    return stack.top();
    throw std::runtime_error("Pas de token a evaluer");
    return 0.f;
}


//EXERCICE 3
int operator_precedence(Operator const op){
    switch (op) {
        case Operator::ADD:
        case Operator::SUB:
            return 1;
        case Operator::MUL:
        case Operator::DIV:
            return 2;
        case Operator::POW:
            return 3;
        case Operator::OPEN_PAREN:
        case Operator::CLOSE_PAREN:
            return 0; 
        default:
            return -1; 
    }

}

std::vector<Token> infix_to_npi_tokens(std::string const& expression){
    std::vector<Token> output;
    std::stack<Token> operators;
    std::vector<std::string> words = split_string(expression);
    std::vector<Token> tokens = tokenize(words);

    for (Token token : tokens){
        if (token.type == TokenType::OPERAND){
            output.push_back(token);
        } else if (token.type == TokenType::OPERATOR) {
            if (token.op == Operator::OPEN_PAREN) {
                operators.push(token);
            } else if (token.op == Operator::CLOSE_PAREN) {
                while (!operators.empty() && operators.top().op != Operator::OPEN_PAREN) {
                    output.push_back(operators.top());
                    operators.pop();
                }
                if (!operators.empty()) {
                    operators.pop(); 
                }
            } else { 
            while (!operators.empty() && operator_precedence(operators.top().op) >= operator_precedence(token.op)) {
                output.push_back(operators.top());
                operators.pop();
            }
            operators.push(token);
        }
        }
    }

    while (!operators.empty()) {
        output.push_back(operators.top());
        operators.pop();
    }

    return output;
}

// Affichage de l'expression en notation polonaise inverse
void print_npi_expression(std::vector<Token> const& tokens){
    for (Token token : tokens){
        if (token.type == TokenType::OPERAND){
            std::cout << token.value << " ";
        } else {
            switch (token.op) {
                case Operator::ADD:
                    std::cout << "+" << " ";
                    break;
                case Operator::SUB:
                    std::cout << "-" << " ";
                    break;
                case Operator::MUL:
                    std::cout << "*" << " ";
                    break;
                case Operator::DIV:
                    std::cout << "/" << " ";
                    break;
                case Operator::POW:
                    std::cout << "^" << " ";
                    break;
                default:
                    break;
            }
        }
    }
    std::cout << std::endl;
}