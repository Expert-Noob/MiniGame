#include <iostream>
#include "../include/Character.h"

void Character::PrintStats(){
        std::cout << "Health: " << health << '\n';
        std::cout << "Mana: " << mana << '\n';
}

void Character::DrinkPotion(PotionType potiontype, PotionCostAndSize potionsize){
        int xinventory = 0;
        if(static_cast<int>(potionsize) == 25){
                xinventory = 0;
        }
        else if(static_cast<int>(potionsize) == 50){
                xinventory = 1;
        }
        else{
                xinventory = 2;
        }

        if(inventory[xinventory][static_cast<int>(potiontype)] = 0){
                std::cout << "You dont have this potion" << '\n';
        }
        else{
                switch(potiontype){
                        case PotionType::HPPOTION:
                                health += static_cast<int>(potionsize);
                                std::cout << "+" << static_cast<int>(potionsize) << " health" << '\n';
                                break;
                        case PotionType::MANAPOTION:
                                mana += static_cast<int>(potionsize);
                                std::cout << "+" << static_cast<int>(potionsize) << " mana" << '\n';
                                break;
                        case PotionType::DAMAGEPOTION:
                                damagemultiplier += static_cast<int>(potionsize);
                                std::cout << "+" << static_cast<int>(potionsize) << " damage multiplier" << '\n';
                                damagemultstate = true;
                                break;
                }
        }
}

Axe::Axe(){
        health = maxhealth;
        mana = maxmana;
}

Lina::Lina(){
        health = maxhealth;
        mana = maxmana;
}

Rubick::Rubick(){
        health = maxhealth;
        mana = maxmana;
}

Ursa::Ursa(){
        health = maxhealth;
        mana = maxmana;
}