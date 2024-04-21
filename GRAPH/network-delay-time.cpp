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

vector<vector<Edge>> constructDirectedGraphFromInput(vector<vector<int>> edges, int n) {
	vector<vector<Edge>> graph(n);
	for (auto edge : edges) {
		int v1 = edge[0] - 1;
		int v2 = edge[1] - 1;
		int wt = edge[2];
		graph[v1].push_back(Edge(v1, v2, wt));
	}
	return graph;
}

class UtilPair {
public:
	int vertix;
	string path;
	int weight;

	UtilPair(int vertix, string path, int weight) {
		this->vertix = vertix;
		this->path = path;
		this->weight = weight;
	}
};

// Define a custom comparator functor
class MyItemComparator {
public:
	bool operator()( UtilPair& item1, UtilPair& item2) {
		// min heap --> minimum weight vala top me rhega
		return item1.weight > item2.weight;
	}
};

int networkDelayTime(vector<vector<int>> edges, int n, int src) {
	// * NOTE: wrote it myself without any video or reading
	src = src - 1; //coz question me vertixes 1 based indexing me die or to hm use -1 krke 0 based indexing me convert kr rhe hai
	vector<vector<Edge>> graph = constructDirectedGraphFromInput(edges, n);
	priority_queue<UtilPair, vector<UtilPair>, MyItemComparator> q; //min heap
	q.push(UtilPair(src, to_string(src), 0));
	vector<bool> visited(graph.size());
	int totalWeight = 0;
	int countOfVisited = 0;

	while (!q.empty()) {
		//step 1. remove
		UtilPair removed = q.top();
		q.pop();

		//check if already visited
		if (visited[removed.vertix]) {
			continue;
		}

		//step 2. mark visited and do all the work
		visited[removed.vertix] = true;
		countOfVisited++;
		totalWeight += removed.weight;

		if (countOfVisited == n) {
			return removed.weight;
		}

		//step 4. add its unvisited neighbour
		for (Edge edge : graph[removed.vertix]) {
			if (visited[edge.neighbour] == false) {
				cout << "push " << edge.neighbour << endl;
				q.push(UtilPair(edge.neighbour, removed.path + to_string(edge.neighbour), removed.weight + edge.weight));
			}
		}
	}

	return -1;
}

int main() {
	/************************************************************
	 * NOTE: wrote it myself without any video or reading
	//VIDEO LINK:
	QUESTION: https://leetcode.com/problems/network-delay-time/
	//NOTE:
	//NOTE: breadth first traversal is same as the level order traversal of tree.
	//NOTE: BFS give you smaller path as compared to DFS.
	//************************************************************/

	// vector<vector<int>> times = {{2, 1, 1}, {2, 3, 1}, {3, 4, 1}};
	vector<vector<int>> times = {{1, 2, 1}, {2, 3, 2}, {1, 3, 1}};
	int n = 3;
	int k = 2;
	cout << networkDelayTime(times, n, k);
}