#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
public:
	vector<int> parent;
	vector<int> rank;
	DisjointSet(int n) {
		parent.resize(n);
		rank.resize(n, 0);

		for (int i = 0; i < n; i++) {
			parent[i] = i;
		}
	}


	int findParent(int node) { // TC: constant
		//WV
		//BC
		if (parent[node] == node) {
			//this is the ultimate parent
			return node;
		}
		//NOTE: parent[node] = --> agr below me ye line nhi lgaege to path compression nhi hoga(which is done to make this func constant in time)(think, WV)
		return parent[node] = findParent(parent[node]);
	}

	void unionByRank(int u, int v) { // TC: constant
		int pu = findParent(u); //pu --> parent of u
		int pv = findParent(v); //pv --> parent of v

		if (pu == pv) {
			//already union ho chuka h to return kr  jao
			return;
		}

		if (rank[pu] < rank[pv]) {
			//jiski rank jyada hoti h vo parent bnta hai
			parent[pu] = pv;
		}
		else if (rank[pv] < rank[pu]) {
			parent[pv] = pu;
		}
		else { //dono ki rank same h, to kisi ko bhi parent bnado doesn't matter
			parent[pu] = pv;
			// and don't forgot to increase the rank of the parent(think, WV)
			rank[pv]++;
		}
	}
};

bool comparator(vector<int> a, vector<int> b) {
	return a[2] < b[2]; //sort in increasing order of weight
}

int kruskalAlgorithm(vector<vector<int>> edges, int V) {
	//WV, STRONG PREREQUISITE: disjoint set
	//sort the edges in terms of increasing weights
	sort(edges.begin(), edges.end(), comparator);
	int totalCost = 0;
	DisjointSet obj(V);
	for (int i = 0; i < edges.size(); i++) {
		int u = edges[i][0];
		int v = edges[i][1];
		int weight = edges[i][2];

		if (obj.findParent(u) != obj.findParent(v)) {
			//not belongs to the same component
			obj.unionByRank(u, v);
			totalCost += weight;
		}

	}
	return totalCost;
}

int main() {
	/************************************************************
	 * STRONG PREREQUISITE: disjoint set
	 * NOTE:
	//VIDEO LINK: https://www.youtube.com/watch?v=DMnDM_sxVig&list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw&index=27
	//NOTE: spanning tree -> tree(connected acyclic graph), spanning
	//(all vertices are there)
	//NOTE: minimum spanning tree -> out of many spanning trees that are possible
	//the one whose weight is least is MST.
	A Spanning Tree is a tree which have V vertices and V-1 edges. All nodes in a spanning tree are reachable from each other.

	A Minimum Spanning Tree(MST) or minimum weight spanning tree for a weighted, connected, undirected graph is a spanning tree having a weight less than or equal to the weight of every other possible spanning tree. The weight of a spanning tree is the sum of weights given to each edge of the spanning tree. In short out of all spanning trees of a given graph, the spanning tree having minimum weight is MST.
	//************************************************************/
	int V = 5;
	vector<vector<int>> edges = { {0, 1, 2}, {0, 3, 6}, {1, 2, 3}, {1, 3, 8}, {1, 4, 5}, {4, 2, 7}};

	cout << kruskalAlgorithm(edges, V);
}