#include <iostream>
#include "../include/Character.h"

Character::Character(int maxhealth, int maxmana, float damage, float spelldamage, int manacost){
        this->maxhealth = maxhealth;
        this->maxmana = maxmana;
        this->damage = damage;
        this->spelldamage = spelldamage;
        this->manacost = manacost;
        health = static_cast<float>(maxhealth);
        mana = static_cast<float>(maxmana);
}

int Character::GetMaxHealth() const{
        return maxhealth;
}
int Character::GetMaxMana() const{
        return maxmana;
}
int Character::GetHealth(){
        return health;
}
int Character::GetMana(){
        return mana;
}
int Character::GetSpellManaCost(){
        return manacost;
}

bool Character::GetInvenotrySlotValueForBot(PotionType potiontype, PotionCostAndSize potionsize){
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
        return inventory[static_cast<int>(potiontype)][yinventory];
}

void Character::TakeHealth(int damage){
        health -= damage;
        if(health < 0){
                health = 0;
        }
}

void Character::TakeMana(int usedmana){
        mana -= usedmana;
        if(mana < 0){
                mana = 0;
        }
}

void Character::Attack(Character* characterPtrToDamage){
        if(damagemultstate){
                float damageSave = damage*(damagemultiplier/100.0f);
                characterPtrToDamage->TakeHealth(damageSave);
                damagemultiplier = 100.0f;
                damagemultstate = false;
        }
        else{
                characterPtrToDamage->TakeHealth(damage);
        }
}

void Character::CastSpell(Character* characterPtrToDamage){
        if(damagemultstate){
                float damageSave = spelldamage*(damagemultiplier/100.0f);
                characterPtrToDamage->TakeHealth(damageSave);
                TakeMana(manacost);
                damagemultiplier = 100.0f;
                damagemultstate = false;
        }
        else{
                characterPtrToDamage->TakeHealth(spelldamage);
                TakeMana(manacost);
        }
}

void Character::GiveMoney(){
        money += 100;
}

int Character::GetMoney(){
        return money;
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
                                std::cout << "+" << static_cast<int>(potionsize) << " health\n" << '\n';
                                break;
                        case PotionType::MANAPOTION:
                                mana += static_cast<int>(potionsize);
                                if(mana > GetMaxMana()){
                                        mana = GetMaxMana();
                                }
                                std::cout << "+" << static_cast<int>(potionsize) << " mana\n" << '\n';
                                break;
                        case PotionType::DAMAGEPOTION:
                                if(damagemultstate){
                                        std::cout << "You cant use another damage potion until you've attacked" << '\n';
                                        IsPotionPresent = false;
                                }
                                else{
                                        damagemultiplier += static_cast<float>(potionsize);
                                        std::cout << "+" << (static_cast<float>(potionsize)/100.0f) << " damage multiplier\n" << '\n';
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

Axe::Axe() : Character(200, 100, 20.0f, 30.0f, 50){
}
Lina::Lina() : Character(100, 150, 40.0f, 80.0f, 150) {
}

Rubick::Rubick() : Character(150, 200, 10.0f, 50.0f, 60) {
}

Ursa::Ursa() : Character(175, 125, 30.0f, 40.0f, 35) {
}