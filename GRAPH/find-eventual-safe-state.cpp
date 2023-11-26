#include <bits/stdc++.h>
using namespace std;

vector<int> findSafeStates(vector<vector<int>> graph) {
	// * NOTE: this is my code, i wrote this after wv
	int n = graph.size();

	//create a reverse graph(wv, think, cs, logic)
	vector<vector<int>> reversedGraph(n);
	for (int i = 0; i < n; i++) {
		for (int adj : graph[i]) {
			reversedGraph[adj].push_back(i); //reverse graph
		}
	}

	//do topological sorting for reversed graph using BFS(kahn algorithm)

	//find indegre
	vector<int> indegree(n, 0);
	for (int i = 0; i < n; i++)  {
		for (auto adj : reversedGraph[i]) {
			indegree[adj]++;
		}
	}

	//add all the node with indegree 0 in queue
	queue<int> q;
	for (int i = 0; i < indegree.size(); i++) {
		if (indegree[i] == 0) {
			q.push(i);
		}
	}


	//do BFS
	vector<bool> visited(n, false);
	while (!q.empty()) {
		int removed = q.front();
		q.pop();

		if (visited[removed]) continue;

		visited[removed] = true;

		for (int adj : reversedGraph[removed]) {
			indegree[adj]--;
			if (indegree[adj] == 0) {
				// cout << "ad " << adj << endl;
				q.push(adj);
			}
		}
	}


	//those who are visited are safe nodes(think, wv, cs)
	vector<int> ans;
	for (int i = 0; i < visited.size(); i++) {
		if (visited[i]) {
			ans.push_back(i);
		}
	}
	return ans;
}


int main() {
	/************************************************************
	 * STRONG PREQ: topological sort BFS kahn algorithm
	 * NOTE: this is my code, i wrote this after wv
	VIDEO LINK: https://www.youtube.com/watch?v=2gtg3VsDGyc
	LEETCODE: https://leetcode.com/problems/find-eventual-safe-states/
	//************************************************************/
	vector<vector<int>> graph = {{1, 2}, {2, 3}, {5}, {0}, {5}, {}, {}};
	vector<int> ans = findSafeStates(graph);
	for (auto it : ans) cout << it << " ";
	cout << endl;
}