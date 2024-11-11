#ifndef TRAINER_CARD_H
#define TRAINER_CARD_H

#include "Card.h"
#include <string>
#include <vector>
#include "PokemonCard.h"

class TrainerCard : public Card {
private:
    std::string trainerEffect;

public:
    TrainerCard(const std::string& name, const std::string& effect);

    std::string getTrainerEffect() const;

    void applyEffect(std::vector<PokemonCard*>& activePokemons);
    void displayInfo() const override;
};

#endif // TRAINER_CARD_H
