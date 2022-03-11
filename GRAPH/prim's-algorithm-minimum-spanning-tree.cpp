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
	int acquiredBy;
	int weight;

	UtilPair(int vertix, int acquiredBy, int weight) {
		this->vertix = vertix;
		this->acquiredBy = acquiredBy;
		this->weight = weight;
	}
};

//we are doing operator overloading so that we can implement priority queue.
bool operator<(const UtilPair p1, const UtilPair p2) {
	return p1.weight > p2.weight;
}

void PrimsAlgorithm(vector<vector<Edge>> graph) {
	priority_queue<UtilPair> q;
	q.push(UtilPair(0, -1, 0));
	vector<bool> visited(graph.size());
	while (!q.empty()) {
		//step 1. remove
		UtilPair removed = q.top();
		q.pop();

		//check if already visited
		if (visited[removed.vertix]) {
			continue;
		}

		//step 2. mark visited
		visited[removed.vertix] = true;

		//step 3. work(print)
		if (removed.acquiredBy != -1)
			cout << removed.vertix << " - " << to_string(removed.acquiredBy) << " @ " << removed.weight << endl;

		//step 4. add its unvisited neighbour
		for (Edge edge : graph[removed.vertix]) {
			if (visited[edge.neighbour] == false) {
				q.push(UtilPair(edge.neighbour, removed.vertix, edge.weight));
			}
		}
	}
}

int main() {
	//************************************************************
	//VIDEO LINK: https://www.youtube.com/watch?v=Vw-sktU1zmc&list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk&index=534
	//NOTE: spanning tree -> tree(connected acyclic graph), spanning
	//(all vertices are there)
	//NOTE: minimum spanning tree -> out of many spanning trees that are possible
	//the one whose weight is least is MST.
	//NOTE: prerequisite is "dijsktra's algorithm"
	//************************************************************
	// INPUT:
// 7
// 8
// 0 1 10
// 1 2 10
// 2 3 10
// 0 3 40
// 3 4 2
// 4 5 3
// 5 6 3
// 4 6 8

	vector<vector<Edge>> graph = constructGraphFromInput();
	PrimsAlgorithm(graph);
}