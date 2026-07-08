#include <iostream>
#include <string>
#include <vector>
#include "../include/Character.h"
#include "../include/Print.h"

int main() {

    Axe character;
    character.PrintStats();
    character.DrinkPotion(PotionType::HPPOTION, PotionCostAndSize::BIG);
    character.BuyPotion(PotionType::MANAPOTION, PotionCostAndSize::SMALL);
    character.PrintInventory();
    character.DrinkPotion(PotionType::MANAPOTION, PotionCostAndSize::BIG);
    character.PrintInventory();
    character.DrinkPotion(PotionType::MANAPOTION, PotionCostAndSize::SMALL);
    character.PrintInventory();
}