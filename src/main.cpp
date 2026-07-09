#include <iostream>
#include <string>
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

    int counter = 1;
    while(true){
        if(character->GetHealth() == 0){
            break;
        }
        BuyPotionFunc(character);
        std::cout << '\n';
    
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
                    break;
                }
            }
        }
    }

    delete character;
}