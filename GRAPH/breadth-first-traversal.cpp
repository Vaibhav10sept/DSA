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

void breadthFirstTraversal(vector<vector<Edge>> graph, int src) {
	queue<UtilPair> q;
	q.push(UtilPair(src, to_string(src)));
	vector<bool> visited(graph.size());
	while (!q.empty()) {
		//step 1. remove
		UtilPair removed = q.front();
		q.pop();

		//check if already visited
		if (visited[removed.vertix]) {
			continue;
		}

		//step 2. mark visited
		visited[removed.vertix] = true;

		//step 3. work(print)
		cout << removed.vertix << " @ " << removed.path << endl;

		//step 4. add its unvisited neighbour
		for (Edge edge : graph[removed.vertix]) {
			if (visited[edge.neighbour] == false) {
				q.push(UtilPair(edge.neighbour, removed.path + to_string(edge.neighbour)));
			}
		}
	}
}

int main() {
	//************************************************************
	//VIDEO LINK: https://www.youtube.com/watch?v=GHnC5qHexsk&list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk&index=530
	//NOTE: we use queue data structure here
	//STEPS: remove, mark(visited), work(print), add
	//NOTE: breadth first traversal is same as the level order traversal of tree.
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
	// 2

	vector<vector<Edge>> graph = constructGraphFromInput();
	int src;
	cin >> src;
	breadthFirstTraversal(graph, src);
}