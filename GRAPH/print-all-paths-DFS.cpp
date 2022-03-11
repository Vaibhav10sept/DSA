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

vector<vector<Edge>> constructGraphFromInput() {
	int vertices;
	int edges;
	cin >> vertices >> edges;
	vector<vector<Edge>> graph(vertices);
	for (int i = 0; i < edges; i++) {
		int v1, v2, wt;
		cin >> v1 >> v2 >> wt;
		graph[v1].push_back(Edge(v1, v2, wt));
		graph[v2].push_back(Edge(v2, v1, wt));
	}
	return graph;
}



void printAllPaths(vector<vector<Edge>> graph, int src, int dest, vector<bool> &visited, string path) {
	//bc
	if (src == dest) {
		path += to_string(src);
		cout << path << endl;
		return;
	}

	visited[src] = true;
	for (Edge edge : graph[src]) {
		if (visited[edge.neighbour] == false) {
			printAllPaths(graph, edge.neighbour, dest, visited, path + to_string(src));
		}
	}
	//backtrack(think, same logic as in "floodFill"(recursion))
	visited[src] = false;
}

int main() {
	//************************************************************
	//VIDEO LINK: https://www.youtube.com/watch?v=DrQ-eTN2v3A&list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk&index=523
	//NOTE: prerequisite is "has path"
	//************************************************************

	// INPUT:
	// 7
	// 8
	// 0 1 10
	// 1 2 10
	// 2 3 10
	// 0 3 10
	// 3 4 10
	// 4 5 10
	// 5 6 10
	// 4 6 10
	// 0
	// 6
	vector<vector<Edge>> graph = constructGraphFromInput();
	int src, dest;
	cin >> src >> dest;
	vector<bool> visited(graph.size(), false);

	printAllPaths(graph, src, dest, visited, "");
}