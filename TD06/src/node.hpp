#include <iostream>
#include <vector>
#include <stack>

// Exercice 1 - Implémentation
struct Node {
    int value;
    Node* left { nullptr };
    Node* right { nullptr };

    bool is_leaf() const ;
    void insert(int value);
    int height() const;
    void delete_childs();

    void display_infixe() const;
    std::vector<Node const*> prefixe() const;
    std::vector<Node const*> postfixe() const;

    int min() const;
    int max() const;

};


void pretty_print_left_right(Node const& node, std::string const& prefix, bool is_left);
void pretty_print_left_right(Node const& node);

Node* create_node(int value);

Node*& most_left(Node*& node);
bool remove(Node*& node, int value);
void delete_tree(Node* node);