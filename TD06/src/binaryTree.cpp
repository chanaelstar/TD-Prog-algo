#include "binaryTree.hpp"
#include "smartNode.hpp"


BinaryTree::BinaryTree(int root_value)
{
    root = create_smart_node(root_value);
}

// Affichage de l'arbre dans la console
void pretty_print_left_right(BinaryTree const& tree){
    pretty_print_left_right(*tree.root);
}

void BinaryTree::insert(int value){
    root->insert(value);
}

bool BinaryTree::remove(int value){
    ::remove(root,value);
    return true;
}

void BinaryTree::clear(){
    root.reset();
}

size_t BinaryTree::height() const{
    return root->height();
}

