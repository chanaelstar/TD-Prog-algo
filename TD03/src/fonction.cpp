#include "fonction.hpp"


bool is_sorted(std::vector<int> const& vec){ 
    return std::is_sorted(vec.begin(), vec.end()); }


// Exercice 1
void bubble_sort(std::vector<int> & vec){
    for (int i = 0; i < vec.size(); i++){
        for (int j = 0; j < vec.size()-1; j++){
            if (vec[j] > vec[j+1]){
                std::swap(vec[j], vec[j+1]);
            }
        }
    }
}

// Exercice 2
void merge_sort(std::vector<float> & vec) {
    merge_sort(vec, 0, vec.size()-1);
}
