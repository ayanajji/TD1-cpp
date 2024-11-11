#ifndef POKEMON_CARD_H
#define POKEMON_CARD_H

#include "Card.h"
#include <string>
#include <vector>
#include <tuple>

class PokemonCard : public Card {
private:
    std::string pokemonType;
    std::string familyName;
    int evolutionLevel;
    int maxHP;
    int hp;
    std::vector<std::tuple<int, int, std::string, int>> attacks;

public:
    PokemonCard(const std::string& name, const std::string& type, const std::string& family,
                int level, int max_hp, int current_hp,
                int energyCost1, int currentEnergy1, const std::string& description1, int damage1,
                int energyCost2, int currentEnergy2, const std::string& description2, int damage2);

    void displayInfo() const override;
    bool attack(int attackIndex, PokemonCard* target);
    void healToFull();
};

#endif // POKEMON_CARD_H
