#include <iostream>
#include <map>
#include <vector>
#include "condition.h"

using namespace std;

Condition::Condition(vector<Color> arr, int blacks, int whites){
    this->arr = arr;
    this->black = blacks;
    this->white = whites;
}

bool Condition::check(vector<Color> input){
    if (this->checkBlack(input) != this->getBlack()){
        return false;
    } else if (this->checkWhite(input, this->getBlack(), this->getWhite()) != true){
        return false;
    } else {
        return true;
    }
};

// returns how many same color same pos between input and cond
int Condition::checkBlack(vector<Color> input){
    int count = 0;
    for (int i = 0; i < this->arr.size(); i++){
        if (input[i] == this->arr[i]){
            count += 1;
        }
    }
    return count;
};

// returns how many same color different pos; excluded blacks
bool Condition::checkWhite(vector<Color> input, int blacks, int whites){
    vector<Color> must_have = this->arr;

    for (int i = 0; i < input.size(); i++){
        if (contains(must_have, input[i])){
            must_have.erase(find(must_have.begin(), must_have.end(), input[i]));
            }
        }
    int count;
    for (int i = 0; i < input.size(); i++){
        if (contains(this->arr, input[i]) and input[i] != this->arr[i]){
            count += 1;
        }
    }

    if (blacks + whites == input.size() - must_have.size() and count == whites){
        return true;
    } else {
        return false;
    }
};

bool Condition::contains(vector<Color> arr, Color c){
    for (Color color : arr){
        if (c == color){
            return true;
        } 
    }
    return false;
};

vector<Color> Condition::getArr(){return arr;}
int Condition::getBlack(){return black;}
int Condition::getWhite(){return white;}


// setters
void Condition::setBlack(int n){this->black = n;}
void Condition::setWhite(int n){this->black = n;}

