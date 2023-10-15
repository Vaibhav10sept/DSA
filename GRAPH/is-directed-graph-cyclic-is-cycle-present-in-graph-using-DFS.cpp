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

vector<vector<Edge>> constructDirectedGraphFromInput() {
	int vertices;
	int edges;
	cin >> vertices >> edges;
	vector<vector<Edge>> graph(vertices);
	for (int i = 0; i < edges; i++) {
		int v1, v2, wt;
		cin >> v1 >> v2 >> wt;
		graph[v1].push_back(Edge(v1, v2, wt));
		graph[v2].push_back(Edge(v2, v1, wt)); // uncommented this line for the directed graph
	}
	return graph;
}

bool DepthFirstTraversal(vector<vector<Edge>> graph, int vertex, vector<bool> isPathVisited, vector<bool> visited) {
	//NOTE: base case(jo for loop ke 'if' me kia hai) vo hm yha pe bhi kr skte hai, in this question, but undirected graph cycle detection using dfs me ni kr skte think, cs, wv, dry run

	//mark visited
	visited[vertex] = true;
	//mark the path visited
	isPathVisited[vertex] = true;

	for (auto edge : graph[vertex]) {
		if (visited[edge.neighbour]) {
			if (isPathVisited[edge.neighbour]) {
				return true; //visited and path visited also so has cycle return true;
			}
			else {
				return false; //visited but no cycle -> no need to move further as this node is already visited,
			}
		}
		else {
			if (DepthFirstTraversal(graph, edge.neighbour, isPathVisited,
			                        visited)) {
				return 1;
			}
		}
	}

	//backtrack -> remove from the path visited (think, cs, WV)
	isPathVisited[vertex] = false;

	return false;
}

bool isDirectedGraphCyclicDFS(vector<vector<Edge>> graph) {
	vector<bool> visited(graph.size(), false);
	vector<bool> isPathVisited(graph.size(), false);

	//get connected components vala logic
	for (int v = 0; v < graph.size(); v++) {
		if (visited[v] == false) {
			if (DepthFirstTraversal(graph, v, isPathVisited, visited)) {
				return true;
			}
		}
	}
	return false;
}

int main() {
	/************************************************************
	//VIDEO LINK: https://www.youtube.com/watch?v=9twcmtQj4DU&list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw&index=12
	* QUESTION: https://leetcode.com/problems/course-schedule/submissions/
	//NOTE:
	//************************************************************/
	// INPUT:
// 7
// 6
// 0 1 10
// 1 2 10
// 2 3 10
// 3 4 10
// 4 5 10
// 5 6 10

	vector<vector<Edge>> graph = constructDirectedGraphFromInput();
	if (isDirectedGraphCyclicDFS(graph)) {
		cout << "yes the graph is cyclic" << endl;
	}
	else {
		cout << "no the graph is not cyclic" << endl;
	}
}