//
//  Created by Jonas Anseeuw
//  Copyright (c) 2014 Jonas Anseeuw. All rights reserved.
//

#include <iostream>
#include <vector>
#include "graph.h"

using namespace std;

class EdgeConnectivity{
public:
	EdgeConnectivity(const Graph<UNDIRECTED> &G):g(G),
	pre(G.numberOfVertices()), low(G.numberOfVertices()), parent(G.numberOfVertices(), -1), visited(G.numberOfVertices(), false){
		for(int i=0; i < g.numberOfVertices(); i++){
			if(!visited[i]) dfsR(i);
		}
	}
private:
	const Graph<UNDIRECTED> &g;
	vector<int> pre, low, parent;
	vector<bool> visited;
	
	void dfsR(int u){
		static int num=0;
		
		visited[u]=true;
		pre[u] = num++;
		low[u] = pre[u]; // Every vertex can visit atleast himself
		
		map<int,int>::const_iterator it = g[u].begin();
		while(it != g[u].end()){
			int v=it->first;
			
			if(!visited[v]){
				parent[v]=u;
				dfsR(v);
				
				if(low[v] < low[u]) low[u] = low[v];
				if(low[v] > pre[u])
					cout<<"Bridge "<< u << " "<< v <<endl;
			}else if(v != parent[u]){
				if(pre[v] < low[u])
					low[u] = pre[v];
			}
			it++;
		}
	}
};

class ArticulationPoints{
public:
	ArticulationPoints(const Graph<UNDIRECTED> &G):g(G),
	pre(G.numberOfVertices()), low(G.numberOfVertices()), parent(G.numberOfVertices(), -1), visited(G.numberOfVertices(), false){
		for(int i=0; i < g.numberOfVertices(); i++){
			if(!visited[i]) dfsR(i);
		}
	}
private:
	const Graph<UNDIRECTED> &g;
	vector<int> pre, low, parent;
	vector<bool> visited;
	
	void dfsR(int u){
		static int num=0;
		
		visited[u]=true;
		pre[u] = num++;
		low[u] = pre[u]; // Every vertex can visit atleast himself
		
		map<int,int>::const_iterator it = g[u].begin();
		while(it != g[u].end()){
			int v=it->first;
			
			if(!visited[v]){
				parent[v]=u;
				dfsR(v);
				
				if(low[v] < low[u]){
					low[u] = low[v];
				}else if(low[v] >= pre[u]){
					cout<<"Articulation Point "<<u<< " for "<<v<<endl;
				}
			}else if(v != parent[u]){
				if(pre[v] < low[u])
					low[u] = pre[v];
			}
			it++;
		}
	}
};

int main(int argc, char *argv[]){
	
    Graph<UNDIRECTED> g1(5);
    g1.addEdge(1, 0);
    g1.addEdge(0, 2);
    g1.addEdge(2, 1);
    g1.addEdge(0, 3);
    g1.addEdge(3, 4);
	cout << "\nBridges in first graph \n";
	EdgeConnectivity ec1(g1);
	cout << "\nArticulation points in first graph \n";
    ArticulationPoints a1(g1);
	
    Graph<UNDIRECTED> g2(4);
    g2.addEdge(0, 1);
    g2.addEdge(1, 2);
    g2.addEdge(2, 3);
	cout << "\nBridges in second graph \n";
    EdgeConnectivity ec2(g2);
	cout << "\nArticulation points in second graph \n";
    ArticulationPoints a2(g2);
	
    Graph<UNDIRECTED> g3(7);
    g3.addEdge(0, 1);
    g3.addEdge(1, 2);
    g3.addEdge(2, 0);
    g3.addEdge(1, 3);
    g3.addEdge(1, 4);
    g3.addEdge(1, 6);
    g3.addEdge(3, 5);
    g3.addEdge(4, 5);
	cout << "\nBridges in third graph \n";
    EdgeConnectivity ec3(g3);
	cout << "\nArticulation points in third graph \n";
    ArticulationPoints a3(g3);
	
    return 0;
}
