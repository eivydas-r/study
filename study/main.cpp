#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h> //exit(1)
using namespace std;

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
    
    if (answer[0] == 'x'){
        terminate = true;
    } else {
        writeToFile("data.txt", prefix + answer);
        terminate = false;
    }
}

void addQuestion(){
    cout << "** Enter prompt:" << endl << "[?] ";
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
    readFile("data.txt");
}


int main(){
    addQuestion();
    
    
    return 0;
}
