#include <bits/stdc++.h>
using namespace std;

class Edge {
public:
	int source;
	int neighbour;

	Edge(int src, int nbr) {
		source = src;
		neighbour = nbr;
	}
};

vector<vector<Edge>> constructGraphFromInput() {
	int vertices;
	int edges;
	cin >> vertices >> edges;
	vector<vector<Edge>> graph(vertices);
	for (int i = 0; i < edges; i++) {
		int v1, v2;
		cin >> v1 >> v2;
		graph[v1].push_back(Edge(v1, v2));
		graph[v2].push_back(Edge(v2, v1));
	}
	return graph;
}

void getSingleConnectedComponent(vector<vector<Edge>> graph, int src, vector<int> &comp, vector<bool> &visited) {
	visited[src] = true;
	comp.push_back(src);

	for (Edge edge : graph[src]) {
		if (visited[edge.neighbour] == false) {
			getSingleConnectedComponent(graph, edge.neighbour, comp, visited);
		}
	}
}

void getConnectedComponents(vector<vector<Edge>> graph, vector<vector<int>> &comps) {
	vector<bool> visited(graph.size(), false);

	for (int vertix = 0; vertix < graph.size(); vertix++) {
		if (visited[vertix] == false) { //visit nahi hue hai
			vector<int> comp;

			getSingleConnectedComponent(graph, vertix, comp, visited);
			comps.push_back(comp);
		}
	}
}

void perfectFriend(vector<vector<Edge>> graph) {
	vector<vector<int>> components;
	getConnectedComponents(graph, components);
	int ans = 0;
	for (int i = 0; i < components.size() - 1; i++) {
		for (int j = i + 1; j < components.size(); j++) {
			ans += components[i].size() * components[j].size();
		}
	}
	cout << ans << endl;
}

int main() {
	//************************************************************
	//VIDEO LINK: https://www.youtube.com/watch?v=_q4hA01ZcVQ&list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk&index=536
	//NOTE: prerequisite is "get connected component"
	//************************************************************
	// INPUT:
// 7
// 5
// 0 1
// 2 3
// 4 5
// 5 6
// 4 6

	vector<vector<Edge>> graph = constructGraphFromInput();
	perfectFriend(graph);
}