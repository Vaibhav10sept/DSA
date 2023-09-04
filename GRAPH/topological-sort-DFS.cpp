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
		// graph[v2].push_back(Edge(v2, v1));
	}
	return graph;
}

void topologicalSortHelper(vector<vector<Edge>> graph, int src, vector<bool> &visited, stack<int> &st) {
	visited[src] = true;
	for (Edge edge : graph[src]) {
		if (visited[edge.neighbour] == false) {
			topologicalSortHelper(graph, edge.neighbour, visited, st);
		}
	}
	//post order phase of recursion me stack me push kr rhe hai
	st.push(src);
}

void topologicalSort(vector<vector<Edge>> graph) {
	vector<bool> visited(graph.size(), false);
	stack<int> st;
	for (int i = 0; i < graph.size(); i++) { //LOGIC: like get connected components
		if (visited[i] == false) {
			topologicalSortHelper(graph, i, visited, st);
		}
	}
	while (!st.empty()) {
		cout << st.top() << endl;
		st.pop();
	}
}

int main() {
	/************************************************************
	 * NOTE: same question BFS/kahn's algrithm se bhi kia h dekh lo
	 * NOTE: DAG(directed acyclic graph) ke liye bhi topological sorting possible h
	 * NOTE: acyclic, directed graph ki hi topological sorting possible ho skti h(think, CS)
	 * agr cycle h ya undirected graph h to ordering possible nhi ho skti(think, CS)
	DEFINE: A topological sort (sometimes also called a linearization) of a directed graph is a list of the vertices in such an order that if there is a directed path from vertex v to vertex w , then v precedes w in the list. (The graph must be acyclic in order for this to work.
	//VIDEO LINK: https://www.youtube.com/watch?v=6Vi5Td_a8B8&list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk&index=538
	//NOTE: we use depth first traversal here.
	//************************************************************/

	// INPUT:
// 7
// 7
// 0 1
// 1 2
// 2 3
// 0 3
// 4 5
// 5 6
// 4 6
	vector<vector<Edge>> graph = constructGraphFromInput();
	topologicalSort(graph);
}