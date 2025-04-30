#include "node.hpp"
#include "smartNode.hpp"
#include "binaryTree.hpp"

int main() {
    std::cout << "Exercice 4 - Encapsulation" << std::endl;
    std::cout << "==========================" << std::endl;

    BinaryTree tree{5}; // Racine de l’arbre

    // Insertion des valeurs suivantes: 5, 3, 7, 2, 4, 6, 8, 1, 9, 0.
    tree.insert(3);
    tree.insert(7);
    tree.insert(2);
    tree.insert(4);
    tree.insert(6);
    tree.insert(8);
    tree.insert(1);
    tree.insert(9);
    tree.insert(0);

    // Affichage visuel de l'arbre
    std::cout << "Arbre (visuel gauche-droite) :" << std::endl;
    pretty_print_left_right(tree);
    std::cout << std::endl;

    // Fonctionnalité de suppression
    std::cout << "Suppression de la valeur 3, arbre apres suppression : " << std::endl;
    tree.remove(3);
    pretty_print_left_right(tree);
    std::cout << std::endl;

    // Hauteur
    std::cout << "Hauteur de l'arbre : " << tree.height() << std::endl;
    std::cout << std::endl;


    // Nettoyage
    // tree.clear();
    // std::cout << "Arbre apres clear :" << std::endl;
    // pretty_print_left_right(tree);
    // std::cout << std::endl;

    return 0;
}