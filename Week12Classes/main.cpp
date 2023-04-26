#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;


string names[] = {"USS Cool Boat", "USS Does Things", "USS Doesn't Sink"};

class spaceShip{
  string name;
  int fuelLevel;
  // class 1 = carrier, 2 = destroyer, 3 = fighter
  int shipClass = 2;

public:
  spaceShip(string givenName = "USS Boat", int givenFuel = -1, int givenClass = -1){
    //randomize
    if(givenName == "USS Boat"){
      // randomize name
      name = names[rand() % 3];
    }
    else {
      name = givenName;
    }

    if(givenFuel == -1){
      // randomize
      fuelLevel = rand() % 75 +25;
    }
    else {
      fuelLevel = givenFuel;
    }

    if(givenClass == -1){
      // randomize
      shipClass = rand() % 3 + 1;
    }
    else {
      shipClass = givenClass;
    }

    sitrep();
  } // end of constructor.

  void sitrep(){
    cout << "The spaceship \"" << name << "\" has " << fuelLevel << " fuel.\n";
    cout << "This ship is a ";

    switch(shipClass){
      case 1: cout << "Carrier.\n\n";
      break;
      case 2: cout << "Destroyer.\n\n";
      break;
      case 3: cout << "Fighter.\n\n";
      break;
      default: cout << "UNKOWN.\n\n";
      break;
    }
  }

  void travel() {
    cout << "You wish to travel to a farawy star system.\n";
    int requiredFuel = rand() % 25 + 1;
    cout << "it requires " << requiredFuel << " fuel.\n";
    cout << "You have " << fuelLevel << " units of fuel.\n";
    if(fuelLevel > requiredFuel){
      cout << "Let's go!\n";
      fuelLevel -= requiredFuel;
      cout << "You have " << fuelLevel << " units of fuel left.\n\n";
    }
    else {
      cout << "You do not have enough fuel to travel.\n";
    }
  }

// getters and setters allow access to private variables, with guidelines
  // GetName() just returns the name of the string.
  string GetName(){
    return name;
  }
  void SetName(string givenName){
    // check for obscenities
    if(givenName == "shit" || givenName == "Shit" || givenName == "5h1t" || givenName == "SHIT") {
      cout << "Naughty! Be nice, friend.\n";
      return;          // don't change the name.
    }
    if(givenName.size() > 10 || givenName.size() < 3) {
      cout << "No names longer than 10 characters.\n";
      cout << "Also no names shorter than 3 characters.\n";
      return;
    }

    name = givenName;
  }
  int GetFuelLevel(){
    return fuelLevel;
  }
  void SetFuelLevel(int givenLevel) {
    if(givenLevel < 0){
      fuelLevel = 0;
    }
    else if(givenLevel > 100){
      fuelLevel = 100;
      cout << "you have an excess of " << givenLevel - 100 << " fuel.\n";
    }
    else{
      fuelLevel = givenLevel;
    }
  }

};

int main() {
  srand(time(0));
  spaceShip apollo;          // randomizes everything
  spaceShip falcon("Millenium Falcon");    // randomize all but the name
  spaceShip bananaBoat("Banana Boat", 45, 3);

  cout << "Bananaboat is strying to travel...\n\n";
  bananaBoat.travel();
  bananaBoat.travel();
  bananaBoat.travel();
  bananaBoat.travel();


  // don't allow this:
  // bananaBoat.name = "plaintainBoat";

  cout << "\nMy spaceship's name is " << bananaBoat.GetName() << ".\n";
  cout << "Jerk: That's a terrible name! Change it to 'coolboat3'!!\n";
  cout << "Fine.\n";
  bananaBoat.SetName("coolboat3");
  cout << "\nMy spaceship's name is " << bananaBoat.GetName() << ".\n";

  cout << "My current fuel level is " << bananaBoat.GetFuelLevel() << ".\n";
  cout << "Time to refuel. paying for 200 gallons of fuel.\n";
  bananaBoat.SetFuelLevel(200);

  cout << "\nI now have " << bananaBoat.GetFuelLevel() << " fuel.\n";
}