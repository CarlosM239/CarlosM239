#include "ui.h"

using std::string;
using std::cout;
using std::cin;


bool continue_or_not() {
    string pick = "";
    cout << "\n\t\t\tWould you like to continue or run away? (y/n): ";
    cin >> pick;
    cout << '\n';

    if (pick[0 == 'y' || pick[0] == 'Y']) {
        return true;
    }
    else if (pick[0 == 'n' || pick[0] == 'N']) {
        return false;
    }
    else {
        cout << "You did not enter a valid response.";
        continue_or_not();
    }
    //return added here to prevent annoying warning from compiler
    return true;
}
