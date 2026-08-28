//headers
#include "../include/Functions.hpp"
#include "../include/Character.hpp"
#include "../include/Print.hpp"

//std
#include <iostream>
#include <string>
#include <random>

//asks user to pick a character
//returns pointer to Character on a heap
Character* InitializeCharacter(){
    while(true){
        std::string choose;
        std::getline(std::cin, choose);
        
        //parameters for constructor: 
        //maxhealth, maxmana, damage, spelldamage, manacost
        if(choose == "Axe"){
            Character* characterPtr = new Character(200, 100, 20.0f, 30.0f, 50);
            return characterPtr;
        }
        else if(choose == "Lina"){
            Character* characterPtr = new Character(100, 100, 40.0f, 80.0f, 150);
            return characterPtr;
        }
        else if(choose == "Rubick"){
            Character* characterPtr = new Character(150, 200, 10.0f, 50.0f, 60);
            return characterPtr;
        }
        else if(choose == "Ursa"){
            Character* characterPtr = new Character(175, 125, 30.0f, 40.0f, 35);
            return characterPtr;
        }
        else{
            std::cout << "Invalid input!\n\nEnter again: ";
        }
    }
}

//initializes random character for bot 
Character* InitializeBot(){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(1, 4);

    int random_num = distrib(gen);

    Character* botPtr = nullptr;

    //parameters for constructor: 
    //maxhealth, maxmana, damage, spelldamage, manacost
    if(random_num == 1){
        botPtr = new Character(200, 100, 20.0f, 30.0f, 50);
    }
    else if(random_num == 2){
        botPtr = new Character(100, 150, 40.0f, 80.0f, 150);
    }
    else if(random_num == 3){
        botPtr = new Character(150, 200, 10.0f, 50.0f, 60);
    }
    else if(random_num == 4){
        botPtr = new Character(175, 125, 30.0f, 40.0f, 35);
    }
    else{
        std::cout << "Error!" << '\n';
        botPtr = new Character(200, 100, 20.0f, 30.0f, 50);
    }

    botPtr->BuyPotion(PotionType::HPPOTION, PotionCostAndSize::MEDIUM);
    botPtr->BuyPotion(PotionType::MANAPOTION, PotionCostAndSize::SMALL);
    botPtr->BuyPotion(PotionType::MANAPOTION, PotionCostAndSize::SMALL);

    return botPtr;
}

void BuyPotionChooseFunc(Character* characterPtr){
    std::cout << "Do you want to buy something from the shop? (yes/no)" << '\n';;
    std::cout << "Money:" << characterPtr->GetMoney() << '\n';
    std::cout << "Enter: ";

    std::string input;
    while(input != "no"){  
        std::getline(std::cin, input);
        std::cout << '\n';
    
        if(input == "no"){
            //nothing
        }
        else if(input == "yes"){
            printShop();

            std::cout << "You can enter the first letter of each word as a shortcut (e.g. BHP = Big_Hp_Potion)" << '\n';
            std::cout << "Enter what you want to buy: ";
            PickPotion(characterPtr);

            std::cout << '\n';
            PrintInventory(characterPtr);
            std::cout << "Do you want to buy anything else? (yes/no)\nEnter: ";
        }
        else{
            std::cout << "Invalid input!\n\nEnter again: ";
        }
    }
}

void PickPotion(Character* characterPtr){
    while(true){
        std::string itemname;
        std::getline(std::cin, itemname);
        
        if(itemname == "Small_Hp_Potion" || itemname == "SHP"){
            characterPtr->BuyPotion(PotionType::HPPOTION, PotionCostAndSize::SMALL);
            break;
        }
        else if(itemname == "Medium_Hp_Potion" || itemname == "MHP"){
            characterPtr->BuyPotion(PotionType::HPPOTION,PotionCostAndSize::MEDIUM);
            break;
        }
        else if(itemname == "Big_Hp_Potion" || itemname == "BHP"){
            characterPtr->BuyPotion(PotionType::HPPOTION, PotionCostAndSize::BIG);
            break;
        }
        else if(itemname == "Small_Mana_Potion" || itemname == "SMP"){
            characterPtr->BuyPotion(PotionType::MANAPOTION, PotionCostAndSize::SMALL);
            break;
        }
        else if(itemname == "Medium_Mana_Potion" || itemname == "MMP"){
            characterPtr->BuyPotion(PotionType::MANAPOTION, PotionCostAndSize::MEDIUM);
            break;
        }
        else if(itemname == "Big_Mana_Potion" || itemname == "BMP"){
            characterPtr->BuyPotion(PotionType::MANAPOTION, PotionCostAndSize::BIG);
            break;
        }
        else if(itemname == "Small_Damage_Potion" || itemname == "SDP"){
            characterPtr->BuyPotion(PotionType::DAMAGEPOTION, PotionCostAndSize::SMALL);
            break;
        }
        else if(itemname == "Medium_Damage_Potion" || itemname == "MDP"){
            characterPtr->BuyPotion(PotionType::DAMAGEPOTION, PotionCostAndSize::MEDIUM);
            break;
        }
        else if(itemname == "Big_Damage_Potion" || itemname == "BDP"){
            characterPtr->BuyPotion(PotionType::DAMAGEPOTION, PotionCostAndSize::BIG);
            break;
        }
        else{
            std::cout << "Invalid input!\n\nEnter again: ";
        }
    }
}

void DrinkPotionChooseFunc(Character* characterPtr){
    while(true){
        std::string itemname;
        std::getline(std::cin, itemname);

        if(itemname == "Small_Hp_Potion" || itemname == "SHP"){
            characterPtr->DrinkPotion(PotionType::HPPOTION, PotionCostAndSize::SMALL);
            break;
        }
        else if(itemname == "Medium_Hp_Potion" || itemname == "MHP"){
            characterPtr->DrinkPotion(PotionType::HPPOTION, PotionCostAndSize::MEDIUM);
            break;
        }
        else if(itemname == "Big_Hp_Potion" || itemname == "BHP"){
            characterPtr->DrinkPotion(PotionType::HPPOTION, PotionCostAndSize::BIG);
            break;
        }
        else if(itemname == "Small_Mana_Potion" || itemname == "SMP"){
            characterPtr->DrinkPotion(PotionType::MANAPOTION, PotionCostAndSize::SMALL);
            break;
        }
        else if(itemname == "Medium_Mana_Potion" || itemname == "MMP"){
            characterPtr->DrinkPotion(PotionType::MANAPOTION, PotionCostAndSize::MEDIUM);
            break;
        }
        else if(itemname == "Big_Mana_Potion" || itemname == "BMP"){
            characterPtr->DrinkPotion(PotionType::MANAPOTION, PotionCostAndSize::BIG);
            break;
        }
        else if(itemname == "Small_Damage_Potion" || itemname == "SDP"){
            characterPtr->DrinkPotion(PotionType::DAMAGEPOTION, PotionCostAndSize::SMALL);
            break;
        }
        else if(itemname == "Medium_Damage_Potion" || itemname == "MDP"){
            characterPtr->DrinkPotion(PotionType::DAMAGEPOTION, PotionCostAndSize::MEDIUM);
            break;
        }
        else if(itemname == "Big_Damage_Potion" || itemname == "BDP"){
            characterPtr->DrinkPotion(PotionType::DAMAGEPOTION, PotionCostAndSize::BIG);
            break;
        }
        else{
            std::cout << "Invalid input!\n\nEnter Again: ";
        }
    }
}

void CheckAndPerformMove(Character* characterPtr, Character* characterPtrToDamage){
    while(true){
        std::cout << "Choose your move: attack, cast_spell, use_potion or skip" << '\n';
        std::cout << "Enter: ";
        std::string move;
        std::getline(std::cin, move);
        std::cout << '\n';

        if(move == "attack"){
            characterPtr->Attack(characterPtrToDamage);
            break;
        }
        else if(move == "cast_spell"){
            if(characterPtr->GetSpellManaCost() > characterPtr->GetMana()){
                std::cout << "You dont have enough mana\n" << '\n';
            }
            else{
                characterPtr->CastSpell(characterPtrToDamage);
                break;
            }
        }
        else if(move == "use_potion"){
            std::cout << "Which potion you want to use?" << '\n';
            PrintInventory(characterPtr);
            std::cout << "Enter: ";
            DrinkPotionChooseFunc(characterPtr);
            if(characterPtr->GetIsIsPotionDrank()){
                break;
            }
        }
        else if(move == "skip"){
            break;
        }
        else{
            std::cout << "Invalid input!\n" << '\n';
        }
    }
}

void BotMove(Character* botPtr, Character* characterPtrToDamage){
    while(true){
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> distrib(1, 3);
    
        int random_num = distrib(gen);
        
        if(random_num == 1){
            botPtr->Attack(characterPtrToDamage);
            std::cout << "Bot Attacks\n" << '\n';
            break;
        }
        else if(random_num == 2){
            if(botPtr->GetSpellManaCost() <= botPtr->GetMana()){
                botPtr->CastSpell(characterPtrToDamage);
                std::cout << "Bot casts spell\n" << '\n';
                break;
            }
        }
        else if(random_num == 3){
            if(botPtr->GetHealth() <= (botPtr->GetMaxHealth()/2) && 
            botPtr->GetNumberOfPotionsInInventorySlot(PotionType::HPPOTION, PotionCostAndSize::MEDIUM) > 0){
                std::cout << "Bot Uses potion" << '\n';
                botPtr->DrinkPotion(PotionType::HPPOTION, PotionCostAndSize::MEDIUM);
                if(botPtr->GetIsIsPotionDrank()){
                    break;
                }
            }
            else if(botPtr->GetMana() <= (botPtr->GetMaxMana()/2) && 
            botPtr->GetNumberOfPotionsInInventorySlot(PotionType::MANAPOTION, PotionCostAndSize::SMALL) > 0){
                std::cout << "Bot Uses potion" << '\n';
                botPtr->DrinkPotion(PotionType::MANAPOTION, PotionCostAndSize::SMALL);
                if(botPtr->GetIsIsPotionDrank()){
                    break;
                }
            }
        }
        else{
            std::cout << "Error";
        }
    }
}