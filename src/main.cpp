#include "player.h"

int main() {
    player player1("Alex", 100, 20, 50);
    player player2("Roman", 100, 20, 50);

    for (int i = 0; i < 5; ++i) {
        player1.takeDamage(20);
        player1.heal();
        player2.takeDamage(35);
        player2.heal();
    }
    
    return 0;
}