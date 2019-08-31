#include "wgraph.h"
// 
//  Weighted complete graph with n vertices and random weights up to Mw 
//  to weighted adjacencies lists (wgraph): WKn
//
 wgraph
    wgraph_complete( vertex n, weight Mw )
 {    
    wgraph WKn( n );
    for( vertex v = 0; v < n; v++ ) 
        for( vertex u = v+1; u<n; u++ ) {
			weight w = rand()%Mw+1;
			WKn[v].push_back(pair<vertex,weight>(u,w));
			WKn[u].push_back(pair<vertex,weight>(v,w));
        }
    return WKn;
}
// 
//  Weighted bipartite complete graph with (n1,n2) vertices and random weights up to Mw 
//  to weighted adjacencies lists (wgraph): WKn1n2
//
 wgraph
    wgraph_bipartite_complete( vertex n1, vertex n2, weight Mw )
 {    
    wgraph WKn1n2( n1+n2 );
    for( vertex v1 = 0; v1 < n1; v1++ ) 
        for( vertex v2 = n1; v2<n1+n2; v2++ ) {
			weight w = rand()%Mw+1;
			WKn1n2[v1].push_back(pair<vertex,weight>(v2,w));
			WKn1n2[v2].push_back(pair<vertex,weight>(v1,w));
        }
    return WKn1n2;
}
// 
//  Weighted cycle graph with n vertices and random weights up to Mw 
//  to weighted adjacencies lists (wgraph): WCn
//
 wgraph
    wgraph_cycle( vertex n, weight Mw )
 {    
    wgraph WCn( n );
	for( vertex v = 0; v < n-1; v++ ) {
        weight w = rand()%Mw+1;
		WCn[v].push_back(pair<vertex,weight>(v+1,w));
		WCn[v+1].push_back(pair<vertex,weight>(v,w));
    }
	weight w = rand()%Mw+1;
    WCn[n-1].push_back(pair<vertex,weight>(0,w));
	WCn[0].push_back(pair<vertex,weight>(n-1,w));
    return WCn;
}
// 
//  Weighted star graph with n peripherial vertices and random weights up to Mw 
//  to weighted adjacencies lists (wgraph): WWn
//
 wgraph
    wgraph_star( vertex n, weight Mw )
 {    
    wgraph WSn( n+1 );
	for( vertex v = 0; v < n; v++ ) {
        weight w = rand()%Mw+1;
		WSn[v].push_back(pair<vertex,weight>(n,w));
		WSn[n].push_back(pair<vertex,weight>(v,w));
    }
    return WSn;
}

// 
//  Weighted wheel graph with n peripherial vertices and random weights up to Mw 
//  to weighted adjacencies lists (wgraph): WWn
//
 wgraph
    wgraph_wheel( vertex n, weight Mw )
 {    
    wgraph WWn( n+1 );
	for( vertex v = 0; v < n; v++ ) {
        weight w = rand()%Mw+1;
		WWn[v].push_back(pair<vertex,weight>(n,w));
		WWn[n].push_back(pair<vertex,weight>(v,w));
    }
	for( vertex v = 0; v < n-1; v++ ) {
        weight w = rand()%Mw+1;
		WWn[v].push_back(pair<vertex,weight>(v+1,w));
		WWn[v+1].push_back(pair<vertex,weight>(v,w));
    }
	weight w = rand()%Mw+1;
    WWn[n-1].push_back(pair<vertex,weight>(0,w));
	WWn[0].push_back(pair<vertex,weight>(n-1,w));
    return WWn;
}
// 
//  Read from file fname of weighted edges to weighted adjacencies lists
//
 wgraph
	wgraph_read( string fname )
 {    
	ifstream fin;
    fin.open(fname.c_str());    
    if (fin.fail()) {
        cerr << "unable to open file " << fname.c_str() << " for reading" << endl;
        exit(1);
    }
 	vertex vn;
    edge en;
	fin >> vn >> en;
	wgraph G( vn );
    for( edge e=0; e<en; e++ ) {
        vertex u, v;
        weight w;
        fin >> u >> v >> w; 
        G[u].push_back(pair<vertex,weight>(v,w));
        if( u != v ) 
            G[v].push_back(pair<vertex,weight>(u,w));
    }    
    return G;
}
// 
//  Write from weighted adjacencies lists (wgraph) to stream
//  - vertices and edges numbers
//  - weighted edges
//  - degrees and sorted degrees
  void 
	wgraph_write( wgraph& G, ofstream& fout )
 {    
//  Vertices number 
	vertex vn = G.size();
//  Count edges number from adajacency matrix
    edge en = 0; 
    for( vertex v = 0; v < vn; v++) 
         en += G[v].size();
    en /= 2;
//  Write edges         
    fout << "WGraph with " << vn << " vertices and " << en << " edges " << endl;
    fout << "Weighted adjacency lists" << endl;
//  Allocate/read weighted adjacent pairs
    for( vertex v = 0; v < vn; v++ ) {
        fout << v << ":";
        for( index i = 0; i < G[v].size(); i++)  
            fout << " " << G[v][i].first << "[" << G[v][i].second << "] ";
        fout << endl;
    }
    fout << endl;
    fout << "Weighted edges" << endl;
    for( vertex v = 0; v < vn; v++ ) 
        for( index i = 0; i < G[v].size(); i++) 
            if( v <= G[v][i].first )
                fout << v << "-" << G[v][i].first <<  "[" << G[v][i].second << "] " << endl;
//  Count degrees 
    vector<degree> deg( vn );
    for( vertex v = 0; v < vn; v++ ) 
         deg[v] = G[v].size();
//  Write sorted degrees sequence
    fout << "Degrees sequence" << endl;
    for( vertex v = 0; v < vn; v++) 
        fout << deg[v] << " ";
    fout << endl;
//  Sort degrees sequence from begining position to ending position
    sort( deg.begin(), deg.end() );
//  Write sorted degrees sequence
    fout << "Sorted degrees sequence" << endl;
    for( vertex v = 0; v < vn; v++) 
        fout << deg[v] << " ";
    fout << endl;
 }
