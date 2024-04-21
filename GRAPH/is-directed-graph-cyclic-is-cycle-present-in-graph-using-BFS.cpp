#include <bits/stdc++.h>
using namespace std;

class Edge {
public:
	int source;
	int neighbour;
	int weight;
	Edge(int src, int nbr, int wt) {
		source = src;
		neighbour = nbr;
		weight = wt;
	}
};

vector<vector<int>> constructDirectedGraphFromInput() {
	int vertices;
	int edges;
	cin >> vertices >> edges;
	vector<vector<int>> graph(vertices);
	for (int i = 0; i < edges; i++) {
		int v1, v2, wt;
		cin >> v1 >> v2 >> wt;
		graph[v1].push_back(v2);
		//graph[v2].push_back(Edge(v2, v1, wt)); // uncommented this line for the undirected graph
	}
	return graph;
}

bool isDirectedGraphCyclicBFS(vector<vector<int>> graph) {
	//* LOGIC: topological only possible in DAG, if the graph is not acyclic then the topo ans array will not have the same size as graph.size() (think, cs, WV)
	//using BFS
	//step 1: find the indegree of all the vertixes
	vector<int> indegree(graph.size(), 0);
	for (int i = 0; i < graph.size(); i++) {
		for (auto edge : graph[i]) {
			indegree[edge]++;
		}
	}

	//step 2: put the 0 indegree into the queue
	queue<int> q;
	for (int i = 0; i < graph.size(); i++) {
		if (indegree[i] == 0) {
			q.push(i);
		}
	}

	vector<int> topologicalSort;
	while (!q.empty()) {
		int removedNode = q.front();
		q.pop();
		topologicalSort.push_back(removedNode);

		//reduce the indegree of all adjacent node from the remove node
		for (auto edge : graph[removedNode]) {
			indegree[edge]--;
			if (indegree[edge] == 0) {
				q.push(edge);
			}
		}
	}

	if (topologicalSort.size() != graph.size()) {
		//means topo sort me sare vertixes nhi aae, that means graph DAG ni h, so it's acyclic return false
		return false;
	}
	return true;
}

int main() {
	/************************************************************
	 * STRONG PREQ: topological sort using BFS, kahn's algorithm.
	 * LOGIC: topological only possible in DAG, if the graph is not acyclic then the topo ans array will not have the same size as graph.size() (think, cs, WV)
	 * QUESTION: https://leetcode.com/problems/course-schedule/submissions/
	//VIDEO LINK: https://www.youtube.com/watch?v=iTBaI90lpDQ&list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw&index=15
	/************************************************************/
	// INPUT:
// 7
// 6
// 0 1 10
// 1 2 10
// 2 3 10
// 3 4 10
// 4 5 10
// 5 6 10

	vector<vector<int>> graph = constructDirectedGraphFromInput();
	if (isDirectedGraphCyclicBFS(graph)) {
		cout << "yes the graph is cyclic" << endl;
	}
	else {
		cout << "no the graph is not cyclic" << endl;
	}
}