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

bool satisfiabilityEquation(vector<string> arr) {
	//disjoint set DS is used here.
	// * NOTE: i wrote this after WV
	DisjointSet ds(26);


	//step1: sare equal vale case ke liye, union krdo
	for (auto str : arr) {
		int a = str[0] - 'a'; //char to int(will give int in range 0 to 25)
		int b = str[3] - 'a'; //char to int(will give int in range 0 to 25)
		if (str[1] == '=') { // a==b
			//do union
			ds.unionByRank(a, b); //char to int(will give int in range 0 to 25)
		}
	}

	//step2: sare not equal vale case ke liye check kro, agr parent same aae to return false krdo
	for (auto str : arr) {
		int a = str[0] - 'a'; //char to int(will give int in range 0 to 25)
		int b = str[3] - 'a'; //char to int(will give int in range 0 to 25)
		if (str[1] == '!') { // a!=b
			//check the parent of a and b
			if (ds.findParent(a) == ds.findParent(b)) {
				//means, dono ke parent same to ye not equal nhi ho skte isliye return false
				return false;
			}

		}
	}

	return true;
}

int main() {
	/************************************************************
	 * STRONG PREQ: disjoint set
	 * NOTE: i wrote this after WV
	LINK: https://leetcode.com/problems/satisfiability-of-equality-equations/description/
	VIDEO: https://www.youtube.com/watch?v=0Z8lt7U_kiE
	//************************************************************/
	vector<string> equations = {"a==b", "b!=c", "c==a"};
	if (satisfiabilityEquation(equations)) {
		cout << "true";
	}
	else cout << "false";
}