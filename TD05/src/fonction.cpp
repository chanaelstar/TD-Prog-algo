#include "fonction.hpp"


// Exercice 1 (fonction de hachage)
size_t folding_string_hash_sum(std::string const& s, size_t max){
    size_t hash = 0;
    for (char c : s) {
        hash += static_cast<size_t>(c);
        hash %= max;
    }
    return hash % max;
}

size_t folding_string_ordered_hash(std::string const& s, size_t max){
    size_t hash = 0;
    for (size_t i = 0; i < s.size(); ++i) {
        hash += static_cast<size_t>(s[i]) * (i + 1);
        hash %= max;
    }
    return hash % max;
}

size_t polynomial_rolling_hash(const std::string& s, size_t p, size_t m){
    size_t hash = 0;
    size_t p_pow = 1;
    for (size_t i = 0; i < s.size(); ++i) {
        hash = (hash + (s[i] * p_pow) % m) % m;
        p_pow = (p_pow * p) % m;
    }
    return hash;
}



// Exercice 2 (Analyse du nombre d'insectes)
std::vector<std::pair<Insect, int>> get_insect_observations(
    size_t const number_of_observations,
    std::vector<float> const& insect_probabilities,
    unsigned int const seed)
    {
    // Create a random engine with a given seed
    std::default_random_engine random_engine{seed};

    auto rand_insect_index { std::bind(std::discrete_distribution<size_t>{insect_probabilities.begin(), insect_probabilities.end()}, random_engine) };
    
    std::vector<std::pair<Insect, int>> observations {};
    observations.reserve(number_of_observations);

    for(size_t i {0}; i < number_of_observations; ++i) {
        size_t const random_insect_index { rand_insect_index() };
        Insect const random_insect { insect_values[random_insect_index] };
        
        // If we have already seen the same insect, increment the count on the last observation
        if(!observations.empty() && observations.back().first == random_insect) {
            observations.back().second++;
            i -= 1;
        } else {
            observations.push_back({random_insect, 1});
        }
    }

    return observations;
}


std::vector<float> probabilities_from_count(std::vector<int> const& counts){
    std::vector<float> probabilities(counts.size(), 0.0f);
    int total_count = 0;
    for (int count : counts) {
        total_count += count;
    }
    for (size_t i = 0; i < counts.size(); ++i) {
        probabilities[i] = float(counts[i]) / total_count;
    }
    return probabilities;
}

void display_proba_diff(std::vector<float> const& observed_proba, std::vector<float> const& expected_proba){
    std::cout << "Probabilities of observed insects vs expected probabilities : " <<  std::endl;
    std::cout << std::endl;
    std::cout << std::fixed << std::setprecision(3);
    for(Insect i : insect_values){
        std::cout << insect_to_string.at(i) << ": " << observed_proba[static_cast<size_t>(i)] << " vs " << expected_proba[static_cast<size_t>(i)] << " ";
        if (observed_proba[static_cast<size_t>(i)]  > expected_proba[static_cast<size_t>(i)] - 0.01 || observed_proba[static_cast<size_t>(i)] < expected_proba[static_cast<size_t>(i)] + 0.01) {
            std::cout << "OK" << std::endl;
        } else {
            std::cout << "BAD" << std::endl;
        }
    }
}


std::ostream& operator<<(std::ostream& os, std::vector<float> const& vec) {
    for (size_t i = 0; i < vec.size(); ++i) {
        os << vec[i];
        if (i != vec.size() - 1) {
            os << ", ";
        }
    }
    return os;
}
std::ostream& operator<<(std::ostream& os, std::vector<int> const& vec) {
    for (size_t i = 0; i < vec.size(); ++i) {
        os << vec[i];
        if (i != vec.size() - 1) {
            os << ", ";
        }
    }
    return os;
}
std::ostream& operator<<(std::ostream& os, std::unordered_map<Insect, int> map) {
    for (std::pair<Insect, int> pair : map) {
        os << insect_to_string.at(pair.first) << ": " << pair.second << std::endl;
    }
    return os;
}




// Exercice 3 (hash sur une structure)
std::vector<Card> get_cards(size_t const size) {
    std::vector<Card> cards {};
    cards.reserve(size);
    for (size_t i {0}; i < size; ++i) {
        cards.push_back({static_cast<CardKind>(rand() % 4), static_cast<CardValue>(rand() % 13)});
    }
    return cards;
}