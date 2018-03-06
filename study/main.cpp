#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h> //exit(1)
using namespace std;

void writeToFile(string name, string data){ //writes data to an inputted file
    ofstream dataFile;
    dataFile.open(name);
    
    if (dataFile.is_open()){
        dataFile << data << "\n"; //doesn't skip line and add to file, resets file
        dataFile.close();
    } else cout << "Unable to open file";;
}

void readFile(string name){ //reads the text within an inputted file
    string line;
    ifstream dataFile(name);
    
    if (dataFile.is_open()){
        while (getline(dataFile, line)){
            cout << line << endl;
        }
        dataFile.close();
    } else cout << "Unable to open file";;
}

void addQuestion(){
    cout << "** Enter prompt:" << endl << "[?] ";
    string prompt;
    getline(cin,prompt);
    writeToFile("data.txt", "[?] " + prompt + "\n");
    
    cout << "** Enter possible answers, 'X' to stop:" << endl;
    string answer;
    int count = 1;

    while (tolower(answer[0]) != 'x'){
        switch (count){
            case 1:
                cout << "[A] ";
                break;
            case 2:
                cout << "[B] ";
                break;
            case 3:
                cout << "[C] ";
                break;
            case 4:
                cout << "[D] ";
                break;
            case 5:
                cout << "[E] ";
                break;
            case 6:
                cout << "[F] ";
                break;
            case 7:
                cout << "[G] ";
                break;
            case 8:
                cout << "[H] ";
                break;
            case 9:
                cout << "[I] ";
                break;
            default:
                break;
        }
        getline(cin,answer);
        writeToFile("data.txt", "[A] " + answer); //move into switch later
        count++;
    }
    
    readFile("data.txt");
}


int main(){
    addQuestion();
    
    
    return 0;
}
