//
//  functions.h
//  study
//
//  Created by Eivydas Raulynaitis on 10/7/18.
//  Copyright © 2018 eivydas-r. All rights reserved.
//

#ifndef functions_h
#define functions_h
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h> //exit(1)
using namespace std;

namespace functions{
    void writeToFile(string name, string data){ //writes data to an inputted file
        ofstream dataFile;
        dataFile.open(name,ios::app); //opens and appends to end of file
        
        if (dataFile.is_open()){
            dataFile << data << "\n";
            dataFile.close();
        } else cout << "Unable to open file";;
    }
    
    void readFile(string name){ //reads the text within an inputted file
        string line;
        ifstream dataFile(name);
        
        cout << endl << "** Reading..." << endl;
        
        if (dataFile.is_open()){
            while (getline(dataFile, line)){
                cout << line << endl;
            }
            dataFile.close();
        } else cout << "Unable to open file";;
    }
    
    void addAnswer(bool& terminate, char letter){
        string prefix = "["; //use str.insert instead
        prefix += letter;
        prefix += "] ";
        cout << prefix;
        
        string answer;
        getline(cin,answer);
        
        if (tolower(answer[0]) == 'x'){
            cout << "Correct answer: ";
            char choice;
            cin >> choice;
            choice = toupper(choice);
            string answer;
            answer += "Answer: ";
            answer += toupper(choice);
            answer += "\n\n";
            writeToFile("data.txt", answer);
            terminate = true;
        } else {
            writeToFile("data.txt", prefix + answer);
            terminate = false;
        }
    }
    
    void addQuestion(){
        cout << endl << "** Enter prompt:" << endl << "[?] ";
        string prompt;
        getline(cin,prompt);
        writeToFile("data.txt", "[?] " + prompt + "\n");
        
        cout << "** Enter possible answers, 'X' to stop:" << endl;
        
        bool terminate = false;
        int count = 1;
        
        while (!terminate){
            switch (count){
                case 1:
                    addAnswer(terminate, 'A');
                    break;
                case 2:
                    addAnswer(terminate, 'B');
                    break;
                case 3:
                    addAnswer(terminate, 'C');
                    break;
                case 4:
                    addAnswer(terminate, 'D');
                    break;
                case 5:
                    addAnswer(terminate, 'E');
                    break;
                case 6:
                    addAnswer(terminate, 'F');
                    break;
                case 7:
                    addAnswer(terminate, 'G');
                    break;
                case 8:
                    addAnswer(terminate, 'H');
                    break;
                case 9:
                    addAnswer(terminate, 'I');
                    break;
            }
            if (count > 9){
                cout << endl << "** Maximum answers reached..." << endl;
                break;
            } else{
                count++;
            }
        }
        //addQuestion();
    }

    void mainMenu(){
        cout << "** Welcome. What would you like to do today?" << endl;
        cout << "[A] add questions mode" << endl;
        cout << "[B] quiz mode" << endl;
        cout << "[C] test mode" << endl;
        cout << "[D] read all current data" << endl;
        cout << "[E] clear all data" << endl;
        cout << "[Y] extra info" << endl;
        cout << "[X] quit program" << endl;
        cout << "-- ";
        
        char choice;
        cin >> choice;
        cin.clear(); //bypass newline by enter
        cin.ignore( numeric_limits <streamsize> ::max(), '\n' );
        
        switch (toupper(choice)) {
            case 'A':
                addQuestion();
                break;
            case 'B':
                cout << "** Still in development." << endl;
                break;
            case 'C':
                cout << "** Still in development." << endl;
                break;
            case 'D':
                readFile("data.txt");
                break;
            case 'E':
                cout << "** Still in development." << endl;
                break;
            case 'Y':
                cout << "[Y] extra info:" << endl
                << "\t** Selection info" << endl
                << "\t[A] add questions mode: allows you to add \n\tquestions with answers to the data file that can \n\tbe later used for other modes" << endl
                << "\t[B] quiz mode: will quiz you on the questions in \n\tdata, good for studying" << endl
                << "\t[C] test mode: will test you on questions in data, \n\tanswers and percentage correct given at the end" << endl
                << "\t[D] read all current data: reads all current \n\tquestions/answers collected in the data file" << endl
                << "\t[E] clear all data: delete all data stored in data \n\tfile permanently" << endl
                << "\t[Y] extra info: this" << endl;
                
                cout << "\n\t** Type 'X' to return to main menu: ";
                char input;
                cin >> input;
                break;
            case 'X':
                cout << "** Still in development." << endl;
                break;
            default:
                cout << "** Still in development." << endl;
                break;
        }
    }
}


#endif /* functions_h */
