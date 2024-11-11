#include "Player.h"
#include <iostream>

Player::Player(const std::string& name) : playerName(name) {}

void Player::addCardToBench(Card* card) {
    benchCards.push_back(card);
}

void Player::activatePokemon(int index) {
    PokemonCard* pokemon = dynamic_cast<PokemonCard*>(benchCards[index]);
    if (pokemon) {
        actionCards.push_back(pokemon);
        benchCards.erase(benchCards.begin() + index);
        std::cout << playerName << " activated Pokemon: " << pokemon->getCardName() << std::endl;
    }
}

void Player::attachEnergy(int benchIndex, int activeIndex) {
    EnergyCard* energy = dynamic_cast<EnergyCard*>(benchCards[benchIndex]);
    PokemonCard* pokemon = actionCards[activeIndex];
    if (energy && pokemon) {
        benchCards.erase(benchCards.begin() + benchIndex);
    }
}

void Player::useTrainer(int index) {
    TrainerCard* trainer = dynamic_cast<TrainerCard*>(benchCards[index]);
    if (trainer) {
        trainer->applyEffect(actionCards);
        benchCards.erase(benchCards.begin() + index);
        std::cout << playerName << " used Trainer Card with effect: " << trainer->getTrainerEffect() << std::endl;
    }
}

void Player::attack(int activeIndex, int attackIndex, Player& opponent, int targetIndex) {
    PokemonCard* attacker = actionCards[activeIndex];
    PokemonCard* target = opponent.actionCards[targetIndex];
    bool targetKO = attacker->attack(attackIndex, target);

    if (targetKO) {
        opponent.actionCards.erase(opponent.actionCards.begin() + targetIndex);
        std::cout << opponent.playerName << "Pokemon " << target->getCardName() << "  knocked out!" << std::endl;
    }
}

void Player::displayBench() const {
    std::cout << "Bench for " << playerName << ":" << std::endl;
    for (const auto& card : benchCards) {
        card->displayInfo();
    }
}

void Player::displayActivePokemons() const {
    std::cout << "Active Pokemon for " << playerName << ":" << std::endl;
    for (const auto& pokemon : actionCards) {
        pokemon->displayInfo();
    }
}
