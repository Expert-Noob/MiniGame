//headers
#include "../include/Character.hpp"
#include "../include/Print.hpp"
#include "../include/Functions.hpp"

//std
#include <iostream>
#include <string>
#include <memory>

int main(){

    std::cout << "-Game-" << '\n';
    std::cout << "Choose youre character" << '\n';
    printAllCharacters();
    std::cout << "Enter: ";
    
    std::unique_ptr<Character> character = InitializeCharacter();
    std::cout << '\n';

    GameLoop(character.get());

    std::cout << "You lost :(" << '\n';

    return 0;
}