//headers
#include "../include/Character.hpp"
#include "../include/Print.hpp"
#include "../include/Functions.hpp"

//std
#include <iostream>
#include <string>

int main(){

    std::cout << "-Game-" << '\n';
    std::cout << "Choose youre character" << '\n';
    printAllCharacters();
    std::cout << "Enter: ";
    Character* character = InitializeCharacter();
    std::cout << '\n';

    int Roundcounter = 1;
    while(character->GetHealth() != 0){
        BuyPotionFunc(character);
    
        Character* bot = InitializeBot();

        std::cout << "Round " << Roundcounter << "\n\n";

        while(bot->GetHealth() != 0 && character->GetHealth() != 0){
            std::cout << "Choose your move: attack, cast_spell, use_potion or skip" << '\n';
            CheckAndPerformMove(character, bot);
            PrintStats(character, bot);

            if(bot->GetHealth() == 0){
                std::cout << "You won\n" << '\n';
                character->GiveMoney(150);

                Roundcounter += 1;
            }
            else{
                std::cout << "Bot's move: " << '\n';
                BotMove(bot, character);
                PrintStats(character, bot);
            }
        }

        delete bot;
    }

    std::cout << "You lost :(" << '\n';

    delete character;

    return 0;
}