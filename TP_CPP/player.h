#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include "Card.h"
#include "PokemonCard.h"
#include "EnergyCard.h"
#include "TrainerCard.h"

class Player {
private:
    std::string playerName;
    std::vector<Card*> benchCards;
    std::vector<PokemonCard*> actionCards;

public:
    Player(const std::string& name);
    void addCardToBench(Card* card);
    void activatePokemon(int index);
    void attachEnergy(int benchIndex, int activeIndex);
    void useTrainer(int index);
    void attack(int activeIndex, int attackIndex, Player& opponent, int targetIndex);
    void displayBench() const;
    void displayActivePokemons() const;
};

#endif // PLAYER_H
