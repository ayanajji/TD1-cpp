#include "Card.h"
#include "PokemonCard.h"
#include "EnergyCard.h"
#include "TrainerCard.h"
#include "Player.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
    Player player1("Hadi");

    player1.addCardToBench(new EnergyCard("Electric"));
    player1.addCardToBench(new EnergyCard("Electric"));
    player1.addCardToBench(new TrainerCard("Ash", "heal all your action pokemon"));
    player1.addCardToBench(new PokemonCard("Pikachu", "Electric", "Pikachu", 2, 100, 2, 
                                           "thunder bolt", 20, 3, "thunder storm", 30));

    player1.activatePokemon(3);  
    player1.attachEnergy(0, 0);  
    player1.attachEnergy(0, 0);  

    cout << endl;
    player1.displayBench();
    cout << endl;
    player1.displayActivePokemons();

    Player player2("Germain");

    player2.addCardToBench(new EnergyCard("Grass"));
    player2.addCardToBench(new TrainerCard("Brock", "heal all your action pokemon"));
    player2.addCardToBench(new PokemonCard("Bulbasaur", "Grass", "Bulbasaur", 1, 100, 2, 
                                           "Leech Seed", 15, 3, "Vine Whip", 25));

    player2.activatePokemon(2);  
    player2.attachEnergy(0, 0);  

    cout << endl;
    player2.displayBench();
    cout << endl;
    player2.displayActivePokemons();

    player1.attack(0, 0, player2, 0);  

    cout << endl;
    player2.displayActivePokemons();
    player2.useTrainer(0);  

    cout << endl;
    player2.displayActivePokemons();

    return 0;
}
