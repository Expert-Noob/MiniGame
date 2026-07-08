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

    character->PrintStats();
    std::cout << '\n';

    while(true){
        if(character->GetHealth() == 0){
            break;
        }
        BuyPotionFunc(character);
        std::cout << '\n';
    
        Character* bot = nullptr;
        bot = InitializeBot();
    
        bot->PrintStats();
        std::cout << '\n';

        std::cout << "Round 1\n" << '\n';
        while(true){
            std::cout << "Choose your move: attack, cast_spell, use_potion or skip" << '\n';
            CheckAndPerformMove(character, bot);
            std::cout << "Character stats:" << '\n';    
            character->PrintStats();
            std::cout << "Bot stats:" << '\n';
            bot->PrintStats();
            if(bot->GetHealth() == 0){
                std::cout << "You won\n" << '\n';
                delete bot;
                break;
            }
            else{
                std::cout << "Bot's move" << '\n';
                BotMove(bot, character);
                std::cout << "Character stats:" << '\n';
                character->PrintStats();
                std::cout << "Bot stats:" << '\n';
                bot->PrintStats();
                if(character->GetHealth() == 0){
                    std::cout << "You lost" << '\n';
                    break;
                }
            }
        }
    }

    delete character;
}