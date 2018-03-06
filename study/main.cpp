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

void addAnswer(string answer, char letter){
    cout << answer << endl; //this prints nothing?
    if (answer == "x"){
        return;
    }
    string prefix = "["; //use str.insert instead
    prefix += letter;
    prefix += "] ";
    cout << prefix;
    getline(cin,answer);
    writeToFile("data.txt", prefix + answer);
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
                addAnswer(answer, 'A');
                break;
            case 2:
                addAnswer(answer, 'B');
                break;
            case 3:
                addAnswer(answer, 'C');
                break;
            case 4:
                addAnswer(answer, 'D');
                break;
            case 5:
                addAnswer(answer, 'E');
                break;
            case 6:
                addAnswer(answer, 'F');
                break;
            case 7:
                addAnswer(answer, 'G');
                break;
            case 8:
                addAnswer(answer, 'H');
                break;
            case 9:
                addAnswer(answer, 'I');
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
