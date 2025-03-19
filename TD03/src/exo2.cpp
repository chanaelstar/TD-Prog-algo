#include "fonction.hpp"

int main()
{
    std::vector<int> array {42, 31, 59, 47, 13, 37, 19};


    std::cout << "Tableau initial :" << std::endl;
    for (int num : array) std::cout << num << " ";
    std::cout << std::endl;

    merge_sort(array);
    
    std::cout << "Tableau apres tri :" << std::endl;
    for (int num : array) std::cout << num << " ";
    std::cout << std::endl;

    return 0;

}