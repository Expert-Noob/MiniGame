#pragma once

//headers
#include "Character.hpp"

Character* InitializeCharacter();
Character* InitializeBot();

void BuyPotionFunc(Character* characterPtr);
void PickPotion(Character* characterPtr);
void DrinkPotionFunc(Character* characterPtr);

void CheckAndPerformMove(Character* characterPtr, Character* characterPtrToDamage);
void BotMove(Character* botPtr, Character* characterPtrToDamage);