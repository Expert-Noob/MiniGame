#pragma once
#include "../include/Character.h"

Character* InitializeCharacter();

void PickPotion(Character* characterPtr);

void DrinkPotionFunc(Character* characterPtr);

void BuyPotionFunc(Character* characterPtr);

Character* InitializeBot();

void CheckAndPerformMove(Character* characterPtr, Character* characterPtrToDamage);