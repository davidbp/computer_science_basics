
/*
#### Compilation code
c++ -std=c++11 4_read_edges_graph_write.cpp  -o 4_read_edges_graph_write.out


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



// 
//  Read from file fname of edges to adjacencies lists (graph): G
//
graph graph_read( string fname )
{    
    ifstream fin;
    fin.open( fname.c_str() );    
    if( fin.fail() ) {
       cerr << "unable to open file " << fname.c_str() << " for reading" << endl;
        exit( 1 );
    }
    size_t vn;
    size_t en;
    
    fin >> vn >> en;
    graph G( vn );
    for(size_t e=0; e<en; e++ ) {
         size_t v, u;
         fin >> v >> u; 
         G[v].push_back(u);
         if( u != v ) 
             G[u].push_back(v);
    }    
    return G;
}

void graph_write(graph G, std::ofstream &fout )
{    
    
    //  Vertices number 
    size_t vn = G.size();
    
    //  Count edges number from adjacencies lists
    size_t en = 0; 
    for (size_t v = 0; v < vn; v++)
        for (size_t i = 0; i < G[v].size(); i++)
            if (v <= G[v][i])
                en++;
    
    //  Write edges         
    fout << "Graph with " << vn << " vertices and " << en << " edges " << endl;
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
    string f_write = "./results/4_read_edges_graph_write.txt";

    G = graph_read(f_read);
    cout << "\nGraph read from file: " << f_read << endl;
    int n_vertices = G.size();    
    
    ofstream fout;
    fout.open(f_write);    
    graph_write( G, fout );
    fout.close();
    cout << "\nGraph information written to: " << f_write << "\n\n";

    return 0;
}
