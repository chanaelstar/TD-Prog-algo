#include "fonction.hpp"

int main()
{
    std::vector<int> array {1, 2, 2, 3, 4, 8, 12};
    int searched_value = 8;
    
    std::cout << search(array, 0, array.size()-1, searched_value) << std::endl;

    return 0;

}