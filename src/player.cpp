#include "player.h"
#include <iostream>

player::player (std::string pName, int pHealth, int pArmour, int pHealAmount) {
    name = pName;
    setArmour(pArmour);
    setHealth(pHealth);
    setHealAmount(pHealAmount);   
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

void player::takeDamage () {
    if(health > 0) {
        if (armour > 0) {
            int calculatedHealth = getHealth() - 10;
            setHealth(calculatedHealth);
            int calculatedArmour = getArmour() - 5;
            setArmour(calculatedArmour);

            std::cout << name << " took damage! New Health: " << getHealth() << std::endl;
        }

        else if (armour <= 0) {
            int calculatedHealth = getHealth() - 20;
            setHealth(calculatedHealth);

            std::cout << name << " took damage! New Health: " << getHealth() << std::endl;
        }
    }

    else {
        std::cout << name << " is dead!" << std::endl;
    }

}

void player::heal () {
    if (health < 70) {
        if (healAmount >= 20) {
            int calculatedHealth = getHealth() + 20;
            setHealth(calculatedHealth);
            int calculatedHealAmount = getHealAmount() - 20;
            setHealAmount(calculatedHealAmount);

            std::cout << name << " using healing potion! New Health: " << getHealth() << ". Remaining heal amount: " << getHealAmount() << std::endl;
        }

        else if (healAmount < 20 && healAmount > 0) {
            int calculatedHealth = getHealth() + getHealAmount();
            setHealth(calculatedHealth);
            int calculatedHealAmount = getHealAmount() - getHealAmount();
            setHealAmount(0);

            std::cout << name << " using remaining healing potion! New Health: " << getHealth() << ". Remaining heal amount: " << getHealAmount() << std::endl;
        }

        else {
            std::cout << name << " tried healing but healing pool was empty!" << std::endl;
        }
    }
}