#include "enemy.h"
#include <iostream>
using std::cout;

// define the construtor
enemy::enemy(string givenName){
  name = givenName;
  health = 10;
  cout << name << " has appeared! This is where the fun begins!\n";
}

void enemy::status(){
  cout << "Status checking... " << name << " has " << health << " health remaining...\n";
}

void enemy::changeHealth(int amount){
  health += amount;

  if(health < 0) health = 0;
  if(health > 10) health = 10;
}

int enemy::getHealth(){
  return health; 
}

void enemy::setName(string input){
  if(name == "Poop"){
    cout << "Uh oh, Stinky!";
    return;
  }
  name = input;
}

string enemy::getName(){
  return name;
}
