#include "fonction.hpp"

int main() {

    std::vector<Card> cards = get_cards(100);

    std::unordered_map<Card, int> card_counts;
    for (const Card& card : cards) {
        card_counts[card]++;
    }

    std::cout << "Distribution des cartes:" << std::endl;
    for (const auto& [card, count] : card_counts) {
        std::cout << card_name(card) << " : " << count << " fois" << std::endl;
    }

    return 0;
}