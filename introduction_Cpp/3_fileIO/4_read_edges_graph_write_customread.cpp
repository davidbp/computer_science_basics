
/*
#### Compilation code
c++ -std=c++11 4_read_edges_graph_write_customread.cpp  -o 4_read_edges_graph_write_customread.out


#### Program description
This code reads an adjacency list graph from a file and plots 

- The number of edges
- the adjacency matrix


#### Output of the program
```
Graph read from file: ./files/edge_lists/graph8A.in

Graph information written to: ./results/4_read_edges_graph_write.txt

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
using std::cout;
using std::ifstream;
using std::ofstream;

typedef vector<vector<int>> graph;


vector<vector<int>> graphM_read(string fname)
 {    
    
    // Read file
    ifstream stream_file;
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
         M[u][v] = M[v][u] = 1;
         //M[u][v] = 1;
         //M[v][u] = 1;
        // previous two lines can be written as: M[u][v] = M[v][u] = 1  
    }
    stream_file.close( );    

    return M;
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



void graph_write(graph G, std::ofstream &fout )
{    
    
    //  Vertices number 
    size_t vn = G.size();
    
    //  Count edges number from adjacencies lists
    size_t n_edges;
    n_edges = count_edges_given_adjacency_list(G);
    
    //  Write edges         
    fout << "Graph with " << vn << " vertices and " << n_edges << " edges " << endl;
    fout << "\nAdjacencies lists" << endl;
    for( size_t v=0; v<vn; v++ )  {
        fout << v << "\t:";
        for( size_t i=0; i<G[v].size(); i++) 
            fout << "\t" << G[v][i];
        fout << endl;
    }
    fout << "\nEdges" << endl;
    for(size_t v = 0; v < vn; v++ ) 
        for(size_t i = 0; i < G[v].size(); i++ ) 
            if( v <= G[v][i] )
                fout << v << "-" << G[v][i] << endl;
    
    //  Count degrees
    vector<size_t> deg( vn );
    for(size_t v = 0; v < vn; v++ ) 
         deg[v] = G[v].size();
    
    //  Write degrees sequence
    fout << "\nDegrees sequence" << endl;
    for(size_t v = 0; v < vn; v++ ) 
        fout << deg[v] << " ";
    fout << endl;
    
    //  Sort degrees sequence
    sort(deg.begin(), deg.end());
    
    //  Write sorted degrees sequence
    fout << "\nSorted degrees sequence" << endl;
    for(size_t v = 0; v < vn; v++ ) 
        fout << deg[v] << " ";
    fout << endl;
}


int main () 
{
    vector<vector<int>> G;
    string f_read = "./files/edge_lists/graph3.in";
    string f_write = "./results/4_read_edges_graph_write_customread.txt";

    G = graphM_read(f_read);
    cout << "\nGraph read from file: " << f_read << endl;
    int n_vertices = G.size();    
    
    cout << "\nGraph has n_vertices: " << n_vertices << endl;

    ofstream fout;
    fout.open(f_write);    
    graph_write( G, fout );
    fout.close();
    cout << "\nGraph information written to: " << f_write << "\n\n";

    return 0;
}
