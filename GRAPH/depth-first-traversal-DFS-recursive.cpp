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

class UtilPair {
public:
	int vertix;
	string path;

	UtilPair(int vertix, string path) {
		this->vertix = vertix;
		this->path = path;
	}
};

void depthFirstSearchHelper(vector<vector<Edge>> &graph, int src, int dest, vector<bool> &visited, string path) {
	if (src == dest) {
		cout << path << endl;
	}

	//mark visited
	visited[src] = true;

	//recursive calls
	for (auto edge : graph[src]) {
		if (visited[edge.neighbour] == false) {
			depthFirstSearchHelper(graph, edge.neighbour, dest, visited, path + to_string(edge.neighbour));
		}
	}
	//NOTE: backtrack to explore all the path from src to dest.(remove this line and you'll only get one path(think, cs))
	visited[src] = false;
}

void recursiveDepthFirstTraversal(vector<vector<Edge>> graph, int src, int dest) {
	vector<bool> visited(graph.size(), false);
	string path = "";
	path = path + to_string(src);
	depthFirstSearchHelper(graph, src, dest, visited, path);
}

int main() {
	//************************************************************
	//PREQ: print all paths
	//VIDEO LINK: https://www.youtube.com/watch?v=iUtmQ66IC_0&list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk&index=535
	//NOTE: reverse eular path chlta hai isme.
	//STEPS: remove, mark(visited), work(print), add
	//NOTE: BFS give you smaller path as compared to DFS.
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
	recursiveDepthFirstTraversal(graph, src, dest);
}

