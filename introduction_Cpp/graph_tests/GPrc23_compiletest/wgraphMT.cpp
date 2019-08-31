
//	MINIMAL TREES IN WEIGHTED GRAPHS
//  - Kruskal method
//  - Prim method
//

#include <limits.h>
#include "wgraph.h"
//
//	KruskalTree: writes minimal trees by Kruskal to fout
//
 weight
    KruskalTrees( wgraph &G, ofstream& fout ) 
{
    vertex vn = G.size();
//  Infty weight 
    weight infty = UINT_MAX;
//  Initialize different Kruskal components numbers
    vector<component> Kc( vn );
	for( vertex v=0; v<vn; v++ )
		Kc[v] = v;
//  Initialize tree weights to 0
	vector<weight> Kw( vn, 0 );
	weight mw;
//  Initialize total trees weight
	weight Tw = 0;
    do {
		vertex mv;
		index mvi; 
	//  Find minimum weight edge between vertices in different components	
		mw = infty;
		for( vertex v=0; v<vn; v++ )
			for( index i=0; i<G[v].size(); i++ ) 	
				if( Kc[G[v][i].first] != Kc[v] && mw > G[v][i].second ) {
					mw = G[v][i].second;
					mv = v;
					mvi = i;
				}
		if( mw==infty ) 
            break;
	//  Write new edge as in trees and merge components to minimum value
        vertex mva = G[mv][mvi].first;
		fout << "Kruskal edge: " << mv << " - " << mva <<  " (" << mvi<< ")" <<  " [" << mw << "]\n";
		Tw += mw;
		component mKc = min( Kc[mv], Kc[mva] ), MKc = max( Kc[mv], Kc[mva] ); 
		for( vertex v=0; v<vn; v++ ) 
			if( Kc[v] == MKc )
				Kc[v] = mKc;
		Kw[mKc] += Kw[MKc]+mw;
		Kw[MKc] = 0;
    } while( true );
	for( vertex v=0; v<vn; v++ ) {
		if( Kc[v]==v ) {
			fout << "Component " << v << " of weight " << Kw[v] << ", vertices: ";
			for( vertex u=0; u<vn; u++ )
				if( Kc[u] == v )
					fout << "\t" << u;
			fout << endl;
		}
	}
	fout << "Total weight :" << Tw << endl;
	return Tw;
}
//
//	PrimTree: writes minimal trees by Prim to fout
//
 weight
    PrimTrees( wgraph &G, ofstream& fout ) 
{
    vertex vn = G.size();
//  Infty weight 
    component Tn = 0;
    weight infty = UINT_MAX;
    weight Tw = 0;
//  Initialize parents to vn, components and weights
    vector<vertex> Pp( vn, vn );
    vector<component> Pc( vn );
    vector<weight> Pw( vn,0 );
	weight mw;
    vertex mv, mvi;
	do {
	//  Find minimal edge out of previous trees
		mw = infty;
		for( vertex v=0; v<vn; v++ )
			for( index i=0; i<G[v].size(); i++ ) 	
				if( Pp[v]==vn  && mw > G[v][i].second ) {
					mw = G[v][i].second;
					mv = v;
					mvi = i;
				}
		if( mw == infty )
			break;
	//  Root tree in mv
		vertex mva = G[mv][mvi].first;
		Pp[mv] = mv; Pp[mva] = mv;
    //  Assign component
		Pc[mv] = Tn; Pc[mva] = Tn;
		Tw += mw;
		Pw[Tn] += mw;
        do {       
        //  Edge in tree: from a vertex in tree to a vertex out of trees
        //  Sum edge weight to tree weights and total weight
            
		//  Write found edge as trees edge
			fout << "Prim edge: " << mv << " - " << mva <<  " (" << mvi<< ")" <<  " [" << mw << "]\n";
		    mw = infty;
		//  Search for minimal edge from one vertex in tree and the other out of tree
			for( vertex v=0; v<vn; v++ )
				for( index i=0; i<G[v].size(); i++ ) 	
					if(  Pp[G[v][i].first]==vn && Pp[v]<vn && mw > G[v][i].second ) {
			            mw = G[v][i].second;
						mv = v;
						mvi = i;
					}
			if (mw == infty)
				break;
			vertex mva = G[mv][mvi].first;
			Pp[mva] = mv;
			//  Assign component
			Pc[mva] = Tn;
			Tw += mw;
			Pw[Tn] += mw;

		} while( true );
        Tn++;
	} while (true);
	for( vertex v=0; v<vn; v++ )
		if (!G[v].size())
			Pc[v] = Tn++;
   	for( component Ti=0; Ti<Tn; Ti++ ) {
		fout << "Component " << Ti << " of weight " << Pw[Ti] << ", vertices: ";
		for( vertex v=0; v<vn; v++ )
			if( Pc[v] == Ti )
				fout << "\t" << v;
		fout << endl;
	}

	return Tw;
}
