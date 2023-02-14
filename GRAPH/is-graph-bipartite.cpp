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

class UtilPair {
public:
	int vertix;
	string path;
	int level;

	UtilPair(int vertix, string path, int level) {
		this->vertix = vertix;
		this->path = path;
		this->level = level;
	}
};

bool breadthFirstTraversal(vector<vector<Edge>> graph, int src, vector<int> &visited) {
	queue<UtilPair> q;
	q.push(UtilPair(src, to_string(src), 0));
	while (!q.empty()) {
		//step 1. remove
		UtilPair removed = q.front();
		q.pop();

		//check if already visited. if yes, That means it has cycle(think, WV)
		if (visited[removed.vertix] != -1) {//means visit ho chuka hai, or cycle hai
			// now, check for even/odd cycle.
			// if odd cycle -> not bipartite
			// if even cycle -> bipartite
			// agr same level pe nhi revisit hua to odd lenght cycle h, means bipartite nhi h(WV recommended)
			// agr same level pe revisit hua to even lenght cycle h, means bipartite hai(WV recommended)
			if (removed.level != visited[removed.vertix]) { //means odd cycle hai
				return false;
			}
		}

		//step 2. mark as visited.
		visited[removed.vertix] = removed.level;


		//step 3. add unvisited neighbours
		for (Edge edge : graph[removed.vertix]) {
			if (visited[edge.neighbour] == -1) {//add only unvisited neighbour
				q.push(UtilPair(edge.neighbour, removed.path + to_string(edge.neighbour), removed.level + 1));
			}
		}
	}
	return true;
}

bool isGraphBipartite(vector<vector<Edge>> graph) {
	vector<int> visited(graph.size(), -1); //it will store the level in which vertix has been visited, -1 for unvisited vertix

	//get connected components vala logic used here, kyoki graph disconnected bhi ho skta hai
	for (int v = 0; v < graph.size(); v++) {
		if (visited[v] == -1) {
			if (breadthFirstTraversal(graph, v, visited) == false) {
				return false;
			}
		}
	}
	return true;
}

int main() {
	//************************************************************
	// VIDEO LINK: https://www.youtube.com/watch?v=ZBhZ1DXGrhA&list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk&index=532
	// NOTE: if it is possible to divide vertixes into two mutually exclusive
	// exhaustive sets such that all edges are across sets, then the graph
	// is bipartite.
	// LOGIC: 1) acyclic graph -> bipartite
	// 2) cyclic graph, even size cycle -> bipartite (division is possible)
	// 3) cyclic graph, odd size cycle -> not bipartite (division is not possible)
	// NOTE: prerequisite is "is graph cyclic", used "BST" here
	//************************************************************
	// INPUT:
	// 7
	// 8
	// 0 1 10
	// 1 2 10
	// 2 3 10
	// 0 3 10
	// 3 4 10
	// 4 5 10
	// 5 6 10
	// 4 6 10

	vector<vector<Edge>> graph = constructGraphFromInput();
	if (isGraphBipartite(graph)) {
		cout << "yes the graph is bipartite" << endl;
	}
	else {
		cout << "no the graph is not bipartite" << endl;
	}
}