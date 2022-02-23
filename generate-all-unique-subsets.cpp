#include <bits/stdc++.h>
using namespace std;


void gensubset(int idx, vector<int> &ds, vector<int> &v, vector<vector<int>> &ans) {
	ans.push_back(ds);
	for (int i = idx; i < v.size(); i++) {
		if (i > idx and v[i] == v[i - 1]) continue;
		ds.push_back(v[i]);
		gensubset(i + 1, ds, v, ans);
		ds.pop_back();
	}
}


int main () {
	vector<int> in;
	int n;
	cin >> n;
	while (n--) {
		int temp;
		cin >> temp;
		in.push_back(temp);
	}
	vector<vector<int>> ans;
	vector<int> ds;
	gensubset(0, ds , in, ans);
	for (auto i : ans) {
		for (auto j : i) cout << j << " ";
		cout << endl;
	}
}