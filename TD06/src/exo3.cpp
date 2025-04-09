#include "node.hpp"
#include "smartNode.hpp"

int main() {
    std::cout << "Exercice 3 - Pointeur intelligent" << std::endl;
    std::cout << "==========================" << std::endl;

    std::unique_ptr<SmartNode> root = create_smart_node(5); // Racine de l’arbre

    // Insertion des valeurs suivantes: 5, 3, 7, 2, 4, 6, 8, 1, 9, 0.
    root->insert(3);
    root->insert(7);
    root->insert(2);
    root->insert(4);
    root->insert(6);
    root->insert(8);
    root->insert(1);
    root->insert(9);
    root->insert(0);

    // Affichage visuel de l'arbre
    std::cout << "Arbre (visuel gauche-droite) :" << std::endl;
    pretty_print_left_right(*root);
    std::cout << std::endl;


    // // Affichage infixe
    // std::cout << "Affichage infixe : ";
    // root->display_infixe();
    // std::cout << std::endl;

    // Valeurs minimale et maximale
    std::cout << "Valeur minimale : " << root->min() << std::endl;
    std::cout << "Valeur maximale : " << root->max() << std::endl;

    // Hauteur de l'arbre
    std::cout << "Hauteur de l'arbre : " << root->height() << std::endl;
    std::cout << std::endl;


    // // Affichage préfixe + somme des valeurs 
    // std::cout << "Affichage prefixe : ";

    // int sum = 0;
    // for (auto node : root->prefixe()) {
    //     sum += node->value;
    //     std::cout << node->value << " ";
    // }
    // std::cout << std::endl;
    // std::cout << "Somme des valeurs des noeuds (ordre prefixe) : " << sum << std::endl; 
    // std::cout << std::endl;   


    return 0;
}