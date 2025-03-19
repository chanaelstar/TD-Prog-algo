#include "fonction.hpp"
#include "ScopedTimer.hpp"

int main()
{

    std::vector<int> array {generate_random_vector(1000)};
    std::sort(array.begin(), array.end());


    {
        ScopedTimer timer("merge_sort ");
        merge_sort(array);
    }

    {
        ScopedTimer timer("bubble_sort ");
        bubble_sort(array);
    }

    {
        ScopedTimer timer("std::sort ");
        std::sort(array.begin(), array.end());
    }

    // Avec cette fonction, vous pouvez comparer les temps d'exécution de vos algorithmes de tri avec celui de la bibliothèque standard.

    // Que constatez-vous ?
    // Que pouvez-vous en dire ?

        // Le tri à bulles (bubble_sort) est très lent, notamment sur de grandes tailles de données, en raison de sa complexité en O(n²).
        // Le tri par fusion (merge_sort) offre de bien meilleures performances, avec une complexité en O(n log n), ce qui le rend plus adapté aux grandes entrées.
        // La fonction std::sort est la plus rapide, car elle utilise des optimisations avancées et des algorithmes hybrides pour maximiser l'efficacité.
    
    return 0;

}