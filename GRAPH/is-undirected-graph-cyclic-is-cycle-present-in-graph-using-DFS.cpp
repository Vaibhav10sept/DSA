#include <bits/stdc++.h>
using namespace std;

bool dfs(vector<vector<int>> graph, int vertex, int parentVertex, vector<bool> &visited) {
	//mark as visited
	visited[vertex] = true;

	for (int adj : graph[vertex]) {
		if (visited[adj]) {
			if (adj != parentVertex) {
				return true;
			}
		}
		else { //not visited
			if (dfs(graph, adj, vertex, visited)) return true;
		}
	}
	return false;
}



bool isUndirectedGraphCyclic(vector<vector<int>> edges, int n) {
	//create graph from the edges(given in parameter)
	vector<vector<int>> graph(n);
	for (vector<int> vec : edges) { //NOTE: -1 coz vertex are given in 1 based indexing in the question soo -1 se 0 based indexing me convert kr dia(cs)
		graph[vec[0] - 1].push_back(vec[1] - 1);
		graph[vec[1] - 1].push_back(vec[0] - 1); //undirected graph hai to dono vertex me push hogi(think, cs)
	}

	//get connected components vala for loop
	vector<bool> visited(n, false);
	for (int i = 0; i < graph.size(); i++) {
		if (visited[i] == false) {
			if (dfs(graph, i, -1, visited)) {
				return true; //yes the graph is cyclic
			}
		}
	}
	return false;
}

int main() {
	/************************************************************
	//VIDEO LINK: https://www.youtube.com/watch?v=Y9NFqI6Pzd4
	* QUESTION: https://www.codingninjas.com/studio/problems/1062670?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website
	//************************************************************/
	// int n = 3;
	// vector<vector<int>> edges = {{1, 2}, {2, 3}, {1, 3}};

	int n = 3;
	vector<vector<int>> edges = {{1, 2}, {2, 3}};

	if (isUndirectedGraphCyclic(edges, n)) {
		cout << "yes cyclic" << endl;
	}
	else {
		cout << "non cyclic" << endl;
	}
}