#include <iostream>
#include "condition.h"
#include "search.h"




using namespace std;
// complie: g++ -std=c++11 app.cpp condition.cpp search.cpp
// run: ./a.out

int main(){
    cout << "Welcome to MasterMind Solver" << endl;
    cout << "Please test red, green, blue, yellow" << endl;
    vector<Color> last  = {Color::red, Color::green, Color::blue, Color::yellow};
    vector<Condition> conditions;
    while (true){
        string input;
        int blacks;
        int whites;
        cout << "Did it work? y/n";
        cin >> input;
        if (input == "y"){
            cout << "AI > human :)" << endl;
            break;
        } 
        cout << "enter the number of blacks" << endl;
        cin >> blacks;
        cout << "enter the number of whites" << endl;
        cin >> whites;

        Condition condition_to_add = Condition(last, blacks, whites);
        conditions.push_back(condition_to_add);

        vector<Color> next_guess = nextGuess(conditions);
        cout << "please try:" << endl;
        vector<string> all_color = {"red", "green", "blue", "yellow", "brown", "orange", "black", "white"};
        for (Color c : next_guess){
            cout << c << " : " << all_color[c] << endl;
            
        }

        last = next_guess;

    }
    return -1;
};



