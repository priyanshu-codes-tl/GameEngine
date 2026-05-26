#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class player {

    private:
    
    int health;
    int armour;
    int healAmount;
    std::string name;

    public:

    player (std::string pName, int pHealth, int pArmour, int pHealAmount);

    int getHealth ();
    void setHealth (int newHealth);

    int getHealAmount ();
    void setHealAmount ( int newHealAmount);

    int getArmour ();
    void setArmour ( int newArmour);

    std::string getName ();
    void setName(std::string newName);

    void takeDamage ();
    void heal ();

};

#endif // PLAYER_H