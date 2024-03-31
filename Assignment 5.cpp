/******************************************
* Edgardo Richard Ventura                 *
* Week 9                                  *
* Assignment 5                            *
* Instructor: Frank Alvino                *
* CIS 121-061                             *
*******************************************/
#include <iostream>
#include <iomanip>
#include <limits> // Needed for std::numeric_limits
#include <string> // Needed for string type
using namespace std;

int main() {
    /************************************
    * dc = destination city             *
    * mt = miles traveled               *
    * gu = gallons used                 *
    * mpg = miles per gallon            *
    * tmt = total miles traveled        *
    * tc = trip count                   *
    *************************************/
    string dc;
    double mt, gu, mpg;
    double tmt = 0;
    int tc = 0;

    cout << fixed << setprecision(2);

    /* Input Phase */
    while (true) {
        cout << "(Press Ctrl+Z then Enter to stop at anytime)";
        cout << "\n\nEnter destination city: ";
        if (!(cin >> dc)) break; // Check for EOF (Ctrl+Z) to exit loop

        cout << "  Enter miles traveled: ";
        cin >> mt;
        while (cin.fail()) { // Validate miles traveled input
            cin.clear(); // Clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard bad input
            cout << "Invalid input. ";
            cout << "Please enter a valid number for miles traveled: ";
            cin >> mt;
        }

        cout << "    Enter gallons used: ";
        cin >> gu;
        while (cin.fail() || gu <= 0) { // Validate gallons used input and check for positive value
            cin.clear(); // Clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard bad input
            cout << "Invalid input. ";
            cout << "Please enter a valid number for gallons used (greater than 0): ";
            cin >> gu;
        }

        /* Process Phase Before (Ctrl+Z) */
        mpg = mt / gu; // Calculate miles per gallon for current trip

        /* Process Phase After (Ctrl+Z) */
        tmt += mt; // Update total miles traveled
        tc++; // Increment trip count

        /* Output Phase Before (Ctrl+Z) */
        cout << "\n      Destination City: " << dc << endl;
        cout << "      Miles per Gallon: " << mpg << "\n" << endl;
    }

    /* Output Phase After (Ctrl+Z) */
    cout << "\n  Total Miles Traveled: " << tmt << endl;
    cout << "       Number of Trips: " << tc << endl;

    return 0;
}
