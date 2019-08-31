
/*
#### Compilation code
c++ -std=c++11 3_read_edges_plot_adjacency_matrix.cpp  -o 3_read_edges_plot_adjacency_matrix.out


#### Program description
This code reads an adjacency list graph from a file and plots 

- The number of vertices
- The number of edges
- The adjacency matrix


#### TODO
In the thid example te number of vertices is computed incorrectly from the adjacency list
- Make the function usable in all cases :)  


#### Output of the program for "./files/edge_lists/graph1.in"
```
--------------------------------------------------------------------- 

Graph read from file: ./files/edge_lists/graph1.in

Number of vertices: 4

Number of edges: 7

Adjacency matrix:

      0 1 2 3 
      - - - - 

0 |   0 1 0 1 
1 |   1 0 1 1 
2 |   0 1 1 0 
3 |   1 1 0 0 


---------------------------------------------------------------------

Graph read from file: ./files/edge_lists/graph2.in

Number of vertices: 4

Number of edges: 7

Adjacency matrix:

      0 1 2 3 
      - - - - 

0 |   0 1 0 1 
1 |   1 0 1 1 
2 |   0 1 1 0 
3 |   1 1 0 0 


---------------------------------------------------------------------

Graph read from file: ./files/edge_lists/graph3.in

Number of vertices: 4

Number of edges: 6

Adjacency matrix:

      0 1 2 3 
      - - - - 

0 |   0 1 1 0 
1 |   1 0 1 0 
2 |   1 1 0 1 
3 |   0 0 1 1 
```

#### About the inputs
```
graph1.in  graph2.in   graph3.in 
  4 7        4 7         4 7
  0 1        1 0         1 2
  1 2        2 1         2 3
  0 3        2 1         1 0
  1 2        2 1         2 3
  1 2        2 2         2 3
  2 2        3 0         3 3
  3 1        3 1         0 2

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


vector<vector<int>> read_adjacency_list_from_file(string fname)
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
    for( int j=0; j<n_edges+1; j++ ) {
         int u, v;
         stream_file >> u >> v;
         M[u][v] = M[v][u] = 1 ;
         //M[u][v] = 1;
         //M[v][u] = 1;
         // previous two lines can be written as: M[u][v] = M[v][u] = 1 ; 
    }    
    stream_file.close( );    

    return M;
}

void cout_adjacency_matrix(vector<vector<int>> edge_list)
{
    int m = edge_list.size();    

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
                cout << i <<" |   " << edge_list[i][j] << " ";
            else
                cout << edge_list[i][j] << " ";
        }
    }
    cout << "\n\n";
}

size_t count_edges_given_adjacency_list(vector<vector<int>>  G)
{
    size_t n_edges=0;

    for (int v=0; v<G.size(); v++)
        for (int i=0; i<G[v].size(); i++)
            if (v <= G[v][i])
                 n_edges++;

    return n_edges;
}


int main () 
{
    // First graph
    cout << "\n--------------------------------------------------------------------- " << std::endl;
    vector<vector<int>> M;
    string f = "./files/edge_lists/graph1.in";
    M = read_adjacency_list_from_file(f);
    int n_vertices = M.size();    
    int n_edges;
    cout << "\nGraph read from file: " << f << std::endl;

    n_edges = count_edges_given_adjacency_list(M);
    cout << "\nNumber of vertices: " << n_vertices  << std::endl;
    cout << "\nNumber of edges: "    << n_edges     << std::endl;
    cout << "\nAdjacency matrix:" << "\n\n";
    cout_adjacency_matrix(M); 


    // Second graph
    cout << "\n--------------------------------------------------------------------- " << std::endl;
    vector<vector<int>> M2;
    string f2 = "./files/edge_lists/graph2.in";
    M2 = read_adjacency_list_from_file(f2);
    int n_vertices2 = M2.size();    
    int n_edges2;
    cout << "\nGraph read from file: " << f2 << std::endl;

    n_edges2 = count_edges_given_adjacency_list(M2);
    cout << "\nNumber of vertices: " << n_vertices2  << std::endl;
    cout << "\nNumber of edges: "    << n_edges2     << std::endl;
    cout << "\nAdjacency matrix:" << "\n\n";
    cout_adjacency_matrix(M2); 


    // Third graph
    cout << "\n--------------------------------------------------------------------- " << std::endl;
    vector<vector<int>> M3;
    string f3 = "./files/edge_lists/graph3.in";
    M3 = read_adjacency_list_from_file(f3);
    int n_vertices3 = M3.size();    
    int n_edges3;
    cout << "\nGraph read from file: " << f3 << std::endl;

    n_edges3 = count_edges_given_adjacency_list(M3);
    cout << "\nNumber of vertices: " << n_vertices3  << std::endl;
    cout << "\nNumber of edges: "    << n_edges3     << std::endl;
    cout << "\nAdjacency matrix:" << "\n\n";
    cout_adjacency_matrix(M3); 
    
    
    return 0;
}
