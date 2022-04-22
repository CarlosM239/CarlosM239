#include <iostream>
#include "background.cpp"
#include "ui.h"

using std::cin;

int main() {
    //Default constructor calls
    BACKGROUND b;
    GAME_TEXT text;
    BOSS_ONE d;
    BOSS_TWO e;

    //second constructor call
    GAME_TEXT text_change = GAME_TEXT(1,3);

    //displays the current background_mountain which is a castle
    b.set_background("door");
    string background = b.get_background();

    cout << "\n" << text_change.get_intro() << std::endl;
    b.building_string_background(background);
    cout << "\n\nType 'y' to enter:";
    string ui;
    cin >> ui;
    cout << "\n";

    //calling function boss and passing parameter that gets boss 1, and printing the boss.
    d.boss(d.get_boss1());

    //Displays redraw function to clear screen
    cout << "\nType 'y' to fight: ";
    cin >> ui;
    cout << "\nYou defeated the vampire! Type y to continue: ";
    string choice{};
    cin >> choice;
    if (choice == "y"){
        b.redraw(d.get_boss1());
    }
    else {
        cout << "ok";
    }

    //calling function boss and passing parameter that gets boss 2, and printing the boss.
    e.boss(e.get_boss2());

    return 0;
}
