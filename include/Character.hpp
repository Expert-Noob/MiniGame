#pragma once
#include "PotionSize.hpp"

class Character{
private:
    int money = 100;
    bool IsPotionPresent = false;

    bool damagemultstate = false;
    float damagemultiplier = 100.0f;
    float health = 0.0f;
    float mana = 0.0f;
    
    //const values
    const int maxhealth = 0;
    const int maxmana = 0;
    const float damage = 0.0f;
    const float spelldamage = 0.0f;
    const int manacost = 0;
    
    int inventory[3][3] = {
        //             Small  Medium  Big
        //    HpPotion   ?      ?      ?
        //  ManaPotion   ?      ?      ?
        //DamagePotion   ?      ?      ?
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    };
public:

    Character(int maxhealth, int maxmana, float damage, float spelldamage, int manacost);

    //get functions
    int GetMaxHealth() const;
    int GetMaxMana() const;
    int GetHealth() const;
    int GetMana() const;
    int GetSpellManaCost() const;
    bool GetNumberOfPotionsInSlotForBot(PotionType potiontype, PotionCostAndSize potionsize);

    //Round action functions
    void TakeHealth(int damage);
    void TakeMana(int usedmana);
    void Attack(Character* characterPtrToDamage);
    void CastSpell(Character* characterPtrToDamage);
    
    //extra
    void GiveMoney();
    int GetMoney();
    void PrintStats(Character* botPtr);
    void DrinkPotion(PotionType potiontype, PotionCostAndSize potionsize);
    bool BoolReturnForPotionPresent();
    void BuyPotion(PotionType potiontype, PotionCostAndSize potionsize);
    void PrintInventory();
};