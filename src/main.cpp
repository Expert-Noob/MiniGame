#include <iostream>
#include <string>
#include <vector>
#include "../include/Character.h"
#include "../include/Print.h"

int main() {

    Axe character;
    character.PrintStats();
    character.DrinkPotion(PotionSize::SMALL);

}