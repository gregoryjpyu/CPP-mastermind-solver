#ifndef SEARCH_H
#define SEARCH_H
#include "condition.h"

vector<Color> nextGuess(vector<Condition> conditions);
bool checkAllConditions(vector<Color> guess, vector<Condition> conditions);

#endif