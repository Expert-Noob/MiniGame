#pragma once

class Character{
private:
    int money = 0;
protected:
    int health = 0;
    int mana = 0;
public:
    void PrintStats();
};

class Axe : public Character{
private:
    const int maxhealth = 200;
    const int maxmana = 100;
    const int damage = 20;
    const int spelldamage = 10;
    const int manacost = 50;
public:
    Axe();
};

class Lina : public Character{
private:
    const int maxhealth = 100;
    const int maxmana = 150;
    const int damage = 40;
    const int spelldamage = 80;
    const int manacost = 100;
public:
    Lina();
};

class Rubick : public Character{
private:
    const int maxhealth = 150;
    const int maxmana = 200;
    const int damage = 10;
    const int spelldamage = 50;
    const int manacost = 60;
public:
    Rubick();
};

class Ursa : public Character{
private:
    const int maxhealth = 175;
    const int maxmana = 125;
    const int damage = 30;
    const int spelldamage = 0;
    const int manacost = 35;
public:
    Ursa();
};