#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdlib>
#include <map>

bool is_sorted(std::vector<int> const& vec);

// Exercice 1 
void bubble_sort(std::vector<int> & vec);

// Exercice 2
void merge_sort_merge(std::vector<int> & vec, size_t const left, size_t const middle, size_t const right);
void merge_sort(std::vector<int> & vec, size_t const left, size_t const right);
void merge_sort(std::vector<int> & vec);

// Exercice 3
std::vector<int> generate_random_vector(size_t const size, int const max = 100);

// Exercice 4
size_t search(std::vector<int> & vec, size_t const left, size_t const right, int const searched_value);


// Pour aller plus loin: Counting sort
// int occurrences(const std::vector<int>& vec, int nombre);
void counting_sort(std::vector<int> & vec);




