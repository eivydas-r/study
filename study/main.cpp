#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void writeToFile(){
    ofstream dataFile("data.txt");
    dataFile.open("data.txt"); //stops working here
    
    if (dataFile.is_open()){
        dataFile << "This is a test." << endl;
        dataFile << "This is also a test." << endl;
        dataFile.close();
    } else cout << "Unable to open file";
}

void readFile(string name){
    string line;
    ifstream dataFile(name);
    
    if (dataFile.is_open()){
        while (getline(dataFile,line)){
            cout << line << endl;
        }
        
        dataFile.close();
    } else cout << "Unable to open file";
}


int main(){
    readFile("data.txt");
    
    return 0;
}
