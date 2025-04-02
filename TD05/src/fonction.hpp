#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <functional>
#include <random>
#include <algorithm>
#include <iterator>
#include <iomanip>


// Exercice 1 (fonction de hachage)
size_t folding_string_hash_sum(std::string const& s, size_t max);
size_t folding_string_ordered_hash(std::string const& s, size_t max);
size_t polynomial_rolling_hash(const std::string& s, size_t p, size_t m);


// Exercice 2 (Analyse du nombre d'insectes)
enum class Insect {
    ClassicBee,
    Ladybug,
    Butterfly,
    Dragonfly,
    Ant,
    Grasshopper,
    Beetle,
    Wasp,
    Caterpillar,
    Spider,
    GuimielBee
};
const std::vector<Insect> insect_values {
    Insect::ClassicBee,
    Insect::Ladybug,
    Insect::Butterfly,
    Insect::Dragonfly,
    Insect::Ant,
    Insect::Grasshopper,
    Insect::Beetle,
    Insect::Wasp,
    Insect::Caterpillar,
    Insect::Spider,
    Insect::GuimielBee
}; 
std::vector<int> const expected_insect_counts {
    75, // ClassicBee
    50, // Ladybug
    100, // Butterfly
    20, // Dragonfly
    400, // Ant
    150, // Grasshopper
    60, // Beetle
    10, // Wasp
    40, // Caterpillar
    90, // Spider 
    5, // GuimielBee
};
std::unordered_map<Insect, std::string> const insect_to_string = {
    {Insect::ClassicBee, "ClassicBee"},
    {Insect::Ladybug, "Ladybug"},
    {Insect::Butterfly, "Butterfly"},
    {Insect::Dragonfly, "Dragonfly"},
    {Insect::Ant, "Ant"},
    {Insect::Grasshopper, "Grasshopper"},
    {Insect::Beetle, "Beetle"},
    {Insect::Wasp, "Wasp"},
    {Insect::Caterpillar, "Caterpillar"},
    {Insect::Spider, "Spider"},
    {Insect::GuimielBee, "GuimielBee"}
};
std::vector<std::pair<Insect, int>> get_insect_observations(size_t const number_of_observations, std::vector<float> const& insect_probabilities, unsigned int const seed = std::random_device{}());
std::vector<float> probabilities_from_count(std::vector<int> const& counts);
void display_proba_diff(std::vector<float> const& observed_proba, std::vector<float> const& expected_proba);
std::ostream& operator<<(std::ostream& os, std::vector<int> const& vec);
std::ostream& operator<<(std::ostream& os, std::unordered_map<Insect, int> map);
std::ostream& operator<<(std::ostream& os, std::vector<float> const& vec);











// Exercice 3 (hash sur une structure)
enum class CardKind {
    Heart,
    Diamond,
    Club,
    Spade,
};

enum class CardValue {
    Two,
    Three,
    Four,
    Five,
    Six,
    Seven,
    Eight,
    Nine,
    Ten,
    Jack,
    Queen,
    King,
    Ace,
};

struct Card {
    CardKind kind;
    CardValue value;
};


std::vector<Card> get_cards(size_t const size);