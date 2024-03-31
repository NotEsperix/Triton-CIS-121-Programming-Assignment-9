/******************************************
* Edgardo Richard Ventura                 *
* Week 9                                  *
* Assignment 2                            *
* Instructor: Frank Alvino                *
* CIS 121-061                             *
*******************************************/
#include <iostream>
#include <iomanip>
#include <limits> // Needed for std::numeric_limits
using namespace std;

int main() {
    /************************************
    * ln = last name                    *
    * h = hits                          *
    * ab = at bats                      *
    * ba = batting average              *
    * pc = player count                 *
    * cba = cumulative batting average  *
    *************************************/
    string ln;
    int h, ab, pc = 0;
    double ba, cba = 0;

    cout << fixed << setprecision(3); // Batting average usually has three decimal places

    /* Input Phase */
    while (true) {
        cout << "(Press Ctrl+Z then Enter to stop at anytime)";
        cout << "\nEnter player's last name: ";
        if (!(cin >> ln)) break; // Check for EOF (Ctrl+Z)

        do {
            cout << "    Enter number of hits: ";
            cin >> h;
            cout << " Enter number of at-bats: ";
            cin >> ab;

            if (cin.fail() || ab <= 0 || h > ab) {
                cin.clear(); // Clear error flag
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard bad input
                cout << "\nInvalid input, division by zero, or more hits than at-bats. Please re-enter.\n";
            }
            else {
                break; // Valid input, exit loop
            }
        } while (true);

        /* Process Phase */
        ba = static_cast<double>(h) / ab; // Compute batting average directly in main
        cba += ba; // Add to cumulative batting average
        pc++; // Increment player count

        /* Output Phase */
        cout << "\n      Player's Last Name: " << ln << endl;
        cout << "         Batting Average: " << ba << "\n" << endl;
    }

    /* Summary Output */
    cout << "\n       Number of Players: " << pc << endl;
    if (pc > 0) { // Avoid division by zero
        cout << "   Whole Batting Average: " << cba / pc << endl; // Display average batting average becuase i wanted to :)
    }

    return 0;
}
