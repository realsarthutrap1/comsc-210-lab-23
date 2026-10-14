// COMSC-210 | Lab 23 | Sarthak Pani
// adapted from the instructor goat manager starter

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <list>
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





    return 0;
}

