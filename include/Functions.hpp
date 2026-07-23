#pragma once
#include "../include/Character.hpp"

Character* InitializeCharacter();

void PickPotion(Character* characterPtr);

void DrinkPotionFunc(Character* characterPtr);

void BuyPotionFunc(Character* characterPtr);

Character* InitializeBot();

void CheckAndPerformMove(Character* characterPtr, Character* characterPtrToDamage);

void BotMove(Character* botPtr, Character* characterPtrToDamage);