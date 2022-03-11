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

void printHamiltonianPathAndCycle(vector<vector<Edge>> graph, int src, set<int> &visited, string path, int originalSource) {
	if (visited.size() == graph.size() - 1) {// -1 think about it.
		// path += to_string(src);
		cout << path;
		bool isHamiltonianCycle = false;
		for (Edge edge : graph[src]) {
			if (edge.neighbour == originalSource) {
				isHamiltonianCycle = true;
				break;
			}
		}
		if (isHamiltonianCycle) {
			cout << "*" << endl; // we are printing '*' as this is given in the question
		}
		else {
			cout << "." << endl; // we are printing '.' as this is given in the question
		}
		return;
	}
	//bc ends

	visited.insert(src);
	for (Edge edge : graph[src]) {
		if (visited.find(edge.neighbour) == visited.end()) {
			printHamiltonianPathAndCycle(graph, edge.neighbour, visited, path + to_string(edge.neighbour), originalSource);
		}
	}
	//backtrack
	visited.erase(src);
}

int main() {
	//************************************************************
	//VIDEO LINK: https://www.youtube.com/watch?v=nUgp0RG57wQ&list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk&index=528
	//NOTE: similar to "print all paths"
	//we need to backtrack in this question similar to "print all paths"
	//************************************************************
	// INPUT:
// 7
// 9
// 0 1 10
// 1 2 10
// 2 3 10
// 0 3 10
// 3 4 10
// 4 5 10
// 5 6 10
// 4 6 10
// 2 5 10
	// 0

	vector<vector<Edge>> graph = constructGraphFromInput();
	int src;
	cin >> src;
	set<int> visited;
	printHamiltonianPathAndCycle(graph, src, visited, to_string(src), src);
}