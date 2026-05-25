#include <player.h>
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
    if (health<0) {
        health =0;
    }

    else if (health >100) {
        health = 100;
    }

    else {
        health = newHealth;
    }
}

void player::setArmour (int newArmour) {
    //clamp armour to game design and prevent over healing bugs
    if (armour < 0) {
        armour = 0;
    }
    else if (armour >30) {
        armour = 30;
    }

    else {
        armour = newArmour;
    }

}

void player::setHealAmount (int newHealAmount) {
    //clamp heal amount to game design and prevent over healing bugs
    if (healAmount < 0) {
        healAmount = 0;
    }
    else if (healAmount >50) {
        healAmount = 50;
    }

    else {
        healAmount = newHealAmount;
    }

}

void player::takeDamage () {
    if (armour > 0) {
        int calculatedHealth = getHealth() - 10;
        setHealth(calculatedHealth);
        int calculatedArmour = getArmour() - 5;
        setArmour(calculatedArmour);
    }

    else {
        int calculatedHealth = getHealth() - 20;
        setHealth(calculatedHealth);
    }
}

void player::heal () {
    if (health < 70) {
        if (healAmount >= 20) {
            int calculatedHealth = getHealth() + 20;
            
        }
    }
}