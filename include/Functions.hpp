#pragma once

//headers
#include "Character.hpp"

Character* InitializeCharacter();
Character* InitializeBot();

void BuyPotionChooseFunc(Character* characterPtr);
void PickPotion(Character* characterPtr);
void DrinkPotionChooseFunc(Character* characterPtr);

void CheckAndPerformMove(Character* characterPtr, Character* characterPtrToDamage);
void BotMove(Character* botPtr, Character* characterPtrToDamage);