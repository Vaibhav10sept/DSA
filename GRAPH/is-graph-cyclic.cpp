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

bool breadthFirstTraversal(vector<vector<Edge>> graph, int src, vector<bool> &visited) {
	queue<UtilPair> q;
	q.push(UtilPair(src, to_string(src)));
	while (!q.empty()) {
		//step 1. remove
		UtilPair removed = q.front();
		q.pop();

		//check if already visited. if yes, That means it has cycle(think)
		if (visited[removed.vertix]) {
			return true; //think
		}

		//step 2. mark as visited
		visited[removed.vertix] = true;

		//step 3. add unvisited neighbours
		for (Edge edge : graph[removed.vertix]) {
			if (visited[edge.neighbour] == false) {//add only unvisited neighbour
				q.push(UtilPair(edge.neighbour, removed.path + to_string(edge.neighbour)));
			}
		}
	}
	return false;
}

bool isGraphCyclic(vector<vector<Edge>> graph) {
	vector<bool> visited(graph.size(), false);

	//get connected components vala logic
	for (int v = 0; v < graph.size(); v++) {
		if (visited[v] == false) {
			if (breadthFirstTraversal(graph, v, visited)) {
				return true;
			}
		}
	}
	return false;
}

int main() {
	//************************************************************
	//VIDEO LINK: https://www.youtube.com/watch?v=qbQq-k75bcY&list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk&index=530
	//NOTE: prerequisite is "bredth first traversal" and "get connected components"
	//************************************************************
	// INPUT:
// 7
// 6
// 0 1 10
// 1 2 10
// 2 3 10
// 3 4 10
// 4 5 10
// 5 6 10

	vector<vector<Edge>> graph = constructGraphFromInput();
	if (isGraphCyclic(graph)) {
		cout << "yes the graph is cyclic" << endl;
	}
	else {
		cout << "no the graph is not cyclic" << endl;
	}
}