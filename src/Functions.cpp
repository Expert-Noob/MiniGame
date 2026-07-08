#include <iostream>
#include <string>
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