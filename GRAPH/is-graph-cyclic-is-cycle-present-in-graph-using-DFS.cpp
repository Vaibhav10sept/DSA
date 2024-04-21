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

bool DepthFirstTraversal(vector<vector<Edge>> graph, int vertex, int parent, vector<bool> visited) {

	if (visited[vertex] == true and parent != vertex) return true; //means already visited by another parent so return true means has cycle

	//mark visited
	visited[vertex] = true;

	for (auto edge : graph[vertex]) {
		if (visited[edge.neighbour] == false) {
			if (DepthFirstTraversal(graph, edge.neighbour, vertex, visited)) {
				return true;
			}
		}
	}

	return false;
}

bool isGraphCyclicDFS(vector<vector<Edge>> graph) {
	vector<bool> visited(graph.size(), false);

	//get connected components vala logic
	for (int v = 0; v < graph.size(); v++) {
		if (visited[v] == false) {
			if (DepthFirstTraversal(graph, v, -1, visited)) {
				return true;
			}
		}
	}
	return false;
}

int main() {
	//************************************************************
	//VIDEO LINK: https://www.youtube.com/watch?v=zQ3zgFypzX4&list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw&index=8
	//NOTE:
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
	if (isGraphCyclicDFS(graph)) {
		cout << "yes the graph is cyclic" << endl;
	}
	else {
		cout << "no the graph is not cyclic" << endl;
	}
}