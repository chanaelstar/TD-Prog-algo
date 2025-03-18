#include "fonction.hpp"

int main()
{
    std::vector<int> array {9, 2, 3, 8, 5, 6, 4, 7, 1};

    if (is_sorted(array)) {
    std::cout << "Le tableau est trie" << std::endl;
    } else {
    std::cout << "Le tableau n'est pas trie" << std::endl;
    }


    std::cout << "Tableau initial :" << std::endl;
    for (int num : array) std::cout << num << " ";
    std::cout << std::endl;

    bubble_sort(array);

    std::cout << "Tableau apres tri à bulles (bubble sort) :" << std::endl;
    for (int num : array) std::cout << num << " ";
    std::cout << std::endl;

    return 0;

}