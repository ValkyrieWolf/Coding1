#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

// our global variables
string bountyHunterNames[] = {"Boba Fett", "Jango Fett", "Django Freeman",
                              "Deadpool", "Deathstroke"};

// our class function for creating bounty hunters
class bountyHunter {
public:
  string name; // bounty hunter names
  int health;  // bounty hunter health
  int x;       // horizontal movement
  int y;       // vertical movement

  bountyHunter(string myName = "Hunter", int givenHealth = 10) {
    cout << "A new bounty hunter has entered the field!\n";
    name = myName;
    health = givenHealth;
    // randomize their location between -3 and +3
    x = (rand() % 6) - 2;
    y = (rand() % 6) - 2;
  }

  void status() {
    cout << "\n[" << name << ": " << health << "]\n";
    cout << name << "'s [Postion on the field is " << x << "," << y << "...]\n";
  }

  void move() {

    if (health <= 0) {
      cout << name << " is hurt...\n";
      return; // don't move.

      while (true) {
        int direction = rand() % 4; // 0 = n, 1 = s, 2 = e, 3 = w

        if (direction == 0) {
          // if not at the top of the map...
          if (y < 3) {
            // go north...
            y++;
            cout << name << " charges north.\n";
            break;
          }
        } else if (direction == 1 && y > -3) {
          y--;
          cout << name << " charges south.\n";
          break;
        } else if (direction == 2 && x < 3) {
          x++;
          cout << name << " charges east.\n";
          break;
        } else if (direction == 3 && x > -3) {
          x--;
          cout << name << " charges west.\n";
          break;
        }

        cout << "A hunter is stuck in a trap, moving them...\n";

      } // end of the while loop()
      health -= 1;
    }
  }

  void sayWarning(bountyHunter bountyHunter[]) {
    for (int i = 0; i < 10; i++) {
      if (bountyHunter[i].x == x) {
        if (&bountyHunter[i] == this)
          continue;
        cout << "they're on the same x-axis...\n";
        if (bountyHunter[i].y == y) {
          cout << "They're near!!\n\n";
          cout << name << " says: "
               << "get out of here before I hurt you! " << bountyHunter[i].name
               << "!\n\n";
        }
      }
    }
  }
};

bountyHunter bountyHunters[10];

int main() {
  srand(time(0));

  // creating our bounty hunters randomly
  for (int i = 0; i < 10; i++) {
    bountyHunters[i] =
        bountyHunter(bountyHunterNames[rand() % 5], rand() % 5 + 5);
  }

  for (int i = 0; i < 10; i++) {
    // move the bounty hunters
    cout << "\nHunters moving out!\n";
    for (int j = 0; j < 10; j++) {
      bountyHunters[j].move();
      bountyHunters[j].status();
      cout << "\n";
      // checks to see if the bounty hunters health is above 0, if it is play
      // the warning.
      if (bountyHunters[j].health > 0)
        bountyHunters[j].sayWarning(bountyHunters);
    }
  }

  // let's get the status of all of these robots...
  cout << "How are our bounty hunters holding up....\n";
  for (int i = 0; i < 10; i++) {
    bountyHunters[i].status();
  }
}
