#include "graph.h"
// 
//  Complete graph with n vertices to adjacencies lists (graph): Kn
//
 graph
    graph_complete( index n )
{    
    graph Kn( n );
    for( vertex v=0; v<n; v++) 
        for( vertex u=v+1; u<n; u++ ) {
             Kn[v].push_back( u );
             Kn[u].push_back( v );
        } 
    return Kn;
}
// 
//  Bipartite complete graph with (n1,n2) vertices to adjacencies lists (graph): Kn1n2
//
 graph
    graph_bipartite_complete( index n1, index n2 )
{    
    graph Kn1n2( n1+n2 );
    for( vertex v1=0; v1<n1; v1++) 
        for( vertex v2=n1; v2<n1+n2; v2++ ) {
             Kn1n2[v1].push_back( v2 );
             Kn1n2[v2].push_back( v1 );
        } 
    return Kn1n2;
}
// 
//  Cycle graph with n vertices to adjacencies lists (graph): Cn
//
 graph
    graph_cycle( index n )
{    
    graph Cn( n );
	for( vertex v=0; v<n-1; v++)  {
         Cn[v].push_back( v+1 );
         Cn[v+1].push_back( v );
    } 
	Cn[n-1].push_back( 0 );
    Cn[0].push_back( n-1 );
    return Cn;
}
// 
//  Star graph with n peripherial vertices to adjacencies lists (graph): : Sn
//
 graph
    graph_star( index n )
{    
    graph Sn( n+1 );
	for( vertex v=0; v<n; v++)  {
         Sn[v].push_back( n );
         Sn[n].push_back( v );
    } 
	return Sn;
}
// 
//  Wheel graph with n peripherial vertices to adjacencies lists (graph): Wn
//
 graph
    graph_wheel( index n )
{    
    graph Wn( n+1 );
	for( vertex v=0; v<n-1; v++)  {
         Wn[v].push_back( v+1 );
         Wn[v+1].push_back( v );
    } 
	Wn[n-1].push_back( 0 );
    Wn[0].push_back( n-1 );
	for( vertex v=0; v<n; v++)  {
         Wn[v].push_back( n );
         Wn[n].push_back( v );
    } 
	return Wn;
}
// 
//  King graph in n1xn2 chessboard: Kgn1n2
//
 graph
    graph_king( index n1, index n2 )
{    
    graph Kgn1n2( n1*n2 );
    for( index i1=0; i1<n1; i1++) 
        for( index i2=0; i2<n2; i2++ ) {
			vertex v= i1*n2+i2;
			if( i2<n2-1 ) {
				Kgn1n2[v].push_back( v+1 );
				Kgn1n2[v+1].push_back( v );
			}
			if( i1<n1-1 ) {
				Kgn1n2[v].push_back( v+n2 );
				Kgn1n2[v+n2].push_back( v );
			}
			if( i1<n1-1 && i2<n2-1 ) {
				Kgn1n2[v].push_back( v+n2+1 );
				Kgn1n2[v+n2+1].push_back( v );
			}
			if( i1<n1-1 && i2>0 ) {
				Kgn1n2[v].push_back( v+n2-1 );
				Kgn1n2[v+n2-1].push_back( v );
			}
        } 
    return Kgn1n2;
}
// 
//  Knight graph in n1xn2 chessboard: Ktn1n2
//
 graph
    graph_knight( index n1, index n2 )
{    
    graph Ktn1n2( n1*n2 );
    for( index i1=0; i1<n1; i1++) 
        for( index i2=0; i2<n2; i2++ ) {
			vertex v = i1*n2+i2;
			if( i1<n1-1 && i2<n2-2 ) {
				Ktn1n2[v].push_back( v+n2+2 );
				Ktn1n2[v+n2+2].push_back( v );
			}
			if( i1<n1-1 && i2>1 ) {
				Ktn1n2[v].push_back( v+n2-2 );
				Ktn1n2[v+n2-2].push_back( v );
			}
			if( i1<n1-2 && i2>0 ) {
				Ktn1n2[v].push_back( v+2*n2-1 );
				Ktn1n2[v+2*n2-1].push_back( v );
			}
			if( i1<n1-2 && i2<n2-1 ) {
				Ktn1n2[v].push_back( v+2*n2+1 );
				Ktn1n2[v+2*n2+1].push_back( v );
			}
        } 
    return Ktn1n2;
}
// 
//  Rook graph in n1xn2 chessboard: Rkn1n2
//
 graph
    graph_rook( index n1, index n2 )
{    
    graph Rkn1n2( n1*n2 );
    for( index i1=0; i1<n1; i1++) 
        for( index i2=0; i2<n2; i2++ ) {
			vertex v = i1*n2+i2;
			for( index k=1; i2+k<n2; k++  ) {
				Rkn1n2[v].push_back( v+k );
				Rkn1n2[v+k].push_back( v );
			}
			for( index k=1; i1+k<n1; k++  ) {
				Rkn1n2[v].push_back( v+k*n2 );
				Rkn1n2[v+k*n2].push_back( v );
			}
        } 
    return Rkn1n2;
}
// 
//  Bishop graph in n1xn2 chessboard: Bpn1n2
//
 graph
    graph_bishop( index n1, index n2 )
{    
    graph Bpn1n2( n1*n2 );
    for( index i1=0; i1<n1; i1++) 
        for( index i2=0; i2<n2; i2++ ) {
			vertex v= i1*n2+i2;
			for( index k=1; i1+k<n1 && i2+k<n2; k++ ) {
				Bpn1n2[v].push_back( v+k*n2+k );
				Bpn1n2[v+k*n2+k].push_back( v );
			}
			for( index k=1; i1+k<n1 && i2>=k; k++ ) {
				Bpn1n2[v].push_back( v+k*n2-k );
				Bpn1n2[v+k*n2-k].push_back( v );
			}
        } 
    return Bpn1n2;
}
// 
//  Read from file fname of edges to adjacencies lists (graph): G
//
 graph 
	graph_read( string fname )
{    
	ifstream fin;
    fin.open( fname.c_str() );    
    if( fin.fail() ) {
       cerr << "unable to open file " << fname.c_str() << " for reading" << endl;
        exit( 1 );
    }
 	vertex vn;
    edge en;
	fin >> vn >> en;
	graph G( vn );
    for( edge e=0; e<en; e++ ) {
         vertex v, u;
         fin >> v >> u; 
         G[v].push_back(u);
         if( u != v ) 
             G[u].push_back(v);
	}    
    return G;
}
// 
//  Write from adjacencies lists (graph) to stream
//  - vertices and edges numbers
//  - edges
//  - degrees and sorted degrees
  void 
	graph_write( graph& G, ofstream& fout )
{    
//  Vertices number 
	vertex vn = G.size();
//  Count edges number from adjacencies lists
    edge en = 0; 
	for (vertex v = 0; v < vn; v++)
		for (index i = 0; i < G[v].size(); i++)
			if (v <= G[v][i])
				en++;
//  Write edges         
    fout << "Graph with " << vn << " vertices and " << en << " edges " << endl;
    fout << "Adjacencies lists" << endl;
    for( vertex v=0; v<vn; v++ )  {
		fout << v << "\t:";
        for( index i=0; i<G[v].size(); i++) 
            fout << "\t" << G[v][i];
        fout << endl;
    }
    fout << "Edges" << endl;
    for( vertex v = 0; v < vn; v++ ) 
        for( index i = 0; i < G[v].size(); i++ ) 
            if( v <= G[v][i] )
                fout << v << "-" << G[v][i] << endl;
//  Count degrees
    vector<degree> deg( vn );
    for( index v = 0; v < vn; v++ ) 
         deg[v] = G[v].size();
//  Write degrees sequence
    fout << "Degrees sequence" << endl;
    for( vertex v = 0; v < vn; v++ ) 
        fout << deg[v] << " ";
    fout << endl;
//  Sort degrees sequence
    sort( deg.begin(), deg.end() );
//  Write sorted degrees sequence
    fout << "Sorted degrees sequence" << endl;
    for( vertex v = 0; v < vn; v++ ) 
        fout << deg[v] << " ";
    fout << endl;
}
// 
//  Write from adjacencies lists (graph) to stream
//  - vertices and edges numbers
//  - edges
//  - degrees and sorted degrees
  void 
	graph_write2( graph& G, index n1, index n2, ofstream& fout )
{    
//  Vertices number 
	vertex vn = G.size();
//  Count edges number from adjacencies lists
	edge en = 0;
	for (vertex v = 0; v < vn; v++)
		for (index i = 0; i < G[v].size(); i++)
			if (v <= G[v][i])
				en++;
//  Write edges         
    fout << "Graph with " << vn << " vertices and " << en << " edges " << endl;
    fout << "Adjacencies lists" << endl;
    for( vertex v=0; v<vn; v++ )  {
		fout << "(" << v/n2 << "," << v%n2 << ") \t:\t";
        for( index i=0; i<G[v].size(); i++) 
			fout << "(" << G[v][i]/n2 << "," << G[v][i]%n2 << ") \t";
         fout << endl;
    }
    fout << "Edges" << endl;
    for( vertex v = 0; v < vn; v++ ) 
        for( index i = 0; i < G[v].size(); i++ ) 
            if( v <= G[v][i] )
                fout << "(" << v/n2 << "," << v%n2 << ")" << "-" << "(" << G[v][i]/n2 << "," << G[v][i]%n2 << ")"  << endl;
//  Count degrees
    vector<degree> deg( vn );
    for( index v = 0; v < vn; v++ ) 
         deg[v] = G[v].size();
//  Write degrees sequence
    fout << "Degrees matrix";
	for( vertex v = 0; v < vn; v++ )  {
		if( !(v%n2) )
			fout << endl;
		fout << deg[v] << "\t";
	}
    fout << endl;
}