#include "fonction.hpp"

int main()
{
    std::string words;
    std::cout << "Entrez une expression en notation polonaise inversee : ";
    std::getline(std::cin, words);
    std::vector<std::string> tokens = split_string(words);

    for (std::string token : tokens){
        if (is_floating(token)){
            std::cout << "Nombre : " << token << std::endl;
        } else {
            std::cout << "Operateur : " << token << std::endl;
        }
    }

    std::cout << "Resultat : " << npi_evaluate(tokens) << std::endl;
    return 0;
}
