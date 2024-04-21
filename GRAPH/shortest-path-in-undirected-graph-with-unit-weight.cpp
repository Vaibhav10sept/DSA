#include <bits/stdc++.h>
using namespace std;

vector<int> shortestPathInUndirectedGraph(vector<vector<int>> graph, int src) {
	// WV recommmended
	vector<int> distance(graph.size(), 1e9); //means infinity store hoga

	distance[src] = 0; //think, CS, WV
	//now, code is similar to BFS
	queue<int> q;
	q.push(src);
	while (!q.empty()) {
		int node = q.front();
		q.pop();

		for (auto neighbour : graph[node]) {
			if (distance[node] + 1 < distance[neighbour]) {
				distance[neighbour] = distance[node] + 1;
				q.push(neighbour);
			}
		}
	}

	//ans array me distance ko fill krna kyoki ques me bola h agr node not reachable hogi to -1 likha but distance me infine(1e9) store h isliye bss
	vector<int> ans;
	for (auto ele : distance) {
		if (ele != 1e9) {
			ans.push_back(ele);
		}
		else {
			ans.push_back(-1);
		}
	}
	return ans;

}

int main() {
	/************************************************************
	//VIDEO LINK: https://www.youtube.com/watch?v=C4gxoTaI71U&list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw&index=19
	QUESTION: https://practice.geeksforgeeks.org/problems/shortest-path-in-undirected-graph-having-unit-distance/1
	/************************************************************/
	vector<vector<int>> edges = {{0, 1}, {0, 3}, {3, 4}, {4 , 5}, {5, 6}, {1, 2}, {2, 6}, {6, 7}, {7, 8}, {6, 8}};
	int V = 9;
	int E = 10;
	int src = 0;
	//construct graph

	vector<vector<int>> graph(V);
	for (auto edge : edges) {
		int u = edge[0];
		int v = edge[1];

		graph[u].push_back(v);
		graph[v].push_back(u); //coz undirected graph hai
	}

	vector<int> ans = shortestPathInUndirectedGraph(graph, src);
	for (auto ele : ans) cout << ele << " ";
	cout << endl;

}