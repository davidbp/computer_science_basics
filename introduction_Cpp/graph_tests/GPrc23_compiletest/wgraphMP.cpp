//
//	MINIMAL PATHS IN WEIGHTED GRAPHS
//  - Dijkstra method
//
#include "wgraph.h"
//
//	Dijkstra method: returns distance from sv to tv
//
 weight
    Dijkstra( wgraph &G, vertex sv, vertex tv ) 
{
    vertex vn = G.size();
    weight infty = UINT_MAX;
    vector<weight> Dd( vn, infty );
    Dd[sv] = 0;
    vector<bool> Dl( vn, false );
    vertex mdv = sv; 
	do {
		Dl[mdv] = true;
		for( index i=0; i<G[mdv].size(); i++ ) 
			if( Dd[G[mdv][i].first] > Dd[mdv]+G[mdv][i].second )	
				Dd[G[mdv][i].first] = Dd[mdv]+G[mdv][i].second; 
		weight md = infty;
		mdv = vn;
		for( vertex v=0; v<G.size(); v++ )
			if( md > Dd[v] && !Dl[v] ) {
				 md = Dd[v];
				mdv = v;
			}
	} while( mdv!=vn && mdv!=tv );
	return Dd[tv];
 }
//
//	Dijkstra method: returns maximum distance from sv
//
 weight
    Dijkstra( wgraph &G, vertex sv ) 
{
    vertex vn = G.size();
	weight infty = UINT_MAX; 
	vector<weight> Dd( vn, infty );
    Dd[sv]=0;
    vector<bool> Dl( vn, false );
    vertex mdv = sv; 
	do {
		Dl[mdv] = true;
		for( index i=0; i<G[mdv].size(); i++ ) 
			if( Dd[G[mdv][i].first] > Dd[mdv]+G[mdv][i].second )	
				Dd[G[mdv][i].first] = Dd[mdv]+G[mdv][i].second; 
		weight md = infty;
		mdv = vn;
		for( vertex v=0; v<G.size(); v++ )
			if( md > Dd[v] && !Dl[v] ) {
				md = Dd[v];
				mdv = v;
			}
	} while( mdv!=vn );
	weight Md = 0;
	for (vertex v = 0; v < vn; v++) {
		if (Md < Dd[v])
			Md = Dd[v];
		if (Md == infty)
			break;
	}
	return Md;
 }
 //
 //	Diameter: returns maximum minimum distance between vertices pairs
 //
  weight
    Diameter( wgraph &G ) 
 {
	weight infty = UINT_MAX;
	weight D=0;
	for( vertex sv=0; sv<G.size(); sv++ ) {
		weight Mmd = Dijkstra( G, sv );
		if( D < Mmd )
			D = Mmd;
		if (D == infty)
			break;
	}
	return D;
 }
//
//	Dijkstra method: writes minimum distances from s to fout
//
 void
    Dijkstra( wgraph &G, vertex sv, ofstream& fout ) 
{
    vertex vn = G.size();
    weight infty = 1;
    for( vertex v=0; v<G.size(); v++ )
        for( index i=0; i<G[v].size(); i++ ) 
            if( v < G[v][i].first )
                infty += G[v][i].second;
    vector<weight> Dd( vn, infty );
    Dd[sv] = 0;
    vector<bool> Dl( vn, false );
    vertex mdv = sv; 
	do {
		Dl[mdv] = true;
		for( index i=0; i<G[mdv].size(); i++ ) 
			if( Dd[G[mdv][i].first] > Dd[mdv]+G[mdv][i].second )	
				Dd[G[mdv][i].first] = Dd[mdv]+G[mdv][i].second; 
		weight md = infty;
		mdv = vn;
		for( vertex v=0; v<G.size(); v++ )
			if( md > Dd[v] && !Dl[v] ) {
				md = Dd[v];
				mdv = v;
			}
	} while( mdv!=vn );
	fout << "\nDijkstra distances\n";
	for( vertex v = 0; v < G.size(); v++ ) {
		if( Dd[v]==infty )
		    fout << v << "\tNot connected" ;
		else
			fout << v << "\t" << Dd[v];
		fout << endl;
	}
}
//
//	DijkstraTree: writes Dijkstra trees and minimal paths from s to fout
//
 void
    DijkstraTree( wgraph &G, vertex sv, ofstream& fout ) 
{
    vertex vn = G.size();
    weight infty = 1;
    for( vertex v=0; v<vn; v++ )
        for( index i=0; i<G[v].size(); i++ ) 
            if( v < G[v][i].first )
                infty += G[v][i].second;
    vector<weight> Dd( vn, infty );
    Dd[sv]=0;
    vector<bool> Dl( vn, false );
    vector<vertex> Dp( vn, vn );
    Dp[sv] = sv;
	int mdv = sv; 
	do {
		Dl[mdv] = true;
		for( int i=0; i<int(G[mdv].size()); i++ ) 
			if( Dd[G[mdv][i].first] > Dd[mdv]+G[mdv][i].second )	{
				Dd[G[mdv][i].first] = Dd[mdv]+G[mdv][i].second; 
				Dp[G[mdv][i].first] = mdv;
			}
		weight md = infty;
		mdv = vn;
		for( vertex v=0; v<vn; v++ )
			if( md > Dd[v] && !Dl[v] ) {
				md = Dd[v];
				mdv = v;
			}
	} while( mdv!=vn );

  	fout << "\nDijkstra tree\n";
    for( vertex v = 0; v <vn; v++ ) 
        if( Dp[v] == v )
            fout << v << "[" << Dd[v] << "]" << endl;
        else if( Dp[v] != vn )
		    fout << v << "[" << Dd[v] << "]\t" << Dp[v] << endl;

    fout << "Dijkstra paths\n";
	for( vertex v = 0; v < G.size(); v++ ) {
        if( Dd[v]==infty )
		    fout << v << "\tNot connected" ;
        else {
			vertex pv = v;
			fout << pv;
			while( Dp[pv] != pv ) {
				pv = Dp[pv];
				fout << " <- " << pv;
			}
        }
        fout << endl;
	}
	fout << endl;
	fout << endl;
}