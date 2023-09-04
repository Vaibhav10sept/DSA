#include <bits/stdc++.h>
using namespace std;

bool dfs(int vertex, int colour, vector<vector<int>> graph, vector<int> &visited) {
	//mark visited
	visited[vertex] = colour;

	//traverse for all the adjacent vertex
	for (int adj : graph[vertex]) {
		if (visited[adj] != -1) { //already visited
			if (visited[adj] == colour) {
				return false; //not bipartite
			}
		}
		else { //not visited
			if (dfs(adj, colour == 1 ? 0 : 1, graph, visited) == false) { //not bipartite
				return false;
			}
		}
	}
	return true;
}

bool isGraphBipartite(vector<vector<int>>& graph) {
	vector<int> visited(graph.size(), -1); //it will store the colour in which vertix has been visited, -1 for unvisited vertix

	//get connected components vala logic used here, kyoki graph disconnected bhi ho skta hai
	for (int v = 0; v < graph.size(); v++) {
		if (visited[v] == -1) {
			if (dfs(v, 0, graph, visited) == false) {
				return false;
			}
		}
	}
	return true;
}

int main() {
	/************************************************************
	 * STRONG PREQ: is-undirected-graph-cyclic-is-cycle-present-in-graph-using-DFS
	// VIDEO LINK: https://www.youtube.com/watch?v=KG5YFfR0j8A
	// LEETCODE: https://leetcode.com/problems/is-graph-bipartite/submissions/
	// NOTE: if it is possible to divide vertixes into two mutually exclusive
	// exhaustive sets such that all edges are across sets, then the graph
	// is bipartite.
	// LOGIC: 1) acyclic graph -> bipartite
	// 2) cyclic graph, even size cycle -> bipartite (division is possible)
	// 3) cyclic graph, odd size cycle -> not bipartite (division is not possible)
	DEFINATION: A Bipartite Graph is a graph whose vertices can be divided into two
	independent sets, U and V such that every edge (u, v) either connects a vertex from U to V or a vertex from V to U.
	//************************************************************/
	vector<vector<int>> graph = {{1, 2, 3}, {0, 2}, {0, 1, 3}, {0, 2}};

	if (isGraphBipartite(graph)) {
		cout << "yes the graph is bipartite" << endl;
	}
	else {
		cout << "no the graph is not bipartite" << endl;
	}
}