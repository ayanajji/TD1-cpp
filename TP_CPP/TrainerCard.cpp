#include "TrainerCard.h"
#include <iostream>

TrainerCard::TrainerCard(const std::string& name, const std::string& effect)
    : Card(name), trainerEffect(effect) {}

std::string TrainerCard::getTrainerEffect() const {
    return trainerEffect;
}

void TrainerCard::applyEffect(std::vector<PokemonCard*>& activePokemons) {
    for (auto& pokemon : activePokemons) {
        pokemon->healToFull();
    }
}

void TrainerCard::displayInfo() const {
    std::cout << "Trainer Card - Name: " << cardName << ", Effect: " << trainerEffect << std::endl;
}
