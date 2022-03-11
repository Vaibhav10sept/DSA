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

vector<vector<int>>  constructMatrix() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> arr(n, vector<int> (m, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	return arr;
}

void getSingleConnectedIsland(vector<vector<int>> graph, int i, int j, vector<vector<bool>> &visited) {
	//bc
	if (i < 0 or j < 0 or i >= graph.size() or j >= graph[0].size() or visited[i][j] == true or graph[i][j] == 1)
	{
		return;
	}

	visited[i][j] = true;
	getSingleConnectedIsland(graph, i + 1, j, visited); //bottom
	getSingleConnectedIsland(graph, i, j + 1, visited); //right
	//NOTE: I don't think we need below two calls(my logic), I wrote them bcoz it was there in the video, answer is same in both cases
	getSingleConnectedIsland(graph, i - 1, j, visited); //top
	getSingleConnectedIsland(graph, i, j - 1, visited); //left
}

int countNumberOfIslands(vector<vector<int>> graph) {
	vector<vector<bool>> visited(graph.size(), vector<bool>(graph[0].size(), false));
	int count = 0;
	for (int i = 0; i < graph.size(); i++) {
		for (int j = 0; j < graph[0].size(); j++) {
			if (visited[i][j] == false and graph[i][j] == 0) {
				getSingleConnectedIsland(graph, i, j, visited);
				count++;
			}
		}
	}
	return count;

}

int main() {
	//************************************************************
	//VIDEO LINK: https://www.youtube.com/watch?v=ErPZFxugYkI&list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk&index=527
	//NOTE: similar is "get-connected-components"
	//************************************************************
	// INPUT:
	// 8
	// 8
	// 0 0 1 1 1 1 1 1
	// 0 0 1 1 1 1 1 1
	// 1 1 1 1 1 1 1 0
	// 1 1 0 0 0 1 1 0
	// 1 1 1 1 0 1 1 0
	// 1 1 1 1 0 1 1 0
	// 1 1 1 1 1 1 1 0
	// 1 1 1 1 1 1 1 0

	vector<vector<int>> graph = constructMatrix();
	cout << "the count of island is: " << countNumberOfIslands(graph);

}