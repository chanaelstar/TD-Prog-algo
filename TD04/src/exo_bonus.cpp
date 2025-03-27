#include "fonction.hpp"

int main() {
    std::vector<int> vec(10);
    random_number(vec);
    std::cout << "Voici le tableau genere aleatoirement :" << std::endl;
    display(vec);
    std::cout << std::endl;

    int somme = square_sum(vec);
    std::cout << "Somme du carre des elements du vecteur : " << somme << std::endl;

    int produit = pair_prod(vec);
    std::cout << "Produit des elements pairs du vecteur : " << produit << std::endl;
}