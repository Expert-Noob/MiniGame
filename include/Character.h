#pragma once
#include "PotionSize.h"

class Character{
private:
    int money = 100;
    float damagemultiplier = 100.0f;
    bool damagemultstate = false;
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
    int health = 0;
    int mana = 0;
public:
    virtual int GetMaxHealth() const = 0;
    virtual int GetMaxMana() const = 0;
    virtual int GetHealth() = 0;
    virtual int GetMana() = 0;
    virtual int SpellManaCost() = 0;
    virtual void TakeHealth(int damage) = 0;
    virtual void TakeMana(int usedmana) = 0;
    virtual void Attack(Character* characterPtrToDamage) = 0;
    virtual void CastSpell(Character* characterPtrToDamage) = 0;
    virtual ~Character() = default;
    void GiveMoney();
    void PrintStats();
    void PrintStatsBetter(Character* botPtr);
    void DrinkPotion(PotionType potiontype, PotionCostAndSize potionsize);
    bool BoolReturnForPotionPresent();
    void BuyPotion(PotionType potiontype, PotionCostAndSize potionsize);
    void PrintInventory();
};

//Axe

class Axe : public Character{
private:
    const int maxhealth = 200;
    const int maxmana = 100;
    const float damage = 20.f;
    const float spelldamage = 10.0f;
    const int manacost = 50;
public:
    Axe();
    int GetMaxHealth() const override;
    int GetMaxMana() const override;
    int GetHealth() override;
    int GetMana() override;
    int SpellManaCost() override;
    void TakeHealth(int damage) override;
    void TakeMana(int usedmana) override;
    void Attack(Character* characterPtrToDamage) override;
    void CastSpell(Character* characterPtrToDamage) override;
};

//Lina

class Lina : public Character{
private:
    const int maxhealth = 100;
    const int maxmana = 150;
    const float damage = 40.0f;
    const float spelldamage = 80.0f;
    const int manacost = 150;
public:
    Lina();
    int GetMaxHealth() const override;
    int GetMaxMana() const override;
    int GetHealth() override;
    int GetMana() override;
    int SpellManaCost() override;
    void TakeHealth(int damage) override;
    void TakeMana(int usedmana) override;
    void Attack(Character* characterPtrToDamage) override;
    void CastSpell(Character* characterPtrToDamage) override;
};

//Rubick

class Rubick : public Character{
private:
    const int maxhealth = 150;
    const int maxmana = 200;
    const float damage = 10.0f;
    const float spelldamage = 50.0f;
    const int manacost = 60;
public:
    Rubick();
    int GetMaxHealth() const override;
    int GetMaxMana() const override;
    int GetHealth() override;
    int GetMana() override;
    int SpellManaCost() override;
    void TakeHealth(int damage) override;
    void TakeMana(int usedmana) override;
    void Attack(Character* characterPtrToDamage) override;
    void CastSpell(Character* characterPtrToDamage) override;
};

//Ursa

class Ursa : public Character{
private:
    const int maxhealth = 175;
    const int maxmana = 125;
    const float damage = 30.0f;
    const float spelldamage = 40.0f;
    const int manacost = 35;
public:
    Ursa();
    int GetMaxHealth() const override;
    int GetMaxMana() const override;
    int GetHealth() override;
    int GetMana() override;
    int SpellManaCost() override;
    void TakeHealth(int damage) override;
    void TakeMana(int usedmana) override;
    void Attack(Character* characterPtrToDamage) override;
    void CastSpell(Character* characterPtrToDamage) override;
};