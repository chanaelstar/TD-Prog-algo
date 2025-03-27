#include "fonction.hpp"

int main() {
    std::cout << is_palindrome("kayak") << std::endl; // true
    std::cout << is_palindrome("ressasser") << std::endl; // true
    std::cout << is_palindrome("hello") << std::endl; // false
    return 0;
}