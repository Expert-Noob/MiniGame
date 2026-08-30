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
int Character::GetMoney() const{
        return money;
}
bool Character::GetIsPotionDrank() const{
        return IsPotionDrank;
}
int Character::GetNumberOfPotionsInInventorySlot(PotionType potiontype, PotionCostAndSize potionsize){
        int xinventory = static_cast<int>(potiontype);
        int yinventory = GetYCordForInventory(potionsize);
        return inventory[xinventory][yinventory];
}
int Character::GetNumberOfPotionsInInventorySlot(int xinventory, int yinventory){
        return inventory[xinventory][yinventory];
}

//uses equation to get int based on potionsize:
// SMALL -> 0, MEDIUM -> 1, BIG -> 2
//   25  -> 0,   50   -> 1, 100 -> 2
int Character::GetYCordForInventory(PotionCostAndSize potionsize){
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
        if(damagemultiplier != 1.0f){
                characterPtrToDamage->TakeHealth(damage*damagemultiplier);
                damagemultiplier = 1.0f;
        }
        else{
                characterPtrToDamage->TakeHealth(damage);
        }
}

void Character::CastSpell(Character* characterPtrToDamage){
        if(damagemultiplier != 1.0f){
                characterPtrToDamage->TakeHealth(spelldamage*damagemultiplier);
                TakeMana(manacost);
                damagemultiplier = 1.0f;
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
        IsPotionDrank = false;
        int xinventory = static_cast<int>(potiontype);
        int yinventory = GetYCordForInventory(potionsize);
        int potionsize_Int = static_cast<int>(potionsize);

        if(inventory[xinventory][yinventory] == 0){
                std::cout << "You dont have this potion" << '\n';
        }
        else{
                IsPotionDrank = true;
                inventory[xinventory][yinventory] -= 1;
                switch(potiontype){
                        case PotionType::HPPOTION:
                                health += potionsize_Int;

                                if(health > GetMaxHealth()){
                                        health = GetMaxHealth();
                                }

                                std::cout << "+" << potionsize_Int << " health\n" << '\n';
                                break;
                        case PotionType::MANAPOTION:
                                mana += potionsize_Int;

                                if(mana > GetMaxMana()){
                                        mana = GetMaxMana();
                                }

                                std::cout << "+" << potionsize_Int << " mana\n" << '\n';
                                break;
                        case PotionType::DAMAGEPOTION:
                                if(damagemultiplier != 1.0f){
                                        std::cout << "You cant use another damage potion until you've attacked" << '\n';
                                }
                                else{
                                        damagemultiplier += ( static_cast<float>(potionsize)/100.0f );
                                        std::cout << "+" << ( static_cast<float>(potionsize)/100.0f ) << " damage multiplier\n" << '\n';
                                }
                                break;
                }
        }
}

void Character::BuyPotion(PotionType potiontype, PotionCostAndSize potionsize){
        int xinventory = static_cast<int>(potiontype);
        int yinventory = GetYCordForInventory(potionsize);
        int potioncost = static_cast<int>(potionsize);

        if(potioncost > money){
                std::cout << "You dont have enough money for this potion!" << '\n';
        }
        else{
                money -= potioncost;
                inventory[xinventory][yinventory] += 1;
        }
}