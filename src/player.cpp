#include "player.h"
#include <iostream>

player::player (std::string pName, int pHealth, int pArmour, int pHealAmount) {
    setName(pName);
    setArmour(pArmour);
    setHealth(pHealth);
    setHealAmount(pHealAmount);   
}

std::string player::getName ()  {
    return name;
}

int player::getHealth () {
    return health;
}

int player::getArmour () {
    return armour;
}

int player::getHealAmount () {
    return healAmount;
}

void player::setName (std::string newName) {
    name = newName;
}


void player::setHealth (int newHealth) {
    //clamp health to game design and prevent over healing bugs
    if (newHealth<0) {
        health =0;
    }

    else if (newHealth >100) {
        health = 100;
    }

    else {
        health = newHealth;
    }
}

void player::setArmour (int newArmour) {
    //clamp armour to game design and prevent over healing bugs
    if (newArmour < 0) {
        armour = 0;
    }
    else if (newArmour >30) {
        armour = 30;
    }

    else {
        armour = newArmour;
    }

}

void player::setHealAmount (int newHealAmount) {
    //clamp heal amount to game design and prevent over healing bugs
    if (newHealAmount < 0) {
        healAmount = 0;
    }
    else if (newHealAmount >50) {
        healAmount = 50;
    }

    else {
        healAmount = newHealAmount;
    }

}

std::string player::takeDamage () {

    std::string logMessage = "";
    if(health > 0) {
        if (armour > 0) {
            setHealth(getHealth() - 10);
            setArmour(getArmour() - 5);

            logMessage = getName() + " took damage! New Health: " + std::to_string(getHealth());
        }

        else {
            setHealth(getHealth() - 20);

            logMessage = getName() + " took Heavy damage! No Armour. New Health: " + std::to_string(getHealth());
        }
    }

    else {
        logMessage = getName() + " is already dead!";
    }

    //Print to console and return stat to our tracker
    std::cout << logMessage << std::endl;
    return logMessage;

}

std::string player::heal () {

    std::string logMessage = "";

    if (health < 70) {
        if (healAmount >= 20) {
            setHealth(getHealth() + 20);
            setHealAmount(getHealAmount() - 20);

            logMessage = getName() + " using healing potion! New Health: " + std::to_string(getHealth()) + ", Potion left: " + std::to_string(getHealAmount());
        }

        else if (healAmount < 20 && healAmount > 0) {
            setHealth(getHealth() + getHealAmount());
            setHealAmount(0);

            logMessage = getName() + " using remaining healing potion! New Health: " + std::to_string(getHealth()) + ", Potion Left: " + std::to_string(getHealAmount());
        }

        else {
            logMessage = getName() + " tried healing but potion pool was empty!";
        }
        std::cout << logMessage << std::endl;
    }
    
    return logMessage;
}