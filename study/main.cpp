#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h> //exit(1)
#include "functions.h"
using namespace std;
using namespace functions;

int main(){
    mainMenu(); //inputs into [A] prompt unintentionally also
    
    return 0;
}


/*
 ** Welcome. What would you like to do today?
 [A] add questions mode
 [B] quiz mode (right/wrong quizzing w/ every question
 [C] test mode (doesn't show answers until end, gives percentage of correct)
 [D] read all current data
 [E] clear all data
 [Y] extra info
 [X] quit program
 
 
 
 [Y] extra info:
    ** Selection info
    [A] add questions mode: allows you to add questions with answers to the data file that can be later used for other modes
    [B] quiz mode: will quiz you on the questions in data, good for studying
    [C] test mode: will test you on questions in data, answers and percentage correct given at the end
    [D] read all current data: reads all current questions/answers collected in the data file
    [E] clear all data: delete all data stored in data file permanently
    [Y] extra info: this
 
    ** Type 'X' to return to main menu:
 
 
    ** About
    This program was made by Eivydas Raulynaitis.
    Feel free to check out the development history at https://github.com/eivydas-r/study
 
 
*/
