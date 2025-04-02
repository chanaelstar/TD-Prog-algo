#include "fonction.hpp"

int main() {

    std::cout << std::endl;

    std::cout << "Insect observations:" << std::endl;
    std::vector<float> proba_expected = probabilities_from_count(expected_insect_counts);
    std::vector<std::pair<Insect, int>> observations = get_insect_observations(1000, proba_expected);
    std::cout << std::endl;

    std::unordered_map<Insect, int> insect_count_map;
    for(Insect i : insect_values){
        insect_count_map.insert({i, 0});
    }
    for(std::pair<Insect, int> const& observation : observations) {
        insect_count_map.at(observation.first) += observation.second;
    }
    std::cout << insect_count_map << std::endl;


    std::vector<int> insect_counts;
    for(Insect i : insect_values){
        insect_counts.push_back(insect_count_map.at(i));
    }

    std::vector<float> proba_observe = probabilities_from_count(insect_counts);
    std::cout << "Insect probabilities: " << proba_observe << std::endl;
    std::cout << std::endl;

    display_proba_diff(proba_observe, proba_expected);

    return 0;
}