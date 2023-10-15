#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<pair<int, int>>> &graph, int steps, int cost, int node, int dest, int k, int& ans) {
	if (steps > k + 1) return;

	if (node == dest) ans = min(cost, ans);

	// cout << "node " << node << " " << steps << " cost " << cost << endl;
	//explore all paths using dfs
	for (auto adj : graph[node]) {
		dfs(graph, steps + 1, cost + adj.second, adj.first, dest, k, ans);
	}
}

int cheapestFligthWithinKStopsDFS(vector<vector<int>>& edges, int src, int dest, int k, int n) {
	//create graph using edges
	vector<vector<pair<int, int>>> graph(n); //pair --> node,cost

	for (vector<int> vec : edges) { //directed graph
		int u = vec[0];
		int v = vec[1];
		int cost = vec[2];

		graph[u].push_back({v, cost});
	}

	int ans = INT_MAX;
	dfs(graph, 0, 0, src, dest, k, ans);

	if (ans == INT_MAX) return -1;
	return ans;
}

int main() {
	/*
	NOTE: this DFS(writen by me) sol will give TLE, a BFS accepted sol is also there
	NOTE: good BFS question, wv
	VIDEO: https://www.youtube.com/watch?v=VmUpydhNmuw
	LEETCODE: https://leetcode.com/problems/cheapest-flights-within-k-stops/description/
	*/

	int n = 4;
	vector<vector<int>> flights = {{0, 1, 1}, {0, 2, 5}, {1, 2, 1}, {2, 3, 1}};
	int src = 0;
	int dst = 3;
	int k = 1;

	cout << cheapestFligthWithinKStopsDFS(flights, src, dst, k, n);
}