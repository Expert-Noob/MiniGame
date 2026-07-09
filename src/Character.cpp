#include <iostream>
#include "../include/Character.h"

void Character::GiveMoney(){
        money += 100;
}

void Character::PrintStats(){
        std::cout << "Stats:" << '\n';
        std::cout << "Health: " << health << '\n';
        std::cout << "Mana: " << mana << '\n';
        std::cout << '\n';
}

void Character::PrintStatsBetter(Character* botPtr){
        std::cout << "Character stats:   Bot stats:" << '\n';

        if(GetHealth() >= 100){
                std::cout << "Health:" << health << "         Health:" << botPtr->GetHealth() << '\n';
        }
        else if(GetHealth() >= 10){
                std::cout << "Health:" << health << "          Health:" << botPtr->GetHealth() << '\n';
        }
        else{
                std::cout << "Health:" << health << "           Health:" << botPtr->GetHealth() << '\n';
        }

        if(GetMana() >= 100){
                std::cout << "Mana:" << mana << "           Mana:" << botPtr->GetMana() << '\n';
        }
        else if(GetMana() >= 10){
                std::cout << "Mana:" << mana << "            Mana:" << botPtr->GetMana() << '\n';
        }
        else{
                std::cout << "Mana:" << mana << "             Mana:" << botPtr->GetMana() << '\n';
        }

        std::cout << '\n';
}

void Character::DrinkPotion(PotionType potiontype, PotionCostAndSize potionsize){
        IsPotionPresent = false;
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
                IsPotionPresent = true;
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
                                        damagemultiplier += static_cast<float>(potionsize);
                                        std::cout << "+" << static_cast<int>(potionsize) << " damage multiplier" << '\n';
                                        damagemultstate = true;   
                                }
                                break;
                }
        }
}

bool Character::BoolReturnForPotionPresent(){
        return IsPotionPresent;
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
                std::cout << "You dont have enough money for this potion!" << '\n';
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

//Subclass section

//Axe

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

int Axe::GetHealth(){
        return health;
}

int Axe::GetMana(){
        return mana;
}

int Axe::SpellManaCost(){
        return manacost;
}

void Axe::TakeHealth(int damage){
        health -= damage;
        if(health < 0){
                health = 0;
        }
}

void Axe::TakeMana(int usedmana){
        mana -= usedmana;
        if(mana < 0){
                mana = 0;
        }
}

void Axe::Attack(Character* characterPtrToDamage){
        characterPtrToDamage->TakeHealth(damage);
}

void Axe::CastSpell(Character* characterPtrToDamage){
        characterPtrToDamage->TakeHealth(spelldamage);
        TakeMana(manacost);
}

//Lina

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

int Lina::GetHealth(){
        return health;
}

int Lina::GetMana(){
        return mana;
}

int Lina::SpellManaCost(){
        return manacost;
}

void Lina::TakeHealth(int damage){
        health -= damage;
        if(health < 0){
                health = 0;
        }
}

void Lina::TakeMana(int usedmana){
        mana -= usedmana;
        if(mana < 0){
                mana = 0;
        }
}

void Lina::Attack(Character* characterPtrToDamage){
        characterPtrToDamage->TakeHealth(damage);
}

void Lina::CastSpell(Character* characterPtrToDamage){
        characterPtrToDamage->TakeHealth(spelldamage);
        TakeMana(manacost);
}

//Rubick

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

int Rubick::GetHealth(){
        return health;
}

int Rubick::GetMana(){
        return mana;
}

int Rubick::SpellManaCost(){
        return manacost;
}

void Rubick::TakeHealth(int damage){
        health -= damage;
        if(health < 0){
                health = 0;
        }
}

void Rubick::TakeMana(int usedmana){
        mana -= usedmana;
        if(mana < 0){
                mana = 0;
        }
}

void Rubick::Attack(Character* characterPtrToDamage){
        characterPtrToDamage->TakeHealth(damage);
}

void Rubick::CastSpell(Character* characterPtrToDamage){
        characterPtrToDamage->TakeHealth(spelldamage);
        TakeMana(manacost);
}

//Ursa

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

int Ursa::GetHealth(){
        return health;
}

int Ursa::GetMana(){
        return mana;
}

int Ursa::SpellManaCost(){
        return manacost;
}

void Ursa::TakeHealth(int damage){
        health -= damage;
        if(health < 0){
                health = 0;
        }
}

void Ursa::TakeMana(int usedmana){
        mana -= usedmana;
        if(mana < 0){
                mana = 0;
        }
}

void Ursa::Attack(Character* characterPtrToDamage){
        characterPtrToDamage->TakeHealth(damage);
}

void Ursa::CastSpell(Character* characterPtrToDamage){
        characterPtrToDamage->TakeHealth(spelldamage);
        TakeMana(manacost);
}