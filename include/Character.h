#pragma once
#include "PotionSize.h"

class Character{
private:
    int money = 100;
    int damagemultiplier = 100;
    bool damagemultstate = false;

    int inventory[3][3] = {
        {1, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    };
protected:
    int health = 0;
    int mana = 0;
public:
    void PrintStats();
    void DrinkPotion(PotionType potiontype, PotionCostAndSize potionsize);
};

class Axe : public Character{
private:
    const int maxhealth = 200;
    const int maxmana = 100;
    const float damage = 20.f;
    const float spelldamage = 10.0f;
    const int manacost = 50;
public:
    Axe();
};

class Lina : public Character{
private:
    const int maxhealth = 100;
    const int maxmana = 150;
    const float damage = 40.0f;
    const float spelldamage = 80.0f;
    const int manacost = 150;
public:
    Lina();
};

class Rubick : public Character{
private:
    const int maxhealth = 150;
    const int maxmana = 200;
    const float damage = 10.0f;
    const float spelldamage = 50.0f;
    const int manacost = 60;
public:
    Rubick();
};

class Ursa : public Character{
private:
    const int maxhealth = 175;
    const int maxmana = 125;
    const float damage = 30.0f;
    const float spelldamage = 0.0f;
    const int manacost = 35;
public:
    Ursa();
};