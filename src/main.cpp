#include <iostream>
#include <string>
#include "../include/Character.hpp"
#include "../include/Print.hpp"
#include "../include/Functions.hpp"

int main() {

    std::cout << "-Game-" << '\n';
    std::cout << "Choose youre character" << '\n';
    printAllCharacters();
    std::cout << "Enter: ";
    Character* character = InitializeCharacter();
    std::cout << '\n';

    int counter = 1;
    while(character->GetHealth() != 0){
        BuyPotionFunc(character);
    
        Character* bot = nullptr;
        bot = InitializeBot();

        std::cout << "Round " << counter << "\n" << '\n';
        while(true){
            std::cout << "Choose your move: attack, cast_spell, use_potion or skip" << '\n';
            CheckAndPerformMove(character, bot);
            character->PrintStatsBetter(bot);

            if(bot->GetHealth() == 0){
                std::cout << "You won\n" << '\n';
                character->GiveMoney();
                delete bot;
                counter += 1;
                break;
            }
            else{
                std::cout << "Bot's move: " << '\n';
                BotMove(bot, character);
                character->PrintStatsBetter(bot);
                if(character->GetHealth() == 0){
                    std::cout << "You lost :(" << '\n';
                    delete bot;
                    break;
                }
            }
        }
    }

    delete character;
}