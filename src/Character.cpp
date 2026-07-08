#include <iostream>
#include "../include/Character.h"

void Character::PrintStats(){
        std::cout << "Health: " << health << '\n';
        std::cout << "Mana: " << mana << '\n';
}

void Character::DrinkPotion(PotionType potiontype, PotionCostAndSize potionsize){
        int yinventory = 0;
        if(static_cast<int>(potionsize) == 25){
                yinventory = 0;
        }
        else if(static_cast<int>(potionsize) == 50){
                yinventory = 1;
        }
        else{
                yinventory = 2;
        }

        if(inventory[static_cast<int>(potiontype)][yinventory] == 0){
                std::cout << "You dont have this potion" << '\n';
        }
        else{
                inventory[static_cast<int>(potiontype)][yinventory] -= 1;
                switch(potiontype){
                        case PotionType::HPPOTION:
                                health += static_cast<int>(potionsize);
                                if(health > GetMaxHealth()){
                                        health = GetMaxHealth();
                                }
                                std::cout << "+" << static_cast<int>(potionsize) << " health" << '\n';
                                break;
                        case PotionType::MANAPOTION:
                                mana += static_cast<int>(potionsize);
                                if(mana > GetMaxMana()){
                                        mana = GetMaxMana();
                                }
                                std::cout << "+" << static_cast<int>(potionsize) << " mana" << '\n';
                                break;
                        case PotionType::DAMAGEPOTION:
                                if(damagemultstate){
                                        std::cout << "You cant use another damage potion until you've attacked" << '\n';
                                }
                                else{
                                        damagemultiplier += static_cast<int>(potionsize);
                                        std::cout << "+" << static_cast<int>(potionsize) << " damage multiplier" << '\n';
                                        damagemultstate = true;   
                                }
                                break;
                }
        }
}

void Character::BuyPotion(PotionType potiontype, PotionCostAndSize potioncost){
        int yinventory = 0;
        if(static_cast<int>(potioncost) == 25){
                yinventory = 0;
        }
        else if(static_cast<int>(potioncost) == 50){
                yinventory = 1;
        }
        else{
                yinventory = 2;
        }
        if(static_cast<int>(potioncost) > money){
                std::cout << "You dont have enough money for this potion" << '\n';
        }
        else{
                money -= static_cast<int>(potioncost);
                inventory[static_cast<int>(potiontype)][yinventory] += 1;
        }
}

void Character::PrintInventory(){
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
                        std::cout << inventory[i][i2] << "      ";
                }
                std::cout << '\n';
        }
        std::cout << '\n';
}

Axe::Axe(){
        health = maxhealth;
        mana = maxmana;
}

int Axe::GetMaxHealth() const{
        return maxhealth;
}

int Axe::GetMaxMana() const{
        return maxmana;
}

Lina::Lina(){
        health = maxhealth;
        mana = maxmana;
}

int Lina::GetMaxHealth() const{
        return maxhealth;
}

int Lina::GetMaxMana() const{
        return maxmana;
}

Rubick::Rubick(){
        health = maxhealth;
        mana = maxmana;
}

int Rubick::GetMaxHealth() const{
        return maxhealth;
}

int Rubick::GetMaxMana() const{
        return maxmana;
}

Ursa::Ursa(){
        health = maxhealth;
        mana = maxmana;
}

int Ursa::GetMaxHealth() const{
        return maxhealth;
}

int Ursa::GetMaxMana() const{
        return maxmana;
}