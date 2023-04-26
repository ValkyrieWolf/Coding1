#include <iostream>
#include <ctime>
#include <cstdlib>
#include "enemy.h"
using namespace std;


int main() {

  enemy duke("Duke");
  duke.status();

  cout << "There was a storm! Duke loses 2 health.\n";
  duke.changeHealth(-2);
  cout << "Duke's health is now " << duke.getHealth() << ".\n";

  cout << "What name would you like to give to Duke?\n";
  string input;
  cin >> input;

  //setting the name
  duke.setName(input);
  // getting the name
  cout << "Duke is now named " << duke.getName() << ".\n";
}