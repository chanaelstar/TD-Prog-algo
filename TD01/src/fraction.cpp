#include "fraction.hpp"
#include "utils.hpp"

#include <iostream>

// void Fraction::display() {
// Exercice2 (affichage)
std::ostream& operator<<(std::ostream& os, Fraction const& f){
    os << f.numerator << "/" << f.denominator;
    return os;
}


//Exercice 1 (opérations) en commentaire et Exercice 5
// Fraction operator+(Fraction const& f1, Fraction const& f2){
//     return simplify({
//         f1.numerator * f2.denominator + f2.numerator * f1.denominator,
//         f1.denominator * f2.denominator
//     });
// };
Fraction operator+(Fraction &f1, Fraction const& f2) {
    f1 += f2;
    return f1;
}

// Fraction operator-(Fraction const& f1, Fraction const& f2) {
//     return simplify({
//         f1.numerator * f2.denominator - f2.numerator * f1.denominator,
//         f1.denominator * f2.denominator
//     });
// }
Fraction operator-(Fraction &f1, Fraction const& f2) {
    f1 -= f2;
    return f1;
}

// Fraction operator*(Fraction const& f1, Fraction const& f2) {
//     return simplify({
//         f1.numerator * f2.numerator,
//         f1.denominator * f2.denominator
//     });
// }
Fraction operator*(Fraction &f1, Fraction const& f2) {
    f1 *= f2;
    return f1;
}

// Fraction operator/(Fraction const& f1, Fraction const& f2) {
//     return simplify({
//         f1.numerator * f2.denominator,
//         f1.denominator * f2.numerator
//     });
// }
Fraction operator/(Fraction &f1, Fraction const& f2) {
    f1 /= f2;
    return f1;
}


    // Exercice 3 (égalité)
bool operator==(Fraction const& f1, Fraction const& f2) {
    return f1.numerator * f2.denominator == f1.denominator * f2.numerator;
}

bool operator!=(Fraction const& f1, Fraction const& f2) {
    return !(f1 == f2);
    }


    // Exercice 4 (comparaison)
bool operator< (Fraction const& f1, Fraction const& f2) {
    return
        f1.numerator * f2.denominator < f1.denominator * f2.numerator;
    }

bool operator> (Fraction const& f1, Fraction const& f2) {
    return f2 < f1;
    }
bool operator<=(Fraction const& f1, Fraction const& f2) {
    return !(f1 > f2);
    }
bool operator>=(Fraction const& f1, Fraction const& f2) {
    return !(f1 < f2);
    }


    // Exercice 5 (opérations d'affectation)
void Fraction::operator+=(Fraction const& f) {
    this->numerator = this->numerator * f.denominator + f.numerator * this->denominator;
    this->denominator = this->denominator * f.denominator;
    
    *this = simplify(*this);
}

void Fraction::operator-=(Fraction const& f) {
    this->numerator = this->numerator * f.denominator - f.numerator * this->denominator;
    this->denominator = this->denominator * f.denominator;
    
    *this = simplify(*this);
}

void Fraction::operator*=(Fraction const& f) {
    this->numerator = this->numerator * f.numerator;
    this->denominator = this->denominator * f.denominator;
    
    *this = simplify(*this);
}

void Fraction::operator/=(Fraction const& f) {
    this->numerator = this->numerator * f.denominator;
    this->denominator = this->denominator * f.numerator;
    
    *this = simplify(*this);
}




    // Exercice 6 (conversion)
float Fraction::to_float() const {
    return static_cast<float>(numerator) / denominator;
}

Fraction::operator float() const {
    return to_float();
}
