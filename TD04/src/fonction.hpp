#pragma once 
#include <iostream>
#include <vector>
#include <random>
#include <string>
#include <algorithm>
#include <cstdlib>



// Exercice 1 - Vector and Algorithm
void random_number (std::vector<int>& vec);
void display (const std::vector<int>& vec);
bool search_number (const std::vector<int>& vec, int nombre);
int occurrences(const std::vector<int>& vec, int nombre);
void sort_vector(std::vector<int>& vec);
int sum_vector(std::vector<int>& vec);


// Exercice 2 - String
size_t number_letters(std::string const& str);
std::vector<std::string> split_string(std::string const& str);


// Exercice 3 - Palindrome
bool is_palindrome(std::string const& str);


// Bonus - Pour aller plus loin (lambda)
int square_sum(std::vector<int> const &v);
int pair_prod(std::vector<int> const &v);