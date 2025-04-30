#pragma once
#include <memory>
#include "smartNode.hpp"

class BinaryTree {
    public:
    std::unique_ptr<SmartNode> root { nullptr };

public:
    BinaryTree(int root_value);

    void insert(int value);
    bool remove(int value);
    void clear();
    size_t height() const;
};

void pretty_print_left_right(BinaryTree const& tree, std::string const& prefix, bool is_left);
void pretty_print_left_right(BinaryTree const& tree);