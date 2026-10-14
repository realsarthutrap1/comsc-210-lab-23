// COMSC-210 | Lab 23 | Sarthak Pani
// adapted from the instructor goat manager starter

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <list>
#include <sstream>
#include "Goat.h"
using namespace std;

const int SZ_NAMES = 200, SZ_COLORS = 25;

int select_goat(list<Goat> trip);
void delete_goat(list<Goat> &trip);
void add_goat(list<Goat> &trip, string [], string []);
void display_trip(list<Goat> trip);
int main_menu();

int main() {
    srand(time(0));

    // read & populate arrays for names and colors
    ifstream fin("names.txt");
    string names[SZ_NAMES];
    for (int i = 0; i < SZ_NAMES; ++i) {
        if (!(fin >> names[i])) {
            cerr << "Could not read all names from names.txt" << endl;
            return 1;
        }
    }
    fin.close();
    ifstream fin1("colors.txt");
    string colors[SZ_COLORS];
    for (int i = 0; i < SZ_COLORS; ++i) {
        if (!(fin1 >> colors[i])) {
            cerr << "Could not read all colors from colors.txt" << endl;
            return 1;
        }
    }
    fin1.close();

    // keep the menu running until the user quits
    int choice;
    do {
        choice = main_menu();
        switch (choice) {
        case 1:
            cout << "Adding goats will be available in the next milestone." << endl;
            break;
        case 2:
            cout << "Deleting goats will be available in the next milestone." << endl;
            break;
        case 3:
            cout << "Listing goats will be available in the next milestone." << endl;
            break;
        case 4:
            cout << "Goodbye!" << endl;
            break;
        }
    } while (choice != 4);

    return 0;
}

int main_menu() {
    cout << "*** GOAT MANAGER 3001 ***\n"
         << "[1] Add a goat\n"
         << "[2] Delete a goat\n"
         << "[3] List goats\n"
         << "[4] Quit\n";

    while (true) {
        cout << "Choice --> ";
        string input;
        if (!getline(cin, input))
            return 4;

        // accept one whole integer and reject extra input
        istringstream entry(input);
        int choice;
        char extra;
        if (entry >> choice && !(entry >> extra) && choice >= 1 && choice <= 4)
            return choice;

        cout << "Please enter a number from 1 to 4." << endl;
    }
}
