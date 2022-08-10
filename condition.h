#ifndef CONDITION_H
#define CONDITION_H
#include <iostream>
#include <vector>
#include <algorithm>
#include "color.h"

using namespace std;

class Condition {
    private:
        vector<Color> arr;
        int black;
        int white;
        
    public:
        // getters
        vector<Color> getArr();
        int getBlack();
        int getWhite();
    

        // setters
        void setBlack(int n);
        void setWhite(int n);
    

        // constructor
        Condition(vector<Color>, int blacks, int whites);

        

        // check if this condition is right
        bool check(vector<Color> input);

        int checkBlack(vector<Color> input);

        bool contains(vector<Color> arr, Color c);

        bool checkWhite(vector<Color> input, int blacks, int whites);

       
};

#endif