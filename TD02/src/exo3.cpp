#include "fonction.hpp"

int main()
{
    std::string expression;
    std::cout << "Entrez une expression en notation infixe : ";
    std::getline(std::cin, expression); // 3 + 4 ^ 2 / ( 1 - 5 ) ^ 6
    std::vector<Token> tokens = infix_to_npi_tokens(expression);

    std::cout << "Expression en NPI : ";
    print_npi_expression(tokens);  // 3 4 2 ^ 1 5 - 6 ^ / +
    std::cout << std::endl;

    return 0;
}
