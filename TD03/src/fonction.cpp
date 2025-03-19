#include "fonction.hpp"


bool is_sorted(std::vector<int> const& vec){ 
    return std::is_sorted(vec.begin(), vec.end()); }


// Exercice 1 (Tri itératif)
// Tri à bulles
void bubble_sort(std::vector<int> & vec){
    for (size_t i = 0; i < vec.size(); i++){
        for (size_t j = 0; j < vec.size()-1; j++){
            if (vec[j] > vec[j+1]){
                std::swap(vec[j], vec[j+1]);
            }
        }
    }
}


// Exercice 2 (Tri récursif)
// Tri par fusion
void merge_sort_merge(std::vector<int> & vec, size_t const left, size_t const middle, size_t const right){
    // Création des sous-tableau 
    std::vector<int> left_part(vec.begin() + left, vec.begin() + middle + 1);
    std::vector<int> right_part(vec.begin() + middle + 1, vec.begin() + right + 1);
    size_t i = 0;
    size_t j = 0;
    size_t k = left;
    while (i < left_part.size() && j < right_part.size()){
        if (left_part[i] < right_part[j]){
            vec[k] = left_part[i];
            i++;
        } else {
            vec[k] = right_part[j];
            j++;
        }
        k++;
    }
    while (i < left_part.size()){
        vec[k] = left_part[i];
        i++;
        k++;
    }
    while (j < right_part.size()){
        vec[k] = right_part[j];
        j++;
        k++;
    }
}

void merge_sort(std::vector<int> & vec, size_t const left, size_t const right){
    // Processus de tri 
    if (left < right){
        size_t middle = left + (right - left) / 2;
        merge_sort(vec, left, middle);
        merge_sort(vec, middle + 1, right);
        merge_sort_merge(vec, left, middle, right);
    }
}

void merge_sort(std::vector<int> & vec) {
    merge_sort(vec, 0, vec.size()-1);
}


// Exercice 3 (Comparaison des algorithmes de tri)
std::vector<int> generate_random_vector(size_t const size, int const max) {
    std::vector<int> vec(size);
    std::generate(vec.begin(), vec.end(), [&max]() { return std::rand() % max;} );
    return vec;
}


// Exercice 4 (recherche dichotomique)
size_t search(std::vector<int> & vec, size_t const left, size_t const right, int const searched_value){
    if (left > right){
        return -1;
    }
    int middle = (left + right) / 2;
    if (vec[middle] == searched_value){
        return middle;
    } else if (vec[middle] < searched_value){
        return search(vec, middle + 1, right, searched_value);
    } else {
        return search(vec, left, middle - 1, searched_value);
    }
}