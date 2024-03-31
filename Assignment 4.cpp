/******************************************
* Edgardo Richard Ventura                 *
* Week 9                                  *
* Assignment 4                            *
* Instructor: Frank Alvino                *
* CIS 121-061                             *
*******************************************/

/* I got a little to tired and started coding a tiny game in the code
So Ignore the whole top half haha.
But if you want to play it, type W for the job code and you'll get started.*/

#include <iostream>
#include <iomanip>
#include <limits> // Needed for std::numeric_limits
#include <cctype> // Needed for character conversion functions
#include <string> // Needed for string type
#include <cstdlib> // Needed for random number generation
#include <ctime> // Needed for seeding the random number generator
using namespace std;

void startGame() {
    const string dragonArt = R"dragon(
              ___====-_  _-====___
        _--^^^#####//      \\#####^^^--_
     _-^##########// (    ) \\##########^-_
    -############//  |\^^/|  \\############-
  _/############//   (@::@)   \\############\_
 /#############((     \\//     ))#############\
 ###############\\    (oo)    //###############
 -###############\\  / VV \  //###############-
  --###############\\/      \//###############--
    -############# /        \ #############-
      -##########/   /\  /\   \##########-
          -#######  /      \  #######-
             -#### /        \ #####-
                -_/          \_-
)dragon";

    const string treasureArt = R"treasure(
             _.--.
         _.-'_:-'||     "Analog and Syntax"
     _.-'_.-::::'||     The treasure awaits!
 _.-:'_.-::::::'  ||
   .'`-.-:::::::'  ||
  /.'`;|:::::::'   ||_
 ||   ||::::::'     _.;._'-._
 ||   ||:::::'  _.-!oo @.!-._'-.
 \'.  ||:::::.-!()oo @!()@.-'_.|
  '.'-;|:.-'.&$@.& ()$%-'o.'\U||
    `>'-.!@%()@'@_%-'_.-o _.|'||
     ||-._'-.@.-'_.-' _.-o  |'||
     ||=[ '-._.-\U/.-'    o |'||
     || '-.]=|| |'|      o  |'||
     ||      || |'|        _| ';
     ||      || |'|    _.-'_.-'
     |'-._   || |'|_.-'_.-'
     '-._'-.|| |' `_.-'
          '-.||_/.-'
)treasure";

        const string goblinArt = R"goblin(
           ___
         .';:;'.
        /_' _' /\   __
        ;a/ e= J/-'"  '.
        \ ~_   (  -'  ( ;_ ,.
         L~"'_.    -.  \ ./  )
         ,'-' '-._  _;  )'   (
       .' .'   _.'")  \  \(  |
      /  (  .-'   __\{`', \  |
     / .'  /  _.-'   "  ; /  |
    / /    '-._'-,     / / \ (
 __/ (_    ,;' .-'    / /  /_'-._
`"-'` ~`  ccc.'   __.','     \j\L\
                 .='/|\7      
                   ' `
)goblin";

        const string rockArt = R"rock(
            ______
           /      \
          / o o o  \
       __/__________\__
      /                \ 
    _/   \    __    /   \_
  / |    /   \__/   \    | \
 |  |   |            |   |  |
 |  |   \__        __/   |  |
 |  |      |\____/|      |  |
 |  |      |      |      |  |
 |  |       ------       |  |
 |  /                    \  |
 | |          __          | |
 \  \        /  \        /  /
  \__|      |    |      |__/
     |      |    |      |
     |______|    |______|
     |      |    |      |
     |______|    |______|
    (________)  (________)???????????????????????????????????????????
)rock";

  
    cout << "\n\nWelcome to Analog and Syntax!" << endl;

    // Game initialization
    int health = 4, room = 1, enemyHealth;
    string action;
    bool gameRunning = true;

    // Random seed initialization
    srand(time(0));

    // Game loop
    while (gameRunning) {
        cout << "\nYou are in room " << room << ". ";
        if (room == 1) {
            cout << goblinArt << endl;
            cout << "There is a goblin here. ";
            enemyHealth = 1;
        }
        else if (room == 4) {
            cout << rockArt << endl;
            cout << "There is a golem here. ";
            enemyHealth = 2;
        }
        else if (room == 8) { // Assuming room 8 is the boss room
            cout << dragonArt << endl;
            cout << "There is a dragon here. ";
            enemyHealth = 3;
        }

        cout << "Choose an action: move, attack, inspect, quit: ";
        cin >> action;

        if (action == "quit") {
            gameRunning = false;
        }
        else if (action == "move") {
            // Simplified movement logic, you may want to add more details
            cout << "You can move up or back: ";
            cin >> action;
            if (action == "up") room++;
            else if (action == "back") room--;
        }
        else if (action == "attack") {
            int attackOutcome = rand() % 2; // 0 for player hit, 1 for enemy hit
            if (attackOutcome == 0) {
                cout << "You hit the enemy!" << endl;
                enemyHealth--;
                if (enemyHealth <= 0) {
                    cout << "You defeated the enemy!" << endl;
                    health = 4; // Regain health
                    room++; // Move to the next room
                }
            }
            else {
                cout << "The enemy hit you!" << endl;
                health--;
                if (health <= 0) {
                    cout << "You have been defeated. Game Over." << endl;
                    gameRunning = false;
                }
            }
        }
        else if (action == "inspect") {
            if (room == 2) {
                cout << "You found a secret passage to the treasure room!" << endl;
                room = 9; // Treasure room
            }
            else {
                cout << "There's nothing special here." << endl;
            }
        }

        if (room == 9) {
            cout << treasureArt << endl;
            cout << "Congratulations, you've found the treasure!" << endl;
            gameRunning = false;
        }
    }
}

int main() {
    string ln;
    char jc;
    double hw, gp;
    double tgp = 0;
    const double overtimeRate = 1.5;
    const double regularHours = 40.0;

    cout << fixed << setprecision(2);

    while (true) {
        cout << "(Press Ctrl+Z then Enter to stop at anytime)" << endl;
        cout << "\n         Enter last name: ";
        if (!(cin >> ln)) break;

        cout << "Enter job code (L, A, J): "; //Press W to play game.
        cin >> jc;
        jc = toupper(jc);

        if (jc == 'W') {
            startGame(); // Start the easter egg game
            continue; // Skip the rest of the loop and start over
        }

        cout << "      Enter hours worked: ";
        cin >> hw;
        while (cin.fail() || hw < 0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\nInvalid input. Please enter a positive number for hours worked." << endl;
            cout << "      Enter hours worked: ";
            cin >> hw;
        }

        double payRate;
        switch (jc) {
        case 'L': payRate = 25.0; break;
        case 'A': payRate = 30.0; break;
        case 'J': payRate = 50.0; break;
        default: payRate = 0.0; cout << "Invalid job code entered.\n"; continue;
        }

        if (hw > regularHours) {
            gp = (regularHours * payRate) + ((hw - regularHours) * payRate * overtimeRate);
        }
        else {
            gp = hw * payRate;
        }
        tgp += gp;

        cout << "\n               Last Name: " << ln << endl;
        cout << "               Gross Pay: $" << gp << "\n" << endl;
    }

    cout << "\nTotal Gross Pay for all employees: $" << tgp << endl;

    return 0;
}
