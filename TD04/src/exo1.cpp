#include "fonction.hpp"

int main() {
    
    std::vector<int> vec(10);
    random_number(vec);
    std::cout << "Voici le tableau genere aleatoirement :" << std::endl;
    display(vec);
    std::cout << std::endl;

    int number;
    std::cout << "Entrez un nombre a rechercher dans le tableau : ";
    std::cin >> number;

    if (search_number(vec, number)){
        std::cout << number << " se trouve dans le tableau." << std::endl;
    }else{
        std::cout << number << " n'est pas dans le tableau." << std::endl;
    }
    std::cout << std::endl;

    int occurences = occurrences(vec, number);
    std::cout << "Le nombre " << number << " est present " << occurences << " fois dans le tableau." << std::endl;
    std::cout << std::endl;

    sort_vector(vec);
    std::cout << "Voici le tableau trie : " << std::endl;
    display(vec);
    std::cout << std::endl;

    int somme = sum_vector(vec);
    std::cout << "Somme de toutes les valeurs du vecteur : " << somme << std::endl;

    return 0;
}
