#include <iostream>
#include "../include/Character.h"

void Character::PrintStats(){
        std::cout << "Health: " << health << '\n';
        std::cout << "Mana: " << mana << '\n';
}

void Character::DrinkPotion(PotionSize potionsize){
        std::cout << "True" << '\n';
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