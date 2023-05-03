#include <iostream>
using namespace std;
#include <cstdlib>
#include <ctime>
#include <fstream>


void add(string favGames[], int index) {
  cout << "What games would you like to add?\n";
  string input;
  cin >> input;
  favGames[index] = input;
  index++;
}

void load(string favGames[], int index){
 ifstream file;
file.open("SavedGames.txt");
  if(file.is_open()){
    string line;
    while(getline(file, line)) {
      favGames[index] = line;
      index++;
  }
    file.close();
 }
}

void save(string favGames[], int index){
ofstream save;
save.open("SaveGames.txt");
  if(save.is_open()) {
    for(int i = 0; i < index; i++) {
      save << favGames[i] << "\n";
    }
    save.close();
  }
  else {
    cout << "Unable to save file.";
  }
}


int main() {
  string favGames[100];
  int index = 0;

  load(favGames, index);

  while(true) {
      cout << "\nWhat would you like to do?\n";
      cout << "\nType 'quit' to quit the program.\n";
      cout << "\nType 'add' to add a game.\n";
      cout << "\nType 'show' to show your favorite games.\n";
      cout << "\nType 'edit' to edit your favorite games.\n";
      cout << "\nType 'editlast' to edit your last game.\n";
      cout << "\nType 'find' to find the game you want to edit.\n";
      cout << "\nType 'addBulk' to continously add games.\n\n";
      cout << "\nType 'Save' to save your chosen games.\n\n";
      cout << "\nType 'Load' to load your chosen games.\n\n";

      // get input
      string input;
      cin >> input;

      if(input == "Load") {
        load(favGames, index);
      }

      if(input == "Save") {
        save(favGames, index);
      }

      // test the input
      if (input == "quit") {
        cout << "\nShutting down goodbye father....\n";
        break; // or return 0 to REALLY quit the program.
      }

      if (input == "add") {
        add(favGames, index);
      }

      else if (input == "show") {
        cout << "Ugh you enjoy these games?!?:\n";
        for (int i = 0; i < index; i += 1) {
          cout << i + 1 << "." << favGames[i] << "\n";
        }
      }

      // what if we mess up?
      else if (input == "edit") {
        cout << "What is the number of the game you want to change?\n";
        int numInput;
        cin >> numInput;

        cout << "What would you like to change " << favGames[numInput - 1]
             << " to?\n";
        cin >> input;
        favGames[numInput - 1] = input;
      }

      else if (input == "editlast") {
        cout << "Last entry was " << favGames[index - 1]
             << ", change to what?\n";
        cin >> input;
        favGames[index - 1] = input;
      }

      else if (input == "find") {
        cout << "What are you trying to find?\n";
        cin >> input;

        // look through the games to see if you can find input
        for (int i = 0; i < index; i++) {

          if (input == favGames[i]) {
            cout << "Found your dumb game.\n";
            cout << "What would you like to change this dumb game to next?\n";
            cin >> input;

            favGames[i] = input;
            break;
          }

          if (i + 1 == index) {
            cout << "I looked through the entire list and couldn't find "
                 << input << ".\n";
          }
        } // end of for loop
      }

      
      //  What if we wanted to player to continously add games?
    if (input == "addBulk") {
  cout << "Keep on inputting how many games you want in. To exit out please type 'quit'.\n";
      // While loop to keep on adding in games until quit is called
  while (true) {
    //  Input before to check to see if quit is called
    cin >> input;
    if (input == "quit") {
      break; // Exit the loop
    }
   else
    favGames[index] = input;
    index += 1;
    }
  }
    } // end of while(true)
}
