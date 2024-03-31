/******************************************
* Edgardo Richard Ventura                 *
* Week 9                                  *
* Assignment 3                            *
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
    * gc = gas cost per trip            *
    * tgc = total gas cost              *
    *************************************/
    string dc;
    double mt, gu, mpg, gc;
    double tgc = 0;
    const double gasPricePerGallon = 3.50; // Cost of gas per gallon

    cout << fixed << setprecision(2); // Set decimal precision for money and miles per gallon

    /* Input Phase */
    while (true) {
        cout << "(Press Ctrl+Z then Enter to stop at anytime)";
        cout << "\nEnter destination city: ";
        if (!(cin >> dc)) break; // Check for EOF (Ctrl+Z)

        cout << "  Enter miles traveled: ";
        cin >> mt;
        while (cin.fail() || mt < 0) { // Validate miles traveled
            cin.clear(); // Clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard bad input
            cout << "\nInvalid input. Please enter a positive number for miles traveled." << endl;
            cout << "  Enter miles traveled: ";
            cin >> mt;
        }

        cout << "    Enter gallons used: ";
        cin >> gu;
        while (cin.fail() || gu <= 0) { // Validate gallons used and avoid division by zero
            cin.clear(); // Clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard bad input
            cout << "\nInvalid input or division by zero. Please enter a positive number for gallons used." << endl;
            cout << "    Enter gallons used: ";
            cin >> gu;
        }

        /* Process Phase */
        mpg = mt / gu; // Calculate miles per gallon
        gc = gu * gasPricePerGallon; // Calculate gas cost for the trip
        tgc += gc; // Accumulate total gas cost

        /* Output Phase */
        cout << "\n      Destination City: " << dc << endl;
        cout << "      Miles per Gallon: " << mpg << endl;
        cout << "           Cost of Gas: $" << gc << "\n" << endl;
    }

    /* Summary Output */
    cout << "\n     Total Cost of Gas: $" << tgc << endl;

    return 0;
}
