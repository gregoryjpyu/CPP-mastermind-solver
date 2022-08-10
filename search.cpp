#include "search.h"

vector<Color> all_color = {Color::red, Color::green, Color::blue, Color::yellow, Color::brown, Color::orange, Color::black, Color::white};

vector<Color> nextGuess(vector<Condition> conditions){
    for (Color c1 : all_color){
        for (Color c2 : all_color){
            for (Color c3: all_color){
                for (Color c4: all_color){
                    vector<Color> guess {all_color[c1],all_color[c2],all_color[c3],all_color[c4]};
                    if (checkAllConditions(guess, conditions) == true){
                        return guess;
                    }
                }
            }
        }
    }
    vector<Color> bug {Color::white,Color::white,Color::white,Color::white};
    return bug;
}

bool checkAllConditions(vector<Color> input, vector<Condition> conditions){
    for (Condition cond : conditions){
        if (cond.check(input) == false){
            return false;
        }
    }
    return true;
}