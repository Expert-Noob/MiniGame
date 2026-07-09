#pragma once
#include "PotionSize.h"

class Character{
private:
    int money = 100;
    bool IsPotionPresent = false;

    int inventory[3][3] = {
        //                          y:
        //                  Small, Medium, Big
        //     HpPotion       ?      ?      ?
        // x:  ManaPotion     ?      ?      ?
        //     DamagePotion   ?      ?      ?
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    };
protected:
    bool damagemultstate = false;
    float damagemultiplier = 100.0f;
    float health = 0.0f;
    float mana = 0.0f;

    int maxhealth = 0;
    int maxmana = 0;
    float damage = 0.0f;
    float spelldamage = 0.0f;
    int manacost = 0;
public:

    Character(int maxhealth, int maxmana, float damage, float spelldamage, int manacost);

    int GetMaxHealth() const;
    int GetMaxMana() const;
    int GetHealth();
    int GetMana();
    int GetSpellManaCost();
    bool GetInvenotrySlotValueForBot(PotionType potiontype, PotionCostAndSize potionsize);
    void TakeHealth(int damage);
    void TakeMana(int usedmana);
    void Attack(Character* characterPtrToDamage);
    void CastSpell(Character* characterPtrToDamage);
    
    void GiveMoney();
    int GetMoney();
    void PrintStats();
    void PrintStatsBetter(Character* botPtr);
    void DrinkPotion(PotionType potiontype, PotionCostAndSize potionsize);
    bool BoolReturnForPotionPresent();
    void BuyPotion(PotionType potiontype, PotionCostAndSize potionsize);
    void PrintInventory();
};