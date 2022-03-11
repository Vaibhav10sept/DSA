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

void spreadInfection(vector<vector<Edge>> graph, int src, int time) {
	queue<UtilPair> q;
	int countOfPeopleInfected = 0;
	q.push(UtilPair(src, to_string(src), 1));
	vector<bool> visited(graph.size());
	while (!q.empty()) {
		//step 1. remove
		UtilPair removed = q.front();
		q.pop();

		//check if already visited
		if (visited[removed.vertix]) {
			continue;
		}

		countOfPeopleInfected++;

		if (removed.level == time)
			break;

		//step 2. mark visited
		visited[removed.vertix] = true;

		//step 4. add its unvisited neighbour
		for (Edge edge : graph[removed.vertix]) {
			if (visited[edge.neighbour] == false) {
				q.push(UtilPair(edge.neighbour, removed.path + to_string(edge.neighbour), removed.level + 1));
			}
		}
	}
	cout << "countOfPeopleInfected " << countOfPeopleInfected << endl;
}

int main() {
	//************************************************************
	//VIDEO LINK: https://www.youtube.com/watch?v=3A1XJbRs_6A&list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk&index=532
	//NOTE: we use "breadth first traversal" here
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
	// 6
	// 3

	vector<vector<Edge>> graph = constructGraphFromInput();
	int src;
	cin >> src;
	int time;
	cin >> time;
	spreadInfection(graph, src, time);
}