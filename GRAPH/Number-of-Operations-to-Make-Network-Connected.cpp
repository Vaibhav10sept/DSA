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

		if (pu == pv) { //dono ke parent same h, mtlb already connected(indirectly)(belongs to same component)
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

int numberOfOperations(vector<vector<int>> edges, int n) {
	//WV recommended
	DisjointSet ds(n);

	//count the extra edges, using disjoint set data structure
	int countOfExtraEdge = 0;
	for (auto it : edges) {
		int v = it[0];
		int u = it[1];

		if (ds.findParent(u) == ds.findParent(v)) { //means dono nodes already indirectly connected hai, thats means this is an extra edges
			countOfExtraEdge++;
		}
		else {
			ds.unionByRank(u, v);
		}
	}
	cout << "test " << endl;
	for (auto ele : ds.parent) cout << ele << " ";
	cout << endl;


	//count the number of connected components(here we are using disjoint set(wv))
	//ye same kaam hm dfs use krke bhi kr skte hai
	int countOfConnectedComponents = 0;
	for (int i = 0; i < n; i++) {
		if (ds.parent[i] == i) { //agar ith node the parent i hi hai, that means this is the head of a component so incresase the count of connected comoponents(wv, cs, think)
			countOfConnectedComponents++;
		}
	}

	//logic: eventually hme connected components ko hi connect krna h
	//agr 4 connected components hai to hme 3 extra edges required hogi unhe connected krne ke liye(think,cs,wv)
	//so agr count of extra edges is greater then or equal to count of extra edges required(count of connected componets - 1)
	//then return the count of extra edges required, otherwise return -1

	int countOfExtraEdgesRequired = countOfConnectedComponents - 1;//think,wv,read above
	cout << countOfConnectedComponents << endl;
	if (countOfExtraEdgesRequired <= countOfExtraEdge) return countOfExtraEdgesRequired;

	return -1;
}

int main() {
	/************************************************************
	 * STRONG PREQ: disjoint set
	 * VIDOE: https://www.youtube.com/watch?v=FYrl7iz9_ZU
	 * LEETCODE: https://leetcode.com/problems/number-of-operations-to-make-network-connected/
	//************************************************************/
	int n = 6;
	vector<vector<int>> connections = {{0, 1}, {0, 2}, {0, 3}, {1, 2}};
	cout << "ans " << numberOfOperations(connections, n);
}