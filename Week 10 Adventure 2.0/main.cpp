#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// global variables
int health = 15;
int totalTreasure = 0;

// function to display the story
void Story() {
    cout << "You are an adventurer seeking treasure in a dangerous dungeon.\n";
    cout << "Legend has it that there is a great treasure hidden deep within.\n";
    cout << "Are you brave enough to risk your life and find it?\n";
}

// function to ask a yes/no question
bool AskYesNo(string question) {
    char answer;
    cout << question << " (y/n): ";
    cin >> answer;
    return (answer == 'y' || answer == 'Y');
}

// function to roll a die with a default of 6 sides
int RollDie(int sides = 6) {
    return rand() % sides + 1;
}

// function to display the ending message
void Ending() {
    cout << "You have died!\n";
    cout << "You ended up with " << totalTreasure << " treasure for someone else to pick up...\n";
}

// function for the adventure containing rolls for enemy and player attack
void Adventure() {
    int enemyAttack, playerBlock, treasure;
    bool keepGoing = true;
    while (keepGoing && health > 0) {
        enemyAttack = RollDie();
        playerBlock = RollDie();
        treasure = RollDie(10);
        cout << "An enemy attacks you with " << enemyAttack << " force.\n";
        cout << "You block with " << playerBlock << " force.\n";
      // checks to see if player successfully blocks attack
        if (playerBlock >= enemyAttack) {
            cout << "You successfully blocked the attack and found " << treasure << " treasure!\n";
            totalTreasure += treasure;
        } else {
            cout << "You failed to block the attack and lost " << enemyAttack << " health.\n";
            health -= enemyAttack;
        }
      //checks player's health if at 0 play the ending function if not then ask if they want to keep going.
       if (health <= 0) {
        Ending();
        } else{
        cout << "Your health is now " << health << "and you have " << totalTreasure << " treasure.\n";
        keepGoing = AskYesNo("Do you want to continue adventuring?");
         }
    }
}

// main function
int main() {
    srand(time(0)); // initialize random seed
    Story();
    bool startAdventure = AskYesNo("Do you want to start your adventure?");
    if (startAdventure) {
        Adventure();
    }
        // Final health check to see if player is above 0
    if(health > 0){
      cout << "Congrats! You lived to tell the tale! You made out with " << health << " Health and " << totalTreasure << " Treasure! You're Rich!\n";
      }
    return 0;
}
