//headers
#include "../include/Character.hpp"

//std
#include <iostream>

void printAllCharacters(){
    std::cout << "Axe                 Lina                 Rubick               Ursa" << '\n';
    std::cout << "Health:200          Health:100           Health:150           Health:175" << '\n';
    std::cout << "Mana:100            Mana:150             Mana:200             Mana:125" << '\n';
    std::cout << "Damage:20           Damage:40            Damage:10            Damage:30" << '\n';
    std::cout << "SpellDamage:30      SpellDamage:80       SpellDamage:50       SpellDamage:40" << '\n';
    std::cout << "ManaCost:50         ManaCost:100         ManaCost:60          ManaCost:35" << '\n';
}

void printShop(){
    std::cout << "Name                      Cost           Function" << '\n';
    std::cout << "Small_Hp_Potion           25             +25 hp" << '\n';
    std::cout << "Medium_Hp_Potion          50             +50 hp" << '\n';
    std::cout << "Big_Hp_Potion             100            +100 hp" << '\n';
    std::cout << "Small_Mana_Potion         25             +25 mana" << '\n';
    std::cout << "Medium_Mana_Potion        50             +50 mana" << '\n';
    std::cout << "Big_Mana_Potion           100            +100 mana" << '\n';
    std::cout << "Small_Damage_Potion       25             x1.25 damage" << '\n';
    std::cout << "Medium_Damage_Potion      50             x1.5 damage" << '\n';
    std::cout << "Big_Damage_Potion         100            x2 damage\n" << '\n';
}

void PrintStats(Character* characterPtr, Character* botPtr){
        std::cout << "Character stats:   Bot stats:" << '\n';

        if(characterPtr->GetHealth() >= 100){
                std::cout << "Health:" << characterPtr->GetHealth() << "         Health:" << botPtr->GetHealth() << '\n';
        }
        else if(characterPtr->GetHealth() >= 10){
                std::cout << "Health:" << characterPtr->GetHealth() << "          Health:" << botPtr->GetHealth() << '\n';
        }
        else{
                std::cout << "Health:" << characterPtr->GetHealth() << "           Health:" << botPtr->GetHealth() << '\n';
        }

        if(characterPtr->GetMana() >= 100){
                std::cout << "Mana:" << characterPtr->GetMana() << "           Mana:" << botPtr->GetMana() << '\n';
        }
        else if(characterPtr->GetMana() >= 10){
                std::cout << "Mana:" << characterPtr->GetMana() << "            Mana:" << botPtr->GetMana() << '\n';
        }
        else{
                std::cout << "Mana:" << characterPtr->GetMana() << "             Mana:" << botPtr->GetMana() << '\n';
        }

        std::cout << '\n';
}

void PrintInventory(Character* characterPtr){
        std::cout << "Inventory:" << '\n';
        std::cout << "              Small  Medium  Big" << '\n';
        
        for(int i = 0; i < 3; i++){
                switch (i) {
                        case 0:
                                std::cout << "    Hp_Potion   ";
                                break;
                        case 1:
                                std::cout << "  Mana_Potion   ";
                                break;
                        case 2:
                                std::cout << "Damage_Potion   ";
                                break;
                }
                for(int i2 = 0; i2 < 3; i2++){
                        std::cout << characterPtr->GetNumberOfPotionsInInventorySlot(i, i2) << "      ";
                }
                std::cout << '\n';
        }
        std::cout << '\n';
}