#include <bits/stdc++.h>
using namespace std;

int cheapestFligthWithinKStops(vector<vector<int>> edges, int src, int dest, int k, int n) {
	//create graph using edges
	vector<vector<pair<int, int>>> graph(n); //pair --> node,cost

	for (vector<int> vec : edges) { //directed graph
		int u = vec[0];
		int v = vec[1];
		int cost = vec[2];

		graph[u].push_back({v, cost});
	}

	//do level wise BFS starting from the src node
	int level = 0;
	//NOTE: we are using distance array instead of visited, because we are looking for path so we have to explore all the paths, that's why visited we are not using(wv, think)
	vector<int> distance(n, INT_MAX);
	//starting from the src node
	queue<pair<int, int>> q; //pair --> node, distance till node
	q.push({src, 0});
	distance[src] = 0; //distance from src to src is 0 (think, cs)

	while (!q.empty() and level <= k + 1) {
		int size = q.size();
		level++;
		for (int i = 0; i < size; i++) {
			pair<int, int> removed = q.front();
			q.pop();
			int node = removed.first;
			int cost = removed.second;

			distance[node] = min(distance[node], cost);

			//push all the adjacent node to the queue
			for (pair<int, int> adj : graph[node]) {
				if (distance[adj.first] > cost + adj.second) {
					//this "if" will optimize the cost(will submit on leetcode)
					//without this "if" code will give Memory limit exceeded.
					q.push({adj.first, cost + adj.second});
				}
			}
		}
	}
	return distance[dest] != INT_MAX ? distance[dest] : -1;
}

int main() {
	/*
	NOTE: good BFS question, wv
	NOTE: a DFS sol is also there that gives TLE(writen by me)
	VIDEO: https://www.youtube.com/watch?v=VmUpydhNmuw
	LEETCODE: https://leetcode.com/problems/cheapest-flights-within-k-stops/description/
	*/

	int n = 4;
	vector<vector<int>> flights = {{0, 1, 100}, {1, 2, 100}, {2, 0, 100}, {1, 3, 600}, {2, 3, 200}};
	int src = 0;
	int dst = 3;
	int k = 1;

	cout << cheapestFligthWithinKStops(flights, src, dst, k, n);
}