#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>


bool is_sorted(std::vector<int> const& vec);

// Exercice 1 
void bubble_sort(std::vector<int> & vec);

// Exercice 2
void merge_sort_merge(std::vector<float> & vec, size_t const left, size_t const middle, size_t const right);
void merge_sort(std::vector<float> & vec, size_t const left, size_t const right);
