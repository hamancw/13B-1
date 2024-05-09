#include <iostream>
#include <string>

using namespace std;

bool isLeapYear(int year) {
    // Check if the year is divisible by 4
    if (year % 4 == 0) {
        // If divisible by 100, it must also be divisible by 400 to be a leap year
        if (year % 100 == 0) {
            if (year % 400 == 0)
                return true;
            else
                return false;
        }
        else {
            return true;
        }
    }
    return false;
}

int main() {
    string input;
    int year;

    while (true) {
        cout << "Enter a year or Q to quit: ";
        cin >> input;

        if (input == "Q" || input == "q") {
            break;
        }

        // Convert input to integer
        try {
            year = stoi(input);
            if (year < 1582) {
                cout << "Year must be >= 1582." << endl;
                continue;
            }
        }
        catch (...) {
            cout << "Invalid input. Please enter a valid year or Q to quit." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        // Check if the year is a leap year and print the result
        if (isLeapYear(year)) {
            cout << year << " is a leap year." << endl;
        }
        else {
            cout << year << " is not a leap year." << endl;
        }
    }

    return 0;
}
