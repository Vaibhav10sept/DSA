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

vector<vector<int>> constructGraphFromInput() {
	int vertices;
	int edges;
	cin >> vertices >> edges;
	vector<vector<int>> graph(vertices);
	for (int i = 0; i < edges; i++) {
		int v1, v2;
		cin >> v1 >> v2;
		graph[v1].push_back(v2);
		// graph[v2].push_back(Edge(v2, v1));
	}
	return graph;
}

vector<int> topologicalSort(vector<vector<int>> graph) {
	//using BFS

	//step 1: find the indegree of all the vertixes
	vector<int> indegree(graph.size(), 0);
	for (int i = 0; i < graph.size(); i++) {
		for (auto edge : graph[i]) {
			indegree[edge]++;
		}
	}

	//step 2: put the 0 indegree into the queue
	queue<int> q;
	for (int i = 0; i < indegree.size(); i++) {
		if (indegree[i] == 0) {
			q.push(i);
		}
	}

	vector<int> ans;
	while (!q.empty()) {
		int removedNode = q.front();
		q.pop();
		ans.push_back(removedNode);

		//reduce the indegree of all adjacent node from the remove node
		for (int edge : graph[removedNode]) {
			indegree[edge]--;
			if (indegree[edge] == 0) {
				q.push(edge);
			}
		}
	}

	return ans;
}

int main() {
	/************************************************************
	 * NOTE: same question DFS se bhi kia h dekh lo
	 * NOTE: DAG(directed acyclic graph) ke liye bhi topological sorting possible h
	 * NOTE: acyclic, directed graph ki hi topological sorting possible ho skti h(think, CS)
	 * agr cycle h ya undirected graph h to ordering possible nhi ho skti(think, CS)
	DEFINE: A topological sort (sometimes also called a linearization) of a directed graph is a list of the vertices in such an order that if there is a directed path from vertex v to vertex w , then v precedes w in the list. (The graph must be acyclic in order for this to work.
	//VIDEO LINK: https://www.youtube.com/watch?v=73sneFXuTEg&list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw&index=14
	//NOTE: we use BFS here.
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
	vector<vector<int>> graph = constructGraphFromInput();
	vector<int> ans = topologicalSort(graph);
	cout << "topological sort:" << endl;
	for (auto it : ans) cout << it << " ";
	cout << endl;
}