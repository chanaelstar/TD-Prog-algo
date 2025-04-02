#include "fonction.hpp"

int main() {
    std::vector<std::string> strings {"IMAC", "MICA"};

    for(std::string const& s: strings){
        size_t const hash {folding_string_hash_sum (s, 100)};
        std::cout << " Folding Hash Sum of " << s << " is: " << hash << std::endl;
    }
    std::cout << std::endl;

    for(std::string const& s: strings){
        size_t const hash {folding_string_ordered_hash (s, 100)};
        std::cout << "Folding ordered Hash of " << s << " is: " << hash << std::endl;
    }
    std::cout << std::endl;


     for(std::string const& s: strings){
        size_t const hash {polynomial_rolling_hash (s, 31, 1000000009)};
        std::cout << "Polynominal rolling Hash of " << s << " is: " << hash << std::endl;
    }


    return 0;
}