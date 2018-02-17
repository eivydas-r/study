#include <iostream>
#include <fstream>
using namespace std;

int main(){
    ofstream dataFile("data.txt");
    dataFile.open("data.txt");
    
    if (dataFile.is_open()){
        dataFile << "This is a test.\n";
        dataFile << "This is also a test.\n";
        dataFile.close();
    } else cout << "Unable to open file";
    
    return 0;
}
