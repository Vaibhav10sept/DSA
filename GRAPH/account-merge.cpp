#include <bits/stdc++.h>
using namespace std;

void displayMatrix(vector<vector<string>> arr) {
	for (int i = 0; i < arr.size(); i++) {
		for (int j = 0; j < arr[i].size(); j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}

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

vector<vector<string>> accountMerge(vector<vector<string>> arr) {
	// NOTE: this is my code i wrote it after wv
	// * NOTE: ye code video me nhi milega, mene khud se likha h
	DisjointSet ds(arr.size());

	unordered_map<string, int> mp1; //email -> index
	for (int j = 0; j < arr.size(); j++) {
		vector<string> vec = arr[j];

		for (int i = 1; i < vec.size(); i++) {
			string mail = vec[i];
			if (mp1.find(mail) != mp1.end()) {
				//found
				///do union of j and index at which it is found
				cout << "unionByRank " << j << " " << mp1[mail] << endl;
				ds.unionByRank(j, mp1[mail]);
			}
			else { //not found, put it in mp1
				mp1[mail] = j;
			}
		}
	}

	unordered_map<int, vector<string>> mp2; //index -> vector of string(mail)
	for (auto it : mp1) {
		int index = it.second;
		string mail = it.first;

		int parentIdx = ds.findParent(index);
		mp2[parentIdx].push_back(mail);
	}

	//generate the answer
	vector<vector<string>> ans;
	for (auto it : mp2) {
		int index = it.first;
		vector<string> mails = it.second;

		vector<string> temp;
		temp.push_back(arr[index][0]);
		for (string mail : mails) {
			temp.push_back(mail);
		}
		sort(temp.begin() + 1, temp.end()); //think, cs, mera logic h, ek testcase fail hora tha. video me nhi milega
		ans.push_back(temp);
	}
	return ans;
}

int main() {
	/************************************************************
	 * STRONG PREQ: disjoint set graph union by rank.
	 * NOTE: ye code video me nhi milega, mene khud se likha h
	NOTE: this is my code i wrote it after wv
	VIDEO: https://www.youtube.com/watch?v=FMwpt_aQOGw&t=1013s
	LINK: https://leetcode.com/problems/accounts-merge/
	//************************************************************/
	// vector<vector<string>> accounts = {{"Gabe", "Gabe0@m.co", "Gabe3@m.co", "Gabe1@m.co"}, {"Kevin", "Kevin3@m.co", "Kevin5@m.co", "Kevin0@m.co"}, {"Ethan", "Ethan5@m.co", "Ethan4@m.co", "Ethan0@m.co"}, {"Hanzo", "Hanzo3@m.co", "Hanzo1@m.co", "Hanzo0@m.co"}, {"Fern", "Fern5@m.co", "Fern1@m.co", "Fern0@m.co"}};
	// vector<vector<string>> accounts = {{"John", "johnsmith@mail.com", "john_newyork@mail.com"}, {"John", "johnsmith@mail.com", "john00@mail.com"}, {"Mary", "mary@mail.com"}, {"John", "johnnybravo@mail.com"}};
	// vector<vector<string>> accounts = {{"Alex", "Alex5@m.co", "Alex4@m.co", "Alex0@m.co"}, {"Ethan", "Ethan3@m.co", "Ethan3@m.co", "Ethan0@m.co"}, {"Kevin", "Kevin4@m.co", "Kevin2@m.co", "Kevin2@m.co"}, {"Gabe", "Gabe0@m.co", "Gabe3@m.co", "Gabe2@m.co"}, {"Gabe", "Gabe3@m.co", "Gabe4@m.co", "Gabe2@m.co"}};
	vector<vector<string>> accounts = {{"David", "Avid0@m.co", "David0@m.co", "David1@m.co"}, {"David", "Gvid3@m.co", "David3@m.co", "David4@m.co"}, {"David", "David4@m.co", "David5@m.co"}, {"David", "David2@m.co", "David3@m.co"}, {"David", "David1@m.co", "David2@m.co"}};

	vector<vector<string>> ans = accountMerge(accounts);
	displayMatrix(ans);
}