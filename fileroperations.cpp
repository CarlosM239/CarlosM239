#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "functions1.cpp"
#include <algorithm>

using std::string;
using std::getline;
using std::vector;
using std::cout;
using std::replace;

class FILEOPERATION{
public:

    //This function takes a string file name and turns it into a vector and then converts it to a string
    //and returns the string
    string background_art(string file_name){
        //ifstream used for reading files
        //we'll read from a file called file_name
        std::ifstream inf("../"+file_name);

        //If we could not open the input file stream for reading
        if (!inf){
            //print an error and exit
            std::cerr << "Uh oh, " << file_name << " could not be opened for reading!\n";
            exit(1);
        }

        //This vector and string will store our file info
        vector <string> storage;
        string str;

        while (getline(inf, str)){
            if (str.size() > 0){
                str = "\t\t\t\t\t\t\t" + str;
                storage.push_back(str);
            }
        }
        //object created to use our vector to string function
        CONVERSIONS vector_to_string;
        //storing the vector converted to string in this new string
        string new_str = vector_to_string.img_vec_to_str(storage);
        //returning the new string
        return new_str;

    }

    //This function retrieves text from a .txt file and turns it into a vector
    vector<string> game_text(string file_name){
        //ifstream used for reading files
        //we'll read from a file called file_name
        std::ifstream inf("../"+file_name);

        //If we could not open the input file stream for reading
        if (!inf){
            //print an error and exit
            std::cerr << "Uh oh, " << file_name << " could not be opened for reading!\n";
            exit(1);
        }

        //This vector and string will store our file info
        vector <string> storage;
        string str;

        while (getline(inf, str)){

            if (str.size() > 0){
                    storage.push_back(str);
            }
        }

        //returning vector
        return storage;
    }

    //This function takes a vector and erases the first character from every string element
    vector<string> display_text(vector<string> vector_name, int low, int high){
        CONVERSIONS convert;
        string str_storage;
        vector<string> vec_storage;

        for (auto i : vector_name){
            str_storage = i;
            char* pointer = &str_storage[0];
            int num = atoi(pointer);
            if (num >= low && num <= high){
                str_storage[0] = ' ';
                vec_storage.push_back(str_storage);
            }
        }
        return vec_storage;
    }
};
