//
//	TREE SEARCH IN GRAPHS
//  - BFS method
//  - DFS method
//  - Dijkstra (without weights) method
//
#include "graph.h"
//
//  Breadth First Search: returns components/trees number
//
 component
    BFS( graph &G ) 
{
    vertex vn = G.size();
    component Tn = 0;
    vector<bool> BFSl( vn, false );
	vector<vertex> BFSv( vn );
	index BFSn = 0;
//  Find non labeled vertex as root vertex rv of new component/tree Tn
	for( vertex rv=0; rv<vn; rv++ ) 
		if( !BFSl[rv] ) {
		//  New root rv found for new component
			Tn++;
		//  Label and list rv
			BFSl[rv] = true;
			index BFSi = BFSn;
			BFSv[BFSn++] = rv;
			if( G[rv].size() )
		//  Display new component
			do {
			//  New vertex v to display
				vertex v = BFSv[BFSi++]; 				
				for( index i=0; i<G[v].size(); i++ ) 
				if( !BFSl[G[v][i]] ) {
				//  Label and list adjacent G[v][i]
					BFSl[G[v][i]] = true;
					BFSv[BFSn++] = G[v][i];
				}
           } while( BFSi < BFSn );
        }
     return Tn;
}
//
//  BFS Trees: hierarchical structure (trees) of BFS to stream 
//  - BFS trees of components
//  - classification of edges (in tree / not in tree)
//
 component 
    BFS_Trees( graph &G, ofstream& fout ) 
{
    vertex vn = G.size();
    component Tn = 0;
//  Identifiers, indices, depths and parents of vertices 
    vector<vertex> BFSv( vn );
	vector<index> BFSind( vn );
	vector<length> BFSd( vn );
	vector<vertex> BFSp( vn, vn );
	index BFSn = 0;
	for( vertex rv=0; rv<vn; rv++ ) 
		if( BFSp[rv]==vn ) {
		//  New root vertex r (new component)
			Tn++;
			index BFSi = BFSn;
			BFSv[BFSn] = rv;
			BFSind[rv]=BFSn++;
			BFSd[rv]=0;
			BFSp[rv]=rv;
			if( G[rv].size() )
		//  Display new component
			do {
			//  New vertex v to display	
				vertex v = BFSv[BFSi++]; 				
				for( index i=0; i<G[v].size(); i++ ) 
					if( BFSp[G[v][i]]==vn )	{
						BFSv[BFSn] = G[v][i];
						BFSind[G[v][i]]=BFSn++;
						BFSd[G[v][i]]=BFSd[v]+1;
						BFSp[G[v][i]]=v;
					}
			} while( BFSi < BFSn );
		}
//  List indices, depths and parents
	fout << "\nBFS tree(s)\n";
	fout << "v\tind\t[d]\tp" << endl;
	for( vertex v=0; v<vn; v++ ) 
	   if( BFSp[v] == v )
            fout << v << "\t" << BFSind[v] << endl;
	   else 
			fout << v << "\t" << BFSind[v] << "\t[" << BFSd[v]  << "]\t" << BFSp[v] << endl;
//  List edges and its belonging to trees
    fout << "BFS edges\n";
	for( vertex v=0; v<vn; v++ ) 
		for( index i=0; i<G[v].size(); i++ ) 
			if( v<G[v][i] ) {
				if ( BFSp[G[v][i]] == v || BFSp[v] == G[v][i] ) 
					fout << "Edge " << v << " - " << G[v][i] << " in tree" << endl;
				else
					fout << "Edge " << v << " - " << G[v][i] << " not in tree" << endl;
			}
	return Tn;
}

//
//  Recursive function for Depth First Search from v
//
 void 
    DFS( graph &G, vector<bool> &DFSl, vertex v ) 
{
    for( index i=0; i<G[v].size(); i++ ) 
        if( !DFSl[G[v][i]] ) {
            DFSl[G[v][i]] = true;
            DFS( G, DFSl, G[v][i] );
        }
}
//
//  Depth First Search: returns components/trees number
//
 component 
    DFS( graph &G ) 
{
    vertex vn = G.size();
    component Tn = 0;
    vector<bool> DFSl( vn, false );
//  Find non labeled vertex as root vertex rv of new component/tree Tn
    for( vertex rv=0; rv<vn; rv++) 
        if( !DFSl[rv] ){
			Tn++;
		//  Label and recursive DFS from rv
			DFSl[rv] = true;
            DFS( G, DFSl, rv );
        }
    return Tn;
}
// 
//  Recursive function for finding depht-first spanning tree from v
//  - number DFSn, vertex indices DFSi and predecessors DFSp
//
 void 
    DFS_Trees( graph &G, int &DFSn, vector<index> &DFSind, vector<vertex> &DFSp, vector<length> &DFSd, vertex v ) 
{
    vertex vn = G.size();
    for( index i=0; i<G[v].size(); i++ ) {
         if( DFSp[G[v][i]]==vn ) {
             DFSind[G[v][i]] = DFSn++;
             DFSp[G[v][i]] = v;    			
			 DFSd[G[v][i]] = DFSd[v]+1;    			
             DFS_Trees( G, DFSn, DFSind, DFSp, DFSd, G[v][i] );
         }
    }
}
//
//  DFS Trees: hierarchical structure (trees) of DFS to stream 
//  - DFS trees of cnonents
//  - classification of edges (in tree / not in tree)
//
 component 
    DFS_Trees( graph &G, ofstream& fout ) 
 {
	vertex vn = G.size();
    int Tn = 0;
	int DFSn = 0;
    vector<index> DFSind( vn );
	vector<vertex> DFSp( vn, vn );
	vector<length> DFSd( vn );
//  Find non parented vertex as root vertex rv of new component/tree Tn
	for( vertex rv=0; rv<vn; rv++ ) 
        if( DFSp[rv]==vn ) {
			Tn++;
		//  Index, parent and depth for rv and recursive DFS from rv
			DFSind[rv] = DFSn++;
            DFSp[rv] = rv;    		
			DFSd[rv] = 0;
			DFS_Trees( G, DFSn, DFSind, DFSp, DFSd, rv );
        }
	fout << "\nDFS tree(s)\n";
//  List indices, depths and parents
	fout << "v\tind\t[d]\tp" << endl;
    for( vertex v = 0; v <vn; v++ ) 
        if( DFSp[v] == v )
            fout << v << "\t" << DFSind[v] << endl;
        else
		    fout << v << "\t" << DFSind[v] << "\t[" << DFSd[v]  << "]\t" << DFSp[v] << endl;
//  List edges and its belonging to trees
    fout << "DFS edges\n";
	for( vertex v=0; v<vn; v++ ) 
		for( index i=0; i<G[v].size(); i++ ) 
			if( v<=G[v][i] ) {
				if ( DFSp[G[v][i]] == v || DFSp[v] == G[v][i] ) 
					fout << "Edge " << v << " - " << G[v][i] << " in tree" << endl;
				else
					fout << "Edge " << v << " - " << G[v][i] << " not in tree" << endl;
			}
	return Tn;
 }
 //
//  Minimal path lengths by Dijkstra's method to stream
//  - Distances to all vertices: lengths of minimal paths
//
 void
    Dijkstra( graph &G, vertex sv, ofstream& fout ) 
{
    vertex vn = G.size();
//  Inialize vertices as unlabeled
    vector<bool> Dl( vn, false );
//  Infinity for lengths
	length infty = UINT_MAX;
//  Inialitize distance to sv to infty for all vertices but sv
	vector<length> Dd( vn, infty );
	Dd[sv]=0;
//  Vertex mdv with minimum distance to starting vertex sv: sv
	vertex mdv = sv; 
	do {
	//  Label mdv and check distance from sv to its adjacents	
		Dl[mdv] = 1;
		for( index i=0; i<G[mdv].size(); i++ ) 
			if( Dd[G[mdv][i]] > Dd[mdv]+1 )	
				Dd[G[mdv][i]] = Dd[mdv]+1; 
	//  Find new not labeled vertex mdv with minimum distance to sv
		length md = infty;
		mdv = vn;
		for( vertex v=0; v<vn; v++ )
			if( md > Dd[v] && !Dl[v] ) {
				md = Dd[v];
				mdv = v;
			}
	} while( mdv<vn );
    fout << "\nDistances from starting vertex " << sv << endl;
	for( vertex v=0; v<vn; v++ )
        if( Dd[v]<infty )
		    fout << v << "\t" << Dd[v]  << endl;
        else
            fout << v << "\tNot connected" << endl;
}
//
//  Minimum path lengths by Dijkstra's method to stream
//  - Minimum lengts to all vertices
//
 void
    Dijkstra2( graph &G, index n1, index n2, index s1, index s2,  ofstream& fout ) 
{
    vertex vn = G.size();
    vertex sv = s1*n2+s2;
//  Inialize vertices as unlabeled
    vector<bool> Dl( vn, false );
//  Infinity for lengths
	length infty = UINT_MAX;
//  Inialitize distance to sv to infty for all vertices but sv
	vector<length> Dd( vn, infty );
	Dd[sv]=0;
//  Vertex mdv with minimum distance to starting vertex sv: sv
	vertex mdv = sv; 
	do {
	//  Label mdv and check distance from sv to its adjacents	
		Dl[mdv] = 1;
		for( index i=0; i<G[mdv].size(); i++ ) 
			if( Dd[G[mdv][i]] > Dd[mdv]+1 )	
				Dd[G[mdv][i]] = Dd[mdv]+1; 
	//  Find new not labeled vertex mdv with minimum distance md to sv
		length md = infty;
		mdv = vn;
		for( vertex v=0; v<vn; v++ )
			if( md > Dd[v] && !Dl[v] ) {
				md = Dd[v];
				mdv = v;
			}
	} while( mdv<vn );
    fout << "\nDistances to vertex (" << s1 << ", " << s2 << ")";
	for( vertex v=0; v<vn; v++ ) {
		if( !(v%n2) ) 
			fout << endl;
        if( Dd[v]<infty )
		    fout << "\t" << Dd[v];
        else
            fout << "\t" << "N" ;
	}
}
//
//  Minimal paths by Dijkstra's method to stream
//  - Dijkstra tree rooted in s
//  - Minimal paths from s
//
 void
    DijkstraTree( graph &G, vertex sv, ofstream& fout ) 
{
    vertex vn = G.size();
    index cn = 0;
//  Infinity for lengths
    length infty = UINT_MAX;
    vector<bool> Dl( vn, false );
//  Inialitize distance to sv to infty for all vertices but sv	
    vector<length> Dd( vn, infty );
	vector<vertex> Dp( vn, vn );
//  Vertex mdv with minimum distance to starting vertex sv: sv
	vertex mdv = sv; 
	Dd[sv]=0;
	Dl[sv] = true;
	Dp[sv] = sv;
	do {
	//  Label mdv and check distance from sv to its adjacents	
		Dl[mdv] = 1;
		for( index i=0; i<G[mdv].size(); i++ ) 
			if( Dd[G[mdv][i]] > Dd[mdv]+1 )	{
				Dd[G[mdv][i]] = Dd[mdv]+1; 
				Dp[G[mdv][i]] = mdv;
			}
	//  Find new not labeled vertex mdv with minimum distance md to sv
		length md = infty;
		mdv = vn;
		for( vertex v=0; v<vn; v++ )
			if( md > Dd[v] && !Dl[v] ) {
				md = Dd[v];
				mdv = v;
			}
	} while( mdv<vn );
  	fout << "\nDijkstra tree [distances] parents\n";
    for( vertex v=0; v<vn; v++ ) 
        if( Dp[v]==v )
            fout << v << "\t[" << Dd[v] << "]" << endl;
        else if( Dp[v] != vn )
		    fout << v << "\t[" << Dd[v] << "]\t" << Dp[v] << endl;
    fout << "Dijkstra paths\n";
	for( vertex v=0; v<vn; v++ ) {
        if( Dd[v]==infty )
		    fout << v << "\tNot connected" ;
        else {
		vertex pv = v;
		fout << pv;
		if( Dp[pv]<vn )
			while( Dp[pv]!=pv ) {
				pv = Dp[pv];
				fout << " <- " << pv;
			}
		else
			fout << " x ";
        }
        fout << endl;
	}
}
