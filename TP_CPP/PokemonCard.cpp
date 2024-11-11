#include "PokemonCard.h"
#include <iostream>
#include <tuple>

PokemonCard::PokemonCard(const std::string& name, const std::string& type, const std::string& family,
                         int level, int max_hp, int current_hp,
                         int energyCost1, int currentEnergy1, const std::string& description1, int damage1,
                         int energyCost2, int currentEnergy2, const std::string& description2, int damage2)
    : Card(name), pokemonType(type), familyName(family),
      evolutionLevel(level), maxHP(max_hp), hp(current_hp) {

    attacks.emplace_back(energyCost1, currentEnergy1, description1, damage1);
    attacks.emplace_back(energyCost2, currentEnergy2, description2, damage2);
}

void PokemonCard::displayInfo() const {
    std::cout << "Pokemon Card - Name: " << cardName << ", Type: " << pokemonType
              << ", Evolution Level: " << evolutionLevel << ", HP: " << hp << "/" << maxHP
              << std::endl;
    for (size_t i = 0; i < attacks.size(); ++i) {
        int energyCost = std::get<0>(attacks[i]);
        int currentEnergy = std::get<1>(attacks[i]);
        std::string description = std::get<2>(attacks[i]);
        int damage = std::get<3>(attacks[i]);

        std::cout << "  Attack #" << i + 1 << ":\n"
                  << "    Energy Cost: " << energyCost << "\n"
                  << "    Current Energy: " << currentEnergy << "\n"
                  << "    Description: " << description << "\n"
                  << "    Damage: " << damage << "\n";
    }
}

bool PokemonCard::attack(int attackIndex, PokemonCard* target) {
    int energyCost = std::get<0>(attacks[attackIndex]);
    int currentEnergy = std::get<1>(attacks[attackIndex]);
    std::string description = std::get<2>(attacks[attackIndex]);
    int damage = std::get<3>(attacks[attackIndex]);

    if (currentEnergy >= energyCost) {
        target->hp -= damage;
        return target->hp <= 0;
    }
    return false;
}

void PokemonCard::healToFull() {
    hp = maxHP;
}
