#include "fonction.hpp"

// Exercice 1 - Vector and Algorithm
void random_number(std::vector<int> &vec)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 100);

    for (size_t i = 0; i < vec.size(); ++i)
    {
        vec[i] = dis(gen);
    }
}

void display(const std::vector<int> &vec)
{
    for (auto iterator = vec.begin(); iterator != vec.end(); ++iterator)
    {
        std::cout << *iterator << " ";
    };
    std::cout << std::endl;
}

bool search_number(const std::vector<int> &vec, int number)
{
    return std::find(vec.begin(), vec.end(), number) != vec.end();
}

int occurrences(const std::vector<int> &vec, int number)
{
    return std::count(vec.begin(), vec.end(), number);
}

void sort_vector(std::vector<int> &vec)
{
    std::sort(vec.begin(), vec.end());
}

int sum_vector(std::vector<int> &vec)
{
    return std::accumulate(vec.begin(), vec.end(), 0);
}


// Exercice 2 - String