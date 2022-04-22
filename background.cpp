#include <iostream>
#include <string>
#include "fileoperations.cpp"

using std::cout;
using std::string;

class BACKGROUND{
protected:
    //object of class FILEOPERATION which will be used to get boss images from text files
    FILEOPERATION file_operation;
    CONVERSIONS convert;

private:
    string background;

public:
    //function prototypes
    string intro_info(string setting);
    string assign_intro(string new_intro);

    void set_background(string background){
        this->background = background;
    }

    string get_background(){
        return background;
    }

    void building_string_background(string background){
        if (background == "castle"){

            string castle_file = "castle.txt";
            //getting image from the file and storing it in a new string called boss1_img
            const string castle_img = file_operation.background_art(castle_file);
            cout << castle_img;


        }
        else if (background == "mountain"){
            string mountain_file = "mountain.txt";
            //getting image from the file and storing it in a new string called boss1_img
            const string mountain_img = file_operation.background_art(mountain_file);
            cout << mountain_img;
        }
        else if (background == "door"){
            string door_file = "door.txt";
            //getting image from the file and storing it in a new string called boss1_img
            const string door_img = file_operation.background_art(door_file);
            cout << door_img;
        }
    }


    //function which clears lines depending on the length of the string
    void redraw(string input_string){
        int length = input_string.length();
        for (int i = 0; i < length; i++){
            cout << "\n";
        }
    }

};






class GAME_TEXT: public BACKGROUND{
private:
    //private string variable for holding the fin_game_text string
    string game_text_file = "game_text.txt";
    //getting fin_game_text from the file and storing it in a new string called boss1_img
    vector<string> unf_game_text = file_operation.game_text(game_text_file);

    string fin_game_text{};



public:
    //Default constructor
    GAME_TEXT(){}

    //Constructor 2
    GAME_TEXT(int begin, int end){
        this->fin_game_text = convert.text_vec_to_str(file_operation.display_text(unf_game_text, begin, end));
    }


    //gets fin_game_text from this class
    string get_intro(){
        return fin_game_text;
    }

};





class BOSS_ONE: public BACKGROUND{
private:
    //note that file_operation object is created once only in parent class so all inherited classes can use it
    //string which stores the name of the file we want to open
    string boss1_file = "dracula.txt";
    //getting image from the file and storing it in a new string called boss1_img
    const string boss1_img = file_operation.background_art(boss1_file);

public:
    //instance of the intro_background class
    GAME_TEXT instance;

    //Default constructor
    BOSS_ONE(){}

    //Constructor 2
    BOSS_ONE(string intro_change){

    }

    //getter for boss1_img
    string get_boss1(){return boss1_img;}


    //default boss function
    void boss(string boss){
        cout << boss;
        cout << "\nThe first boss has appeared! Kill it quickly before he turns you into a vampire!" << std::endl;
    }
};





class BOSS_TWO: public BOSS_ONE{
private:
    //string which stores the name of the file we want to open
    string boss2_file = "ghost.txt";
    //getting image from the file and storing it in a new string called boss2_img
    const string boss2_img = file_operation.background_art(boss2_file);

public:
    //getter for boss2_img
    string get_boss2(){return boss2_img;}

    //overrided boss function
    void boss(string boss){
        cout << "\nThe second boss has appeared!" << std::endl;
        cout << boss;
    }
};
