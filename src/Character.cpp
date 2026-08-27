#include <iostream>
#include "../include/Character.hpp"

Character::Character(int maxhealth, int maxmana, float damage, float spelldamage, int manacost) :
        //member initializer list
        maxhealth(maxhealth),
        maxmana(maxmana),
        damage(damage),
        spelldamage(spelldamage),
        manacost(manacost)

        /*Main body of constructor*/{
        health = static_cast<float>(maxhealth);
        mana = static_cast<float>(maxmana);
}

//get functions
int Character::GetMaxHealth() const{
        return maxhealth;
}
int Character::GetMaxMana() const{
        return maxmana;
}
int Character::GetHealth() const{
        return health;
}
int Character::GetMana() const{
        return mana;
}
int Character::GetSpellManaCost() const{
        return manacost;
}
bool Character::GetNumberOfPotionsInSlotForBot(PotionType potiontype, PotionCostAndSize potionsize){
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

        //returns either 0 which will make if statement false
        //or returns 1+ which will make if statement true
        //if statement is responsible for bot drinking potions
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
                characterPtrToDamage->TakeHealth(damage*(damagemultiplier/100.0f));
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
        money += 150;
}

int Character::GetMoney(){
        return money;
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