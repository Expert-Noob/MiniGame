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
    virtual ~Character() = default;

    virtual int GetMaxHealth() const;
    virtual int GetMaxMana() const;
    virtual int GetHealth();
    virtual int GetMana();
    virtual int SpellManaCost();
    virtual void TakeHealth(int damage);
    virtual void TakeMana(int usedmana);
    virtual void Attack(Character* characterPtrToDamage);
    virtual void CastSpell(Character* characterPtrToDamage);
    
    void GiveMoney();
    int GetMoney();
    void PrintStats();
    void PrintStatsBetter(Character* botPtr);
    void DrinkPotion(PotionType potiontype, PotionCostAndSize potionsize);
    bool BoolReturnForPotionPresent();
    void BuyPotion(PotionType potiontype, PotionCostAndSize potionsize);
    void PrintInventory();
};

//subclasses

class Axe : public Character{
public:
    Axe();
};

class Lina : public Character{
public:
    Lina();
};

class Rubick : public Character{
public:
    Rubick();
};

class Ursa : public Character{
public:
    Ursa();
};