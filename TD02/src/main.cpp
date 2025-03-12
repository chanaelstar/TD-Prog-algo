#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <sstream>
#include <iterator>
#include <cctype>
#include <cmath>

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

int main()
{
    std::string expression;
    std::cout << "Entrez une expression en notation polonaise inversee : ";
    std::getline(std::cin, expression);
    std::vector<std::string> tokens = split_string(expression);

    for (std::string token : tokens){
        if (is_floating(token)){
            std::cout << "Nombre : " << token << std::endl;
        } else {
            std::cout << "Operateur : " << token << std::endl;
        }
    }

    // Exercice 1.5
    std::cout << "Resultat : " << npi_evaluate(tokens) << std::endl;
    return 0;

}