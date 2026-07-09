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
        if(itemname == "Small_Hp_Potion" || itemname == "SHP"){
            characterPtr->BuyPotion(PotionType::HPPOTION,PotionCostAndSize::SMALL);
            break;
        }
        else if(itemname == "Medium_Hp_Potion" || itemname == "MHP"){
            characterPtr->BuyPotion(PotionType::HPPOTION,PotionCostAndSize::MEDIUM);
            break;
        }
        else if(itemname == "Big_Hp_Potion" || itemname == "BHP"){
            characterPtr->BuyPotion(PotionType::HPPOTION,PotionCostAndSize::BIG);
            break;
        }
        else if(itemname == "Small_Mana_Potion" || itemname == "SMP"){
            characterPtr->BuyPotion(PotionType::MANAPOTION,PotionCostAndSize::SMALL);
            break;
        }
        else if(itemname == "Medium_Mana_Potion" || itemname == "MMP"){
            characterPtr->BuyPotion(PotionType::MANAPOTION,PotionCostAndSize::MEDIUM);
            break;
        }
        else if(itemname == "Big_Mana_Potion" || itemname == "BMP"){
            characterPtr->BuyPotion(PotionType::MANAPOTION,PotionCostAndSize::BIG);
            break;
        }
        else if(itemname == "Small_Damage_Potion" || itemname == "SDP"){
            characterPtr->BuyPotion(PotionType::DAMAGEPOTION,PotionCostAndSize::SMALL);
            break;
        }
        else if(itemname == "Medium_Damage_Potion" || itemname == "MDP"){
            characterPtr->BuyPotion(PotionType::DAMAGEPOTION,PotionCostAndSize::MEDIUM);
            break;
        }
        else if(itemname == "Big_Damage_Potion" || itemname == "BDP"){
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
        if(itemname == "Small_Hp_Potion" || itemname == "SHP"){
            characterPtr->DrinkPotion(PotionType::HPPOTION,PotionCostAndSize::SMALL);
            break;
        }
        else if(itemname == "Medium_Hp_Potion" || itemname == "MHP"){
            characterPtr->DrinkPotion(PotionType::HPPOTION,PotionCostAndSize::MEDIUM);
            break;
        }
        else if(itemname == "Big_Hp_Potion" || itemname == "BHP"){
            characterPtr->DrinkPotion(PotionType::HPPOTION,PotionCostAndSize::BIG);
            break;
        }
        else if(itemname == "Small_Mana_Potion" || itemname == "SMP"){
            characterPtr->DrinkPotion(PotionType::MANAPOTION,PotionCostAndSize::SMALL);
            break;
        }
        else if(itemname == "Medium_Mana_Potion" || itemname == "MMP"){
            characterPtr->DrinkPotion(PotionType::MANAPOTION,PotionCostAndSize::MEDIUM);
            break;
        }
        else if(itemname == "Big_Mana_Potion" || itemname == "BMP"){
            characterPtr->DrinkPotion(PotionType::MANAPOTION,PotionCostAndSize::BIG);
            break;
        }
        else if(itemname == "Small_Damage_Potion" || itemname == "SDP"){
            characterPtr->DrinkPotion(PotionType::DAMAGEPOTION,PotionCostAndSize::SMALL);
            break;
        }
        else if(itemname == "Medium_Damage_Potion" || itemname == "MDP"){
            characterPtr->DrinkPotion(PotionType::DAMAGEPOTION,PotionCostAndSize::MEDIUM);
            break;
        }
        else if(itemname == "Big_Damage_Potion" || itemname == "BDP"){
            characterPtr->DrinkPotion(PotionType::DAMAGEPOTION,PotionCostAndSize::BIG);
            break;
        }
        else{
            std::cout << "Invalid input!\n\nEnter Again: ";
        }
    }
}

void BuyPotionFunc(Character* characterPtr){
    std::cout << "Do you want to buy something from the shop? (yes/no)" << '\n';;
    std::cout << "Money:" << characterPtr->GetMoney() << '\n';
    std::cout << "Enter: ";
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
        botPtr->BuyPotion(PotionType::HPPOTION, PotionCostAndSize::MEDIUM);
        botPtr->BuyPotion(PotionType::MANAPOTION, PotionCostAndSize::SMALL);
        botPtr->BuyPotion(PotionType::MANAPOTION, PotionCostAndSize::SMALL);
        return botPtr;
    }
    else if(random_num == 2){
        botPtr = new Lina;
        botPtr->BuyPotion(PotionType::HPPOTION, PotionCostAndSize::MEDIUM);
        botPtr->BuyPotion(PotionType::MANAPOTION, PotionCostAndSize::SMALL);
        botPtr->BuyPotion(PotionType::MANAPOTION, PotionCostAndSize::SMALL);
        return botPtr;
    }
    else if(random_num == 3){
        botPtr = new Rubick;
        botPtr->BuyPotion(PotionType::HPPOTION, PotionCostAndSize::MEDIUM);
        botPtr->BuyPotion(PotionType::MANAPOTION, PotionCostAndSize::SMALL);
        botPtr->BuyPotion(PotionType::MANAPOTION, PotionCostAndSize::SMALL);
        return botPtr;
    }
    else if(random_num == 4){
        botPtr = new Ursa;
        botPtr->BuyPotion(PotionType::HPPOTION, PotionCostAndSize::MEDIUM);
        botPtr->BuyPotion(PotionType::MANAPOTION, PotionCostAndSize::SMALL);
        botPtr->BuyPotion(PotionType::MANAPOTION, PotionCostAndSize::SMALL);
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
        std::cout << "Enter: ";
        std::string move;
        std::cin >> move;
        std::cout << '\n';
        if(move == "attack"){
            characterPtr->Attack(characterPtrToDamage);
            break;
        }
        else if(move == "cast_spell"){
            if(characterPtr->GetSpellManaCost() > characterPtr->GetMana()){
                std::cout << "You dont have enough mana\n" << '\n';
                std::cout << "Choose your move: attack, cast_spell, use_potion or skip" << '\n';
            }
            else{
                characterPtr->CastSpell(characterPtrToDamage);
                break;
            }
        }
        else if(move == "use_potion"){
            std::cout << "Which potion you want to use?" << '\n';
            characterPtr->PrintInventory();
            std::cout << "Enter: ";
            DrinkPotionFunc(characterPtr);
            if(characterPtr->BoolReturnForPotionPresent()){
                break;
            }
            else{
                std::cout << "\nChoose your move: attack, cast_spell, use_potion or skip" << '\n';
            }
        }
        else if(move == "skip"){
            break;
        }
        else{
            std::cout << "Invalid input!\n" << '\n';
            std::cout << "Choose your move: attack, cast_spell, use_potion or skip" << '\n';
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
            if(botPtr->GetHealth() <= (botPtr->GetMaxHealth()/2) || botPtr->GetInvenotrySlotValueForBot(PotionType::HPPOTION, PotionCostAndSize::MEDIUM) > 0){
                std::cout << "Bot Uses potion" << '\n';
                botPtr->DrinkPotion(PotionType::HPPOTION, PotionCostAndSize::MEDIUM);
                if(botPtr->BoolReturnForPotionPresent()){
                    break;
                }
            }
            else if(botPtr->GetMana() <= (botPtr->GetMaxMana()/2) || botPtr->GetInvenotrySlotValueForBot(PotionType::MANAPOTION, PotionCostAndSize::SMALL) > 0){
                std::cout << "Bot Uses potion" << '\n';
                botPtr->DrinkPotion(PotionType::MANAPOTION, PotionCostAndSize::SMALL);
                if(botPtr->BoolReturnForPotionPresent()){
                    break;
                }
            }
        }
        else{
            std::cout << "Error";
        }
    }
}