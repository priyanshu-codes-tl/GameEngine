#include "player.h"
#include <iostream>

int main() {
    player player1("Alex", 100, 20, 50);
    player player2("Roman", 100, 20, 50);

    std::cout << "----Battle Begins-----" << std::endl;

    int round = 1;


    while(player1.getHealth() > 0 && player2.getHealth() > 0) {

        std::cout << "---Round: " << round << " ----" << std::endl;

        //Player1 attake player 2
        player2.takeDamage();

        //check if player2 surivied
        if (player2.getHealth() <= 0) {
            break;
        }

        //if player2 surivied they try to heal
        player2.heal();

        //player2 counter attack player1
        player1.takeDamage();
        
        //check if player1 died from the counter-attack  
        if (player1.getHealth() <= 0) {
            break;
        }

        //if player1 survived they try to heal
        player1.heal();

        round++;
        
    }

    std::cout << "-----Battle result-----" << std::endl;

    if (player1.getHealth() > 0)
    {
        std::cout << player1.name << " wins!" << std::endl;
    }

    else {
        std::cout << player2.name << " wins!" << std::endl;
    }
    
    
    return 0;
}