#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;

class CONVERSIONS{
public:
    string img_vec_to_str(vector<string> vector_name){
        string returning{};
        for (int i = 0; i < vector_name.size(); i++){
            returning += vector_name[i] + "\n";
        }
        return returning;
    }

    string text_vec_to_str(vector<string> vector_name){
        string returning{};
        for (int i = 0; i < vector_name.size(); i++){
            returning += "\b" + vector_name[i] + "\n";
        }
        return returning;
    }
};
