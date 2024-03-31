/******************************************
* Edgardo Richard Ventura                 *
* Week 9                                  *
* Assignment 1                            *
* Instructor: Frank Alvino                *
* CIS 121-061                             *
*******************************************/
#include <iostream>
#include <iomanip>
#include <limits> // Needed for std::numeric_limits
using namespace std;

int main() {
    /************************************
    * q = quantity                      *
    * p = price                         *
    * t = total before discount         *
    * dt = total after discount         *
    * st = sum of totals                *
    * sdt = sum of discount totals      *
    *************************************/
    double q, p, t, dt;
    double st = 0, sdt = 0;
    string discountMessage; // To store discount percentage message

    cout << fixed << setprecision(2);

    /* Input Phase */
    while (true) {
        cout << "(Press Ctrl+Z then Enter to stop at anytime)";
        cout << "\n    Enter quantity:  ";
        cin >> q;

        // Check for EOF (Ctrl+Z) immediately after trying to read
        if (cin.eof()) {
            cin.clear(); // Clear EOF state to allow further I/O operations
            break; // Exit the loop to proceed to summary output
        }

        // Validate numeric input for quantity
        while (cin.fail()) {
            cin.clear(); // Clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard bad input
            cout << "\nInvalid Input. Please enter a valid number for quantity." << endl;
            cout << "    Enter quantity:  ";
            cin >> q;
        }

        cout << "       Enter price: $";
        cin >> p;
        // Validate numeric input for price
        while (cin.fail()) {
            cin.clear(); // Clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard bad input
            cout << "\nInvalid Input. Please enter a valid number for price." << endl;
            cout << "       Enter price: $";
            cin >> p;
        }

        /* Process Phase */
        t = q * p; // Compute total
        if (t > 10000) {
            dt = t - (t * 0.10); // Apply 10% discount
            discountMessage = "10% Discount Total: $"; // Set message for 10% discount
        }
        else {
            dt = t - (t * 0.05); // Apply 5% discount
            discountMessage = " 5% Discount Total: $"; // Set message for 5% discount
        }

        st += t; // Accumulate total sums
        sdt += dt; // Accumulate discounted total sums

        /* Output Phase */
        cout << "\n             Total: $" << t << endl;
        cout << discountMessage << dt << "\n" << endl; // Output discount message with applied percentage
    }

    /* Summary Output */
    cout << "\n         Sum Total: $" << st << endl;
    cout << "Sum Discount Total: $" << sdt << endl;

    return 0;
}
