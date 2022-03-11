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

int main() {
	//************************************************************
	//VIDEO LINK: https://www.youtube.com/watch?v=dRqO3s14_2s&list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk&index=526
	//NOTE: prerequisite/dependency on "get-connected-components"
	//************************************************************
	// INPUT:
	// 7
	// 5
	// 0 1 10
	// 2 3 10
	// 4 5 10
	// 5 6 10
	// 4 6 10

	vector<vector<Edge>> graph = constructGraphFromInput();
	vector<vector<int>> ans;
	getConnectedComponents(graph, ans);
	if (ans.size() == 1) {
		cout << "The graph is connected" << endl;
	}
	else {
		cout << "The graph is not connected" << endl;
	}
}