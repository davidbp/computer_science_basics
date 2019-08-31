/*
#### Program description

This code reads an adjacency list graph from a file and plots 

- The number of edges
- the edge list


#### Compilation code
c++ -std=c++11 1_read_edge_list.cpp  -o  1_read_edge_list.out


#### Output of the program
```
Graph read from file: ./files/edge_lists/graph1.in

n_edges: 7

Edge list pairs: 
0 1
1 2
0 3
1 2
1 2
2 2
3 1
```

*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

typedef vector<vector<int>> edgelist;

edgelist graphE_read(std::string fname)
{
    std::ifstream stream_file;
    stream_file.open( fname.c_str() );    
    if( stream_file.fail() ) {
        std::cerr << "unable to open file " << fname.c_str() << " for reading" << endl;
        exit(1);
    }
    
    // Read vertices and edges numbers
    int n_vertices, n_edges;
    stream_file >> n_vertices >> n_edges;
    
    // Initialize Edge matrix to 0
    edgelist E(n_edges, {0,0});
    //cout << "n_edges"    << n_edges << "\n";
    //cout << "n_vertices" << n_vertices << "\n";
    
    // Fill edge list
    for( int j=0; j<n_edges; j++ ) {
        int u, v;
        stream_file >> u >> v;
        E[j][0] = u;
        E[j][1] = v;
    }
    stream_file.close( );
    return E;
}


int main() {
    edgelist E;
    std::string f = "./files/edge_lists/graph1.in";
    
    E = graphE_read(f);
    cout << "\nGraph read from file: " << f << endl;
    cout << "\nn_edges: " << E.size() <<"\n";

    cout << "\nEdge list pairs: \n";
    for(int i=0; i<E.size(); i++)
        cout << E[i][0] << " " << E[i][1] << "\n";
    
    cout << "\n";
}
