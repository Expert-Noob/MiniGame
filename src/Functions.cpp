#include <iostream>
#include <string>
#include <random>
#include "../include/Character.h"
#include "../include/Print.h"

Character* InitializeCharacter(){
    Character* characterPtr = nullptr;
    while(true){
        std::string choose;
        std::cin >> choose;
        if(choose == "Axe"){
            characterPtr = new Axe;
            return characterPtr;
        }
        else if(choose == "Lina"){
            characterPtr = new Lina;
            return characterPtr;
        }
        else if(choose == "Rubick"){
            characterPtr = new Rubick;
            return characterPtr;
        }
        else if(choose == "Ursa"){
            characterPtr = new Ursa;
            return characterPtr;
        }
        else{
            std::cout << "Invalid input!\n\nEnter again: ";
        }
    }
}

void PickPotion(Character* characterPtr){
    while(true){
        std::string itemname;
        std::cin >> itemname;
        if(itemname == "Small_Hp_Potion"){
            characterPtr->BuyPotion(PotionType::HPPOTION,PotionCostAndSize::SMALL);
            break;
        }
        else if(itemname == "Medium_Hp_Potion"){
            characterPtr->BuyPotion(PotionType::HPPOTION,PotionCostAndSize::MEDIUM);
            break;
        }
        else if(itemname == "Big_Hp_Potion"){
            characterPtr->BuyPotion(PotionType::HPPOTION,PotionCostAndSize::BIG);
            break;
        }
        else if(itemname == "Small_Mana_Potion"){
            characterPtr->BuyPotion(PotionType::MANAPOTION,PotionCostAndSize::SMALL);
            break;
        }
        else if(itemname == "Medium_Mana_Potion"){
            characterPtr->BuyPotion(PotionType::MANAPOTION,PotionCostAndSize::MEDIUM);
            break;
        }
        else if(itemname == "Big_Mana_Potion"){
            characterPtr->BuyPotion(PotionType::MANAPOTION,PotionCostAndSize::BIG);
            break;
        }
        else if(itemname == "Small_Damage_Potion"){
            characterPtr->BuyPotion(PotionType::DAMAGEPOTION,PotionCostAndSize::SMALL);
            break;
        }
        else if(itemname == "Medium_Damage_Potion"){
            characterPtr->BuyPotion(PotionType::DAMAGEPOTION,PotionCostAndSize::MEDIUM);
            break;
        }
        else if(itemname == "Big_Damage_Potion"){
            characterPtr->BuyPotion(PotionType::DAMAGEPOTION,PotionCostAndSize::BIG);
            break;
        }
        else{
            std::cout << "Invalid input!\n\nEnter Again: ";
        }
    }
}

void DrinkPotionFunc(Character* characterPtr){
    while(true){
        std::string itemname;
        std::cin >> itemname;
        if(itemname == "Small_Hp_Potion"){
            characterPtr->DrinkPotion(PotionType::HPPOTION,PotionCostAndSize::SMALL);
            break;
        }
        else if(itemname == "Medium_Hp_Potion"){
            characterPtr->DrinkPotion(PotionType::HPPOTION,PotionCostAndSize::MEDIUM);
            break;
        }
        else if(itemname == "Big_Hp_Potion"){
            characterPtr->DrinkPotion(PotionType::HPPOTION,PotionCostAndSize::BIG);
            break;
        }
        else if(itemname == "Small_Mana_Potion"){
            characterPtr->DrinkPotion(PotionType::MANAPOTION,PotionCostAndSize::SMALL);
            break;
        }
        else if(itemname == "Medium_Mana_Potion"){
            characterPtr->DrinkPotion(PotionType::MANAPOTION,PotionCostAndSize::MEDIUM);
            break;
        }
        else if(itemname == "Big_Mana_Potion"){
            characterPtr->DrinkPotion(PotionType::MANAPOTION,PotionCostAndSize::BIG);
            break;
        }
        else if(itemname == "Small_Damage_Potion"){
            characterPtr->DrinkPotion(PotionType::DAMAGEPOTION,PotionCostAndSize::SMALL);
            break;
        }
        else if(itemname == "Medium_Damage_Potion"){
            characterPtr->DrinkPotion(PotionType::DAMAGEPOTION,PotionCostAndSize::MEDIUM);
            break;
        }
        else if(itemname == "Big_Damage_Potion"){
            characterPtr->DrinkPotion(PotionType::DAMAGEPOTION,PotionCostAndSize::BIG);
            break;
        }
        else{
            std::cout << "Invalid input!\n\nEnter Again: ";
        }
    }
}

void BuyPotionFunc(Character* characterPtr){
    std::cout << "Do you want to buy something from the shop? (yes/no)\nEnter: ";
    while(true){  
        std::string check;
        std::cin >> check;
    
        if(check == "no"){
            break;
        }
        else if(check == "yes"){
            std::cout << '\n';
            printShop();
            std::cout << "Enter what you want to buy: ";
            PickPotion(characterPtr);
            std::cout << '\n';
            characterPtr->PrintInventory();
            std::cout << "Do you want to buy anything else? (yes/no)\nEnter: ";
        }
        else{
            std::cout << "Invalid input!\n\nEnter again: ";
        }
    }
}

Character* InitializeBot(){
    Character* botPtr = nullptr;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(1, 4);

    int random_num = distrib(gen);

    if(random_num == 1){
        botPtr = new Axe;
        return botPtr;
    }
    else if(random_num == 2){
        botPtr = new Lina;
        return botPtr;
    }
    else if(random_num == 3){
        botPtr = new Rubick;
        return botPtr;
    }
    else if(random_num == 4){
        botPtr = new Ursa;
        return botPtr;
    }
    else{
        std::cout << "Error!" << '\n';
        botPtr = new Axe;
        return botPtr;
    }
}

void CheckAndPerformMove(Character* characterPtr, Character* characterPtrToDamage){
    while(true){
        std::string move;
        std::cin >> move;
        if(move == "attack"){
            characterPtr->Attack(characterPtrToDamage);
            break;
        }
        else if(move == "cast_spell"){
            characterPtr->CastSpell(characterPtrToDamage);
            break;
        }
        else if(move == "use potion"){
            std::cout << "Which potion you want to use?" << '\n';
            characterPtr->PrintInventory();
            std::cout << '\n';
            DrinkPotionFunc(characterPtr);
            break;
        }
        else if(move == "skip"){
            break;
        }
        else{
            std::cout << "Invalid input!\n\nEnter again: ";
        }
    }
}