#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
using namespace std;

void writeToFile(string name, string data){
    ofstream dataFile;
    dataFile.open(name);
    
    if (dataFile.is_open()){
        dataFile << data;
        dataFile.close();
    } else cout << "Unable to open file"; exit(1);
}

void readFile(string name){
    string line;
    ifstream dataFile(name);
    
    if (dataFile.is_open()){
        while (getline(dataFile,line)){
            cout << line << endl;
        }
        
        dataFile.close();
    } else cout << "Unable to open file"; exit(1);
}


int main(){
    //readFile("data.txt");
    writeToFile("data.txt", "Hello world!");
    
    return 0;
}
