#include "fonction.hpp"

int main() {

    std::string sentence = "Hello World";
    std::cout << "Phrase : " << sentence << std::endl;
    std::cout << "Longueur du premier mot de la phrase : " << number_letters(sentence) << std::endl;
    std::cout << std::endl;
    
    std::cout << "Mots de la phrase : ";
    std::vector<std::string> words = split_string(sentence);
    for (auto word : words)
    {
        std::cout << word << " ";
    }
    std::cout << std::endl;

    return 0;
}
