#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h> //exit(1)
using namespace std;

void writeToFile(string name, string data){ //writes data to an inputted file
    ofstream dataFile;
    dataFile.open(name);
    
    if (dataFile.is_open()){
        dataFile << data;
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


int main(){
    writeToFile("data.txt", "Hello world!!!!");
    readFile("data.txt");
    
    return 0;
}
