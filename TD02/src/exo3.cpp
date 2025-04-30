#include "fonction.hpp"

int main()
{
    // std::string expression;
    // std::cout << "Entrez une expression en notation infixe : ";
    // std::getline(std::cin, expression); // 3 + 4 ^ 2 / ( 1 - 5 ) ^ 6
    // std::vector<Token> tokens = infix_to_npi_tokens(expression);

    // std::cout << "Expression en NPI : ";
    // print_npi_expression(tokens);  // 3 4 2 ^ 1 5 - 6 ^ / +
    // std::cout << std::endl;


    // Calculatrice 
    std::string expression;
    std::cout << "=== Calculatrice ===" << std::endl;
    std::cout << "Entrez une expression en notation infixe (ou 'exit' pour quitter) :" << std::endl;
    std::getline(std::cin, expression);
    std::cout << std::endl;
    while (expression != "exit") {
        std::vector<Token> tokens = infix_to_npi_tokens(expression);
        std::cout << "Expression en NPI : ";
        print_npi_expression(tokens);  
        std::cout << std::endl;

        std::cout << "Resultat : " << npi_evaluate(tokens) << std::endl;
        std::cout << "====================" << std::endl;
        std::cout << std::endl;

        // Demande une nouvelle expression
        std::cout << "Entrez une expression en notation infixe (ou 'exit' pour quitter) :" << std::endl;
        std::getline(std::cin, expression);
    }


    return 0;
}
