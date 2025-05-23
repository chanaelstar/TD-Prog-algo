#include <iostream>
#include "fraction.hpp"

int main()
{
    Fraction f1 { 3, 4 };
    Fraction f2 { 1, 2 };
    

    std::cout << "f1 = " << f1 << std::endl;
    std::cout << static_cast<float>(f1) << std::endl;
    // std::cout <<  f1;

    std::cout << "f2 = " << f2 << std::endl;
    std::cout << std::endl;

    Fraction f3 { f1 + f2 };

    // std::cout << "add(f1, f2) = " << f3 ;

    // std::cout << std::endl << "sub(f1, f2) = " << (operator- (f1, f2));

    // std::cout << std::endl << "mul(f1, f2) = " << (operator* (f1, f2));

    // std::cout << std::endl << "div(f1, f2) = " << (operator/ (f1, f2));

    // std::cout << std::endl << "add(1/6, 2/6) = " << (operator+({1, 6}, {2, 6})) << std::endl;
    std::cout << std::endl << "add(1/6, 2/6) = " << f1 + f2 << std::endl;
    std::cout << std::endl;


    // exercice 3
    if (f1 == f2)
    {
        std::cout << "Les fractions " << f1 << " et " <<  f2 << " sont egales." << std::endl;
    }
    else
    {
        std::cout << "Les fractions " << f1 << " et " <<  f2 << " sont differentes." << std::endl;
    }
    std::cout << std::endl;


    if (f1 != f2)
    {
        std::cout << "Les fractions f1 et f2 sont differentes." << std::endl;
    }
    else
    {
        std::cout << "Les fractions f1 et f2 sont egales." << std::endl;
    }
    std::cout << std::endl;
    std::cout << std::endl;


    // exercice 4
    // <
    if (f1 < f2)
    {
        std::cout << "La fraction f1 est inferieure a la fraction f2." << std::endl;
    }
    else
    {
        std::cout << "La fraction f1 est superieure a la fraction f2." << std::endl;
    }
    std::cout << std::endl;

    //>
    if (f2 < f1)
    {
        std::cout << "La fraction f2 est inferieure a la fraction f1." << std::endl;
    }
    else
    {
        std::cout << "La fraction f2 est superieure a la fraction f1." << std::endl;
    }
    std::cout << std::endl;

    // <=
    if (f1 <= f2)
    {
        std::cout << "La fraction f1 est inferieure ou egale a la fraction f2." << std::endl;
    }
    else
    {
        std::cout << "La fraction f1 est superieure ou egale a la fraction f2." << std::endl;
    }
    std::cout << std::endl;

    // >=
    if (f1 >= f2)
    {
        std::cout << "La fraction f1 est superieure ou egale a la fraction f2." << std::endl;
    }
    else
    {
        std::cout << "La fraction f1 est inferieure ou egale a la fraction f2." << std::endl;
    }
    std::cout << std::endl;
    std::cout << std::endl;


    // exercice 5
    f3 = f1;
    f3 += f2;
    std::cout << "f1 += f2 = " << f3 << std::endl;

    f3 = f1;
    f3 -= f2;
    std::cout << "f1 -= f2 = " << f3 << std::endl;

    f3 = f1;
    f3 *= f2;
    std::cout << "f1 *= f2 = " << f3 << std::endl;

    f3 = f1;
    f3 /= f2;
    std::cout << "f1 /= f2 = " << f3 << std::endl;
    std::cout << std::endl;


    // exercice 6
    float floatNumber = static_cast<float>(f1);
    std::cout << "f1 en format de type float = " << floatNumber << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;



    // Aller plus loin (fonctions libres & opérations mathématiques)
    std::cout << "Bonus : aller plus loin (fonctions libres & operations mathematiques)" << std::endl;
    Fraction f { 3, 4 };
    int i { 2 };

    std::cout << "f + i = " << static_cast<float>(f + i) << std::endl;
    std::cout << "i + f = " << static_cast<float>(i + f) << std::endl;
    std::cout << std::endl;

    std::cout << "f - i = " << static_cast<float>(f - i) << std::endl;
    std::cout << "i - f = " << static_cast<float>(i - f) << std::endl;
    std::cout << std::endl;

    std::cout << "f * i = " << static_cast<float>(f * i) << std::endl;
    std::cout << "i * f = " << static_cast<float>(i * f) << std::endl;
    std::cout << std::endl;

    std::cout << "f / i = " << static_cast<float>(f / i) << std::endl;
    std::cout << "i / f = " << static_cast<float>(i / f) << std::endl;
    std::cout << std::endl;

    std::cout << "Fonction mathematiques sur f = 3/4" << std::endl;
    std::cout << "abs(f) = " << static_cast<float>(f.abs()) << std::endl; // valeur absolue de 3/4
    std::cout << "ceil(f) = " << static_cast<float>(f.ceil()) << std::endl; // arrondi supérieur de 3/4
    std::cout << "floor(f) = " << static_cast<float>(f.floor()) << std::endl; // arrondi inférieur de 3/4
    std::cout << "round(f) = " << static_cast<float>(f.round()) << std::endl; // arrondi de 3/4
    std::cout << std::endl;







    return 0;

}