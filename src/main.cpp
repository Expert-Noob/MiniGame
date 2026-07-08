#include <iostream>
#include <string>
#include <vector>
#include "../include/Character.h"
#include "../include/Print.h"
#include "../include/Functions.h"

int main() {

    Character* character = nullptr;

    std::cout << "-Game-" << '\n';
    std::cout << "Choose youre character" << '\n';
    printAllCharacters();
    std::cout << "Enter: ";
    character = InitializeCharacter();
    std::cout << '\n';

    character->PrintStats();
    std::cout << '\n';

    BuyPotionFunc(character);

    delete character;
}