/*

// Compiling like this WILL NOT WORK
c++ test.cpp -o test.out

// In order to compile use
c++ -std=c++11 test.cpp -o test.out

*/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
 
using namespace std;

//  Complete graph to adjacency matrix
vector<vector<int>> graphM_complete( int n )
{
    //  Initialize adjacency matrix to 1
    vector<vector<int>> KnM( n, vector<int>( n, 1 ) );
    //  Fill diagonal with 0
    for( int i=0; i<n; i++ ) 
         KnM[i][i] = 0;
    return KnM;
}

int main()
{
    return 0;
}

