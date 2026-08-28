//headers
#include "../include/Character.hpp"

//std
#include <iostream>
#include <math.h>

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
int Character::GetNumberOfPotionsInInventorySlot(PotionType potiontype, PotionCostAndSize potionsize){
        int xinventory = static_cast<int>(potiontype);
        int yinventory = GetYCoordForInventory(potionsize);

        //returns either 0 which will make if statement false
        //or returns 1+ which will make if statement true
        //if statement is responsible for drinking potion
        return inventory[xinventory][yinventory];
}
int Character::GetNumberOfPotionsInInventorySlot(int xinventory, int yinventory){
        return inventory[xinventory][yinventory];
}
int Character::GetMoney(){
        return money;
}

//uses equation to get int based on potionsize:
// SMALL -> 0, MEDIUM -> 1, BIG -> 2
//   25  -> 0,   50   -> 1, 100 -> 2
int Character::GetYCoordForInventory(PotionCostAndSize potionsize){
    return static_cast<int>( std::lround( std::log2( static_cast<float>(potionsize)/25.0f )));
}

//Round actions functions
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
                characterPtrToDamage->TakeHealth(spelldamage*(damagemultiplier/100.0f));
                TakeMana(manacost);
                damagemultiplier = 100.0f;
                damagemultstate = false;
        }
        else{
                characterPtrToDamage->TakeHealth(spelldamage);
                TakeMana(manacost);
        }
}

//other
void Character::GiveMoney(int value){
        money += value;
}

void Character::DrinkPotion(PotionType potiontype, PotionCostAndSize potionsize){
        IsPotionPresent = false;
        int xinventory = static_cast<int>(potiontype);
        int yinventory = GetYCoordForInventory(potionsize);

        if(inventory[xinventory][yinventory] == 0){
                std::cout << "You dont have this potion" << '\n';
        }
        else{
                IsPotionPresent = true;
                inventory[xinventory][yinventory] -= 1;
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

void Character::BuyPotion(PotionType potiontype, PotionCostAndSize potionsize){
        int xinventory = static_cast<int>(potiontype);
        int yinventory = GetYCoordForInventory(potionsize);
        int potioncost = static_cast<int>(potionsize);

        if(potioncost > money){
                std::cout << "You dont have enough money for this potion!" << '\n';
        }
        else{
                money -= potioncost;
                inventory[xinventory][yinventory] += 1;
        }
}