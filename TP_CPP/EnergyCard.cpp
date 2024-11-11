#include "EnergyCard.h"
#include <iostream>

EnergyCard::EnergyCard(const std::string& type) : Card("Energy"), energyType(type) {}

std::string EnergyCard::getEnergyType() const {
    return energyType;
}

void EnergyCard::displayInfo() const {
    std::cout << "Energy Card - Type: " << energyType << std::endl;
}
