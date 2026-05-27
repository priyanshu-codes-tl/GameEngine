#include "player.h"
#include <iostream>
#include <string>
#include <fstream> //crucial library for reading and writing files!
#include <chrono>

//Function to save player data to a text file 
void saveGame (player& p1, player& p2, int currentRound) {

    std::ofstream saveFile ("../saveGame.txt");   //save player data to saveGame.txt

    if(saveFile.is_open()) {

        //write player 1 data seperated by spaces
        saveFile << p1.getName() << " " << p1.getHealth() << " " << p1.getArmour() << " " << p1.getHealAmount() << "\n";
        //write player 2 data sperated by spaces
        saveFile << p2.getName() << " " << p2.getHealth() << " " << p2.getArmour() << " " << p2.getHealAmount() << "\n";
        //Save cuurent round
        saveFile << currentRound << "\n";
        //Always close your file to prevent data corruption
        saveFile.close();

        std::cout << "[SYSTEM] game file saved successfully to saveGame.txt" << std::endl;
     }

     else {
        std::cerr << "[ ERROR] Could not create save file!" << std::endl;
     }

}

//Function to read saved game data from saveGame.txt
int loadGame (player& p1, player& p2) {

    std::ifstream loadFile ("../saveGame.txt");    //load player data from saveGame.txt
    int savedRound = 1;

    if(loadFile.is_open()) {
        std::string name1, name2;
        int h1, a1, ha1;
        int h2, a2, ha2;

        //extracting data in exact same order we wrote it

        loadFile >> name1 >> h1 >> a1 >> ha1;
        loadFile >> name2 >> h2 >> a2 >> ha2;
        loadFile >> savedRound;

        //Apply the loaded data to our obeject using setter

        p1.setName(name1); p1.setHealth(h1); p1.setArmour(a1); p1.setHealAmount(ha1);
        p2.setName(name2); p2.setHealth(h2); p2.setArmour(a2); p2.setHealAmount(ha2);

        loadFile.close();

        std::cout << "[SYSTEM] Game loaded successfully!" << std::endl;
        return savedRound;
    }

    else {
        std::cout << "[SYSTEM] Saved game file not found!. Starting a fresh battle!" << std::endl;
        return 1;
    }
}

int main() {
    player player1("Alex", 100, 20, 50);
    player player2("Roman", 100, 20, 50);

    std::cout << "----Battle Begins-----" << std::endl;

    //Try to load existing save state!
    int round = loadGame(player1, player2);


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

        //Let's simulate an auto save milestone at the end of Round 1!
        if(round==1) {

            //Taking the starting snapshot using highest resolution clock.
            auto startTime = std::chrono::high_resolution_clock::now();

            round++;

            saveGame(player1, player2, round);

            //Taking the ending snapshot using highest resolution clock.
            auto endTime = std::chrono::high_resolution_clock::now();

            //Calculate the diffrence in microseconds
            auto duration = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime).count();

            std::cout << "[PROFILE] saveGame() executed in: " << duration << " microseconds." << std::endl;
            std::cout << "[SYSTEM] Stopping battle to test save file. Run the program again to resume!" << std::endl;

            return 0;
        }

        else {
            if(round % 3 == 0) {
                auto startTime = std::chrono::high_resolution_clock::now();

                int nextRound = round+1;
                saveGame(player1, player2, nextRound);

                //Taking the ending snapshot using highest resolution clock.
                auto endTime = std::chrono::high_resolution_clock::now();

                //Calculate the diffrence in microseconds
                auto duration = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime).count();

                 std::cout << "[PROFILE] saveGame() executed in: " << duration << " microseconds." << std::endl;
            }
        }

        round++;
        
    }

    std::cout << "-----Battle result-----" << std::endl;

    if (player1.getHealth() > 0)
    {
        std::cout << player1.getName() << " wins!" << std::endl;
    }

    else {
        std::cout << player2.getName() << " wins!" << std::endl;
    }
    
    
    return 0;
}