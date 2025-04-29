#pragma once
#include <iostream>
#include <cmath>


struct Fraction {
    // unsigned 
    int numerator;
    // unsigned 
    int denominator;
    void operator+=(Fraction const& f);
    void operator-=(Fraction const& f);
    void operator*=(Fraction const& f); 
    void operator/=(Fraction const& f);

    // void display();
    float to_float() const;
    operator float() const;
    
    // opérations mathématiques (bonus)
    Fraction abs() const;
    Fraction ceil() const;
    Fraction floor() const;
    Fraction round() const;
};


std::ostream& operator<<(std::ostream& os, Fraction const& f);


// Fraction operator+(Fraction const& f1, Fraction const& f2);
Fraction operator+(Fraction & f1, Fraction const& f2);

// Fraction operator- (Fraction const& f1, Fraction const& f2);
Fraction operator-(Fraction &f1, Fraction const& f2);

// Fraction operator*(Fraction const& f1, Fraction const& f2);
Fraction operator*(Fraction &f1, Fraction const& f2);

// Fraction operator/(Fraction const& f1, Fraction const& f2);
Fraction operator/(Fraction &f1, Fraction const& f2);


bool operator==(Fraction const& f1, Fraction const& f2);
bool operator!=(Fraction const& f1, Fraction const& f2); 

bool operator< (Fraction const& f1, Fraction const& f2);
bool operator> (Fraction const& f1, Fraction const& f2);
bool operator<=(Fraction const& f1, Fraction const& f2);
bool operator>=(Fraction const& f1, Fraction const& f2);



// Bonus : aller plus loin (fonctions libres)
// + 
Fraction operator+(Fraction const& f, int const i);
Fraction operator+(int const i, Fraction const& f);
// -
Fraction operator-(Fraction const& f, int const i);
Fraction operator-(int const i, Fraction const& f);
// *
Fraction operator*(Fraction const& f, int const i);
Fraction operator*(int const i, Fraction const& f);
// division /
Fraction operator/(Fraction const& f, int const i);
Fraction operator/(int const i, Fraction const& f);