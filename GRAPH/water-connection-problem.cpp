#include <bits/stdc++.h>
using namespace std;

void displayMatrix(vector<vector<int>> arr) {
	for (int i = 0; i < arr.size(); i++) {
		for (int j = 0; j < arr[i].size(); j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}

void dfs(int node, vector<vector<pair<int, int>>> &graph, vector<bool> &visited) {
	if (visited[node]) return;

	visited[node] = true;
	// cout << "node " << node << endl;
	for (auto adj : graph[node]) {
		if (visited[adj.first] == false)
			dfs(adj.first, graph, visited);
	}
}

vector<vector<int>>  waterConnectionProblem(int n, int p, vector<int> a, vector<int> b, vector<int> d) {
	//create directed graph
	vector<vector<pair<int, int>>> graph(n + 1); //+1 coz 1 based vertices are there
	for (int i = 0; i < p; i++) {
		graph[a[i]].push_back({b[i], d[i]});
		graph[b[i]].push_back({a[i], d[i]});
	}

	//get connected component vala code
	int numberOfConnectedComponents = 0;
	vector<bool> visited(n + 1, false);
	sort(a.begin(), a.end());
	for (int i = 0; i < a.size(); i++) {
		if (visited[a[i]] == false) {
			cout << "a " << a[i] << endl;
			dfs(a[i], graph, visited);
			numberOfConnectedComponents++;
		}
	}

	cout << numberOfConnectedComponents << endl;


	vector<vector<int>> ans;
	return ans;
}


int main() {
	/************************************************************
	 * QUESTION: https://leetcode.com/problems/making-a-large-island/description/
	 VIDEO:
	//************************************************************/
	int n = 9; //vertices
	int p = 6; //edges
	vector<int> a = {7, 5, 4, 2, 9, 3};
	vector<int> b = {4, 9, 6, 8, 7, 1};
	vector<int> d = {98, 72, 10, 22, 17, 66};

	vector<vector<int>> ans =  waterConnectionProblem(n, p, a, b, d);
	displayMatrix(ans);
}