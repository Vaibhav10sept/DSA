#include <bits/stdc++.h>
using namespace std;

void topologicalSort(vector<vector<int>> graph, int node, vector<bool> &visited, stack<int> &st) {
	visited[node] = true;

	for (auto neighbour : graph[node]) {
		if (!visited[neighbour]) {
			topologicalSort(graph, neighbour, visited, st);
		}
	}

	st.push(node);
}

void dfs(vector<vector<int>> reversedGraph, int node, vector<bool> &visited) {
	visited[node] = true;

	for (auto neighbour : reversedGraph[node]) {
		if (!visited[neighbour]) {
			dfs(reversedGraph, neighbour, visited);
		}
	}
}

int countStronglyConnectedComponents(vector<vector<int>> graph) {
	// * STEPS: 1. do the topological sorting
	//  * 2. reverse all the edges of the graph(crucial step, intuitive, WV)
	//  * 3. just like commented components, do a DFS in the order of the finishing time(topological sort) and find the count of strongly connected components.
	int n = graph.size();
	vector<bool> visited(n, false);
	stack<int> st;

	//step1:
	//call for the topological sort
	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			topologicalSort(graph, i, visited, st);
		}
	}

	//step2: create a reverse graph
	vector<vector<int>> reversedGraph(n);

	for (int i = 0; i < n; i++) {
		for (auto neighbour : graph[i]) {
			//now think, here we are reversing the node
			reversedGraph[neighbour].push_back(i);
		}
	}

	//step3:
	vector<bool> visited2(n, false);

	int countOfStronglyConnectedComponents = 0;
	while (!st.empty()) {
		int node = st.top();
		st.pop();

		if (!visited2[node]) { //similar code pattern to get connected components
			countOfStronglyConnectedComponents++;
			dfs(reversedGraph, node, visited2);
		}
	}

	return countOfStronglyConnectedComponents;
}

int main() {
	/************************************************************
	 * NOTE: only applicable for directed graphs
	 * STRONG PREREQUISITE: topological sorting
	 * STEPS: 1. do the topological sorting
	 * 2. reverse all the edges of the graph(crucial step, intuitive, WV)
	 * 3. just like connected components, do a DFS and find the count of strongly connected components.
	//VIDEO LINK: https://www.youtube.com/watch?v=R6uoSjZ2imo&list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw&index=28
	DEFINE: A directed graph is strongly connected if there is a path between all pairs of vertices. A strongly connected component (SCC) of a directed graph is a maximal strongly connected subgraph.
	//************************************************************/
	int n = 5;
	int edges[5][2] = {
		{1, 0}, {0, 2},
		{2, 1}, {0, 3},
		{3, 4}
	};
	vector<vector<int>> graph(n);
	for (int i = 0; i < n; i++) {
		graph[edges[i][0]].push_back(edges[i][1]);
	}


	cout << "The number of strongly connected components is: " << countStronglyConnectedComponents(graph) << endl;
}