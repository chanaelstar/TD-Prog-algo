#include "node.hpp"

int main() {
    std::cout << "Exercice 1 - Implémentation" << std::endl;
    std::cout << "==========================" << std::endl;

    Node* root = create_node(10); // Racine de l’arbre

    // Insertion de valeurs
    root->insert(5);
    root->insert(15);
    root->insert(3);
    root->insert(7);
    root->insert(12);
    root->insert(20);

    
    // Affichage visuel de l'arbre
    std::cout << "Arbre (visuel gauche-droite) :" << std::endl;
    pretty_print_left_right(*root);
    std::cout << std::endl;

    // Affichage infixe
    std::cout << "Affichage infixe : ";
    root->display_infixe();
    std::cout << std::endl;

    // Affichage préfixe
    std::cout << "Affichage prefixe : ";
    for (auto node : root->prefixe()) {
        std::cout << node->value << " ";
    }
    std::cout << std::endl;

    // Affichage postfixe
    std::cout << "Affichage postfixe : ";
    for (auto node : root->postfixe()) {
        std::cout << node->value << " ";
    }
    std::cout << std::endl;
    std::cout << std::endl;

    // Hauteur de l'arbre
    std::cout << "Hauteur de l'arbre : " << root->height() << std::endl;

    // Valeurs minimale et maximale
    std::cout << "Valeur minimale : " << root->min() << std::endl;
    std::cout << "Valeur maximale : " << root->max() << std::endl;
    std::cout << std::endl;

    // Suppression de noeuds
    std::cout << "Suppression de la valeur 15 :" << std::endl;
    remove(root, 15);
    pretty_print_left_right(*root);
    std::cout << std::endl;

    std::cout << "Suppression de la valeur 10 (racine) :" << std::endl;
    remove(root, 10);
    if (root) {
        pretty_print_left_right(*root);
    } else {
        std::cout << "Arbre vide.";
    }
    std::cout << std::endl;

    // Suppression complète de l'arbre
    std::cout << "Suppression complete de l'arbre : ";
    delete_tree(root);
    root = nullptr; // Mettre le pointeur à nullptr après la suppression    
    if (root == nullptr) {
        std::cout << "Arbre supprime avec succes." << std::endl;
    }


return 0;
}