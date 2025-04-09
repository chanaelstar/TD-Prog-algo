#include "node.hpp"


// Exercice 1 - Implémentation

// Affichage dans la console 
void pretty_print_left_right(Node const& node, std::string const& prefix, bool is_left) {
    if (node.right) {
        pretty_print_left_right(*node.right, prefix + (is_left ? "|   " : "    "), false);
    }
    std::cout << prefix << (is_left ? "+-- " : "+-- ") << node.value << std::endl;
    if (node.left) {
        pretty_print_left_right(*node.left, prefix + (is_left ? "    " : "|   "), true);
    }
}

void pretty_print_left_right(Node const& node) {
    pretty_print_left_right(node, "", true);
}

// Création d'un noeud
Node* create_node(int value){
    Node* newNode = new Node;
    newNode->value = value;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

// Le noeud est-il une feuille ?
bool Node::is_leaf() const {
    return left == nullptr && right == nullptr;
}

// Insertion d'un nouveau noeud
void Node::insert(int value){
    if (value < this->value) {
        if (left == nullptr) {
            left = create_node(value);
        } else {
            left->insert(value);
        }
    } else if (value > this->value) {
        if (right == nullptr) {
            right = create_node(value);
        } else {
            right->insert(value);
        }
    }
}

 // Hauteur de l'arbre
 int Node::height() const{
    if (is_leaf()) {
        return 1;
    } else {
        int left_height = left ? left->height() : -1;
        int right_height = right ? right->height() : -1;
        return 1 + std::max(left_height, right_height);
    }
}

// Supprime tous les fils du noeud
void Node::delete_childs() {
    if (left) {
        left->delete_childs();
        delete left;
        left = nullptr;
    }
    if (right) {
        right->delete_childs();
        delete right;
        right = nullptr;
    }
}

 // Affichage de l'arbre dans l'ordre infixe
 void Node::display_infixe() const{
    if (left) {
        left->display_infixe();
    }
    std::cout << value << " ";
    if (right) {
        right->display_infixe();
    }
}

// Affichage de l'arbre dans l'ordre préfixe
std::vector<Node const*> Node::prefixe() const{
    std::vector<Node const*> nodes;
    nodes.push_back(this);
    if (left) {
        std::vector<Node const*> left_nodes = left->prefixe();
        nodes.insert(nodes.end(), left_nodes.begin(), left_nodes.end());
    }
    if (right) {
        std::vector<Node const*> right_nodes = right->prefixe();
        nodes.insert(nodes.end(), right_nodes.begin(), right_nodes.end());
    }
    return nodes;
}


// Affichage de l'arbre dans l'ordre postfixe (bonus)

// RÉCURSIF
std::vector<Node const*> Node::postfixe() const{
    std::vector<Node const*> nodes;
    if (left) {
        std::vector<Node const*> left_nodes = left->postfixe();
        nodes.insert(nodes.end(), left_nodes.begin(), left_nodes.end());
    }
    if (right) {
        std::vector<Node const*> right_nodes = right->postfixe();
        nodes.insert(nodes.end(), right_nodes.begin(), right_nodes.end());
    }
    nodes.push_back(this);
    return nodes;
}

// ITÉRATIF
// std::vector<Node const*> Node::postfixe() const {
//     std::vector<Node const*> nodes {};
//     std::stack<Node const*> to_process {};
//     Node const* previous {nullptr};
//     to_process.push(this);

//     while (!to_process.empty()) {
//         Node const* current { to_process.top() };

//         // Si on est en train de descendre dans l'arbre
//         if (previous == nullptr || (previous->left == current || previous->right == current)) {
//             if(current->left != nullptr) {
//                 to_process.push(current->left);
//             }
//             else if(current->right != nullptr) {
//                 to_process.push(current->right);
                
//             } else {
//                 // on traite le nœud (ajouter au vecteur) et on le retire de la pile
//                 nodes.push_back(current);
//                 to_process.pop();
//             }

//         // Si l'on remonte dans l'arbre en venant de la gauche
//         }else if (previous == current->left) {
//             if(current->right != nullptr) {
//                 to_process.push(current->right);
            
//             } else {
//                 nodes.push_back(current);
//                 to_process.pop();
//             }

//         // Si l'on remonte dans l'arbre en venant de la droite
//         } else if (previous == current->right) {
//             nodes.push_back(current);
//             to_process.pop();
//         }

//         previous = current;

//     }
//     return nodes;
// }

Node*& most_left(Node*& node){
    Node** tmp = &node;
    while ((*tmp)->left != nullptr) {
        tmp = &(*tmp)->left;
    }
    return *tmp;
}

bool remove(Node*& node, int value){
    if (node == nullptr) {
        return false; // Valeur non trouvée
    }

    if (value < node->value) {
        return remove(node->left, value);
    } else if (value > node->value) {
        return remove(node->right, value);
    } else {
        // Noeud trouvé
        // Cas 1 : Le noeud est une feuille
        if (node->is_leaf()) {
            delete node;
            node = nullptr;

        // Cas 2 : Le nœud à supprimer a un seul fils
        } else if (node->left == nullptr) {
            Node* temp = node;
            node = node->right;
            delete temp;
        } else if (node->right == nullptr) {
            Node* temp = node;
            node = node->left;
            delete temp;
        
        // Cas 3 : Le nœud à supprimer a deux fils
        } else {
            Node*& most_left_node = most_left(node->right);
            node->value = most_left_node->value;
            remove(node->right, most_left_node->value);
        }
        return true; // Valeur supprimée avec succès
    }
    return false; // Valeur non trouvée
}


// Supprime l'arbre
void delete_tree(Node* node){
    if (node) {
        delete_tree(node->left);
        delete_tree(node->right);
        delete node;
    }
    node = nullptr;
}

// Minimal et maximal de l'arbre
int Node::min() const {
    if (left) {
        return left->min();
    } else {
        return value;
    }
}
int Node::max() const {
    if (right) {
        return right->max();
    } else {
        return value;
    }
}