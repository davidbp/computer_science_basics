
/*
#### Compilation code
c++ -std=c++11 0_write_to_file.cpp  -o 0_write_to_file.out

*/


#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

int main () {
    string line;
    //create an output stream to write to the file
    //append the new lines to the end of the file
    ofstream myfileI ("./results/0_write_to_file.txt", ios::app);
    if (myfileI.is_open())
    {
        myfileI << "\nI am adding a line.\n";
        myfileI << "I am adding another line.\n";
        myfileI.close();
    }
    else cout << "Unable to open file for writing";
}
