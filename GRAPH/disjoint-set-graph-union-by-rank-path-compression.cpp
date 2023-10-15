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

int main() {
	/************************************************************
	NOTE: this is the prerequisite for kruskal algo to find the minimum spanning tree.
	NOTE: do check kruskal algo to find the minimum spanning tree after this question
	VIDEO(imp): https://www.youtube.com/watch?v=aBxjDBC4M1U&list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw&index=26
	VIDOE(hindi, anuj bhaiya): https://www.youtube.com/watch?v=Kptz-NVA2RE
	SECOND VIDEO(hindi, love babbar): https://www.youtube.com/watch?v=KxLtIrCyXwE
	//************************************************************/
	DisjointSet obj(8);
	obj.unionByRank(1, 2);
	obj.unionByRank(2, 3);
	obj.unionByRank(4, 5);
	obj.unionByRank(6, 7);
	obj.unionByRank(5, 6);
	//if 3 and 7 are in same component or not
	if (obj.findParent(3) == obj.findParent(7)) {
		cout << "in same component" << endl;
	}
	else {
		cout << "not in same component" << endl;
	}

	obj.unionByRank(3, 7);
	//if 3 and 7 are in same component or not
	if (obj.findParent(3) == obj.findParent(7)) {
		cout << "in same component" << endl;
	}
	else {
		cout << "not in same component" << endl;
	}

}