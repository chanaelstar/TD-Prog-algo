#include "fonction.hpp"

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