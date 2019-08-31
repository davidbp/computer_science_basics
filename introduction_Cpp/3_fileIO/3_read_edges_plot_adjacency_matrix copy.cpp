
/*
#### Compilation code
c++ -std=c++11 3_read_edges_plot_adjacency_matrix.cpp  -o 3_read_edges_plot_adjacency_matrix.out


#### Program description
This code reads an adjacency list graph from a file and plots 

- The number of edges
- the adjacency matrix


#### Output of the program
```
Graph read from file: ./files/edge_lists/graph8A.in

Number of vertices: 8

Adjacency matrix:

      0 1 2 3 4 5 6 7 
      - - - - - - - - 

0 |   0 1 0 0 1 0 1 0 
1 |   1 0 1 0 0 0 0 1 
2 |   0 1 0 1 0 0 0 1 
3 |   0 0 1 0 1 1 0 0 
4 |   1 0 0 1 0 1 0 0 
5 |   0 0 0 1 1 0 1 0 
6 |   1 0 0 0 0 1 0 1 
7 |   0 1 1 0 0 0 1 0 

```

*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

//using namespace std; // IMPORTANT: Very bad, error prone, way to import a namespace
//                        https://stackoverflow.com/questions/41590/how-do-you-properly-use-namespaces-in-c

//correct way
using std::vector;
using std::string;
using std::endl;
using std::cerr;
using std::ifstream;
using std::cout;


vector<vector<int>> graphM_read(string fname)
 {    
    
    // Read file
    std::ifstream stream_file;
    stream_file.open( fname.c_str() );    
    if( stream_file.fail() ) {
        cerr << "unable to open file " << fname.c_str() << " for reading" << endl;
        exit( 1 );
    }
    
    // Read vertices and edges numbers
    int n_vertices, n_edges;
    stream_file >> n_vertices >> n_edges;
    
    // Initialize adjacency matrix to 0
    vector<vector<int>> M( n_vertices, vector<int> (n_vertices, 0) );
    
    // Fill adjacency matrix
    for( int j=0; j<n_edges; j++ ) {
         int u, v;
         stream_file >> u >> v;
         M[u][v] = 1;
         M[v][u] = 1;
        // previous two lines can be written as: M[u][v] = M[v][u] = 1  
    }    
    stream_file.close( );    

    return M;
}

void cout_adjacency_matrix(vector<vector<int>> M)
{
   int m = M.size();    

    cout << std::setw(7);
    for( int i=0; i<m; i++ )
        cout << i << " ";

    cout << "\n" << std::setw(7);
    for( int i=0; i<m; i++ )
        cout << "-" << " ";
    cout << "\n";

    for( int i=0; i<m; i++ )
    {
        cout << "\n";
        for( int j=0; j<m; j++ ) 
            {
            if (j == 0)
                cout << i <<" |   " << M[i][j] << " ";
            else
                cout << M[i][j] << " ";
        }
    }
    cout << "\n\n";
}

size_t count_edges_given_adjacency_list(graph &G)
{
    size_t n_edges=0

    for (int i=0; i<G.size(); i++)
        for (int j=0; j<G[i].size(); j++)
            n_edges++;

    return n_edges/2
}


int main () 
{
    vector<vector<int>> M;
    string f = "./files/edge_lists/graph8A.in";
    
    M = graphM_read(f);
    cout << "\nGraph read from file: " << f << std::endl;
    int n_vertices = M.size();    
    
    n_edges = count_edges_given_adjacency_list(M)
    cout << "\nNumber of vertices: " << n_vertices  << std::endl;
    cout << "\nNumber of edges: "    << n_edges  << std::endl;

    cout << "\nAdjacency matrix:" << "\n\n";
    cout_adjacency_matrix(M); 
    
    return 0;
}
