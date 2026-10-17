#pragma once

//headers
#include "Character.hpp"

//std
#include <memory>
#include <string>

void sleepFunc(int time);
void toLowerCase(std::string& text);

std::unique_ptr<Character> InitializeCharacter();
std::unique_ptr<Character> InitializeBot();

void GameLoop(Character* character);

void BuyPotionChooseFunc(Character* characterPtr);
void PickPotionToBuy(Character* characterPtr);
void BuyPotionsForBot(Character* botPtr);
void ChoosePotionToDrink(Character* characterPtr);

void CheckAndPerformMove(Character* characterPtr, Character* characterPtrToDamage);
void BotMove(Character* botPtr, Character* characterPtrToDamage);