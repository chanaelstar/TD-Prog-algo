#include "smartNode.hpp"

// Affichage dans la console 
void pretty_print_left_right(SmartNode const& node, std::string const& prefix, bool is_left) {
    if (node.right) {
        pretty_print_left_right(*node.right, prefix + (is_left ? "|   " : "    "), false);
    }
    std::cout << prefix << (is_left ? "+-- " : "+-- ") << node.value << std::endl;
    if (node.left) {
        pretty_print_left_right(*node.left, prefix + (is_left ? "    " : "|   "), true);
    }
}


void pretty_print_left_right(SmartNode const& node) {
    pretty_print_left_right(node, "", true);
}

// Création d'un noeud
std::unique_ptr<SmartNode> create_smart_node(int value){
    std::unique_ptr<SmartNode> newNode = std::make_unique<SmartNode>();
    newNode->value = value;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

// Le noeud est-il une feuille ?
bool SmartNode::is_leaf() const {
    return !left && !right;
}


// insertion d'un nouveau noeud
void SmartNode::insert(int value){
    if (value < this->value) {
        if (left == nullptr) {
            left = create_smart_node(value);
        } else {
            left->insert(value);
        }
    } else if (value > this->value) {
        if (right == nullptr) {
            right = create_smart_node(value);
        } else {
            right->insert(value);
        }
    }
}

// Hauteur de l'arbre
size_t SmartNode::height() const{
    if (is_leaf()) {
        return 1;
    } else {
        size_t left_height = left ? left->height() : 0;
        size_t right_height = right ? right->height() : 0;
        return 1 + std::max(left_height, right_height);
    }
}



// Valeur minimale et maximale de l'arbre
int SmartNode::min() const {
    if (left) {
        return left->min();
    } else {
        return value;
    }
}
int SmartNode::max() const {
    if (right) {
        return right->max();
    } else {
        return value;
    }
}


std::unique_ptr<SmartNode>& most_left(std::unique_ptr<SmartNode>& node){
    if (node->left) {
        return most_left(node->left);
    } else {
        return node;
    }
}
bool remove(std::unique_ptr<SmartNode>& node, int value){
    if (node == nullptr) {
        return false; 
    }

    if (value < node->value) {
        return remove(node->left, value);
    } else if (value > node->value) {
        return remove(node->right, value);
    } else {
        // Noeud trouvé
        // Cas 1 : Le noeud est une feuille
        if (node->is_leaf()) {
            node = nullptr;
        // Cas 2 : Le nœud à supprimer a un seul fils
        } else if (node->left == nullptr) {
            node = std::move(node->right);
        } else if (node->right == nullptr) {
            node = std::move(node->left);
        // Cas 3 : Le nœud à supprimer a deux fils
        } else {
            std::unique_ptr<SmartNode>& most_left_node = most_left(node->right);
            node->value = most_left_node->value;
            remove(node->right, most_left_node->value);
        }
        return true; // Valeur supprimée avec succès
    }
    return false; // Valeur non trouvée
}

