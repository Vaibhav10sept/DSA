#include<bits/stdc++.h>
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
	int acquiredBy;
	int weight;

	UtilPair(int vertix, int acquiredBy, int weight) {
		this->vertix = vertix;
		this->acquiredBy = acquiredBy;
		this->weight = weight;
	}
};

//we are doing operator overloading so that we can implement priority queue.
bool operator<(const UtilPair p1, const UtilPair p2) {
	return p1.weight > p2.weight; //min heap
}

int PrimsAlgorithm(vector<vector<Edge>> graph) {
	//isme maene ek totalCost vala variable add kia, baki pura same graph folder se copy kia
	priority_queue<UtilPair> q;
	int totalCost = 0;
	q.push(UtilPair(0, -1, 0));
	vector<bool> visited(graph.size());
	while (!q.empty()) {
		//step 1. removes
		UtilPair removed = q.top();
		q.pop();

		//check if already visited
		if (visited[removed.vertix]) {
			continue;
		}

		//step 2. mark visited
		visited[removed.vertix] = true;

		//step 3. work(print)
		if (removed.acquiredBy != -1) {
			totalCost += removed.weight;
			// cout << removed.vertix << " - " << to_string(removed.acquiredBy) << " @ " << removed.weight << endl;
		}

		//step 4. add its unvisited neighbour
		for (Edge edge : graph[removed.vertix]) {
			if (visited[edge.neighbour] == false) {
				q.push(UtilPair(edge.neighbour, removed.vertix, edge.weight));
			}
		}
	}
	return totalCost;
}

//ABOVE CODE IS COPIED FROM PRIMS ALGO --> IN GRAPH FOLDER

int minCostToConnectAllPoints(vector<vector<int>> arr) {
	//create graph(adjacency list) using given arr.
	int n = arr.size();
	vector<vector<Edge>> graph(n);
	for (int i = 0; i < n; i++) {
		int x1 = arr[i][0];
		int y1 = arr[i][1];
		for (int j = i + 1; j < n; j++) {
			int x2 = arr[j][0];
			int y2 = arr[j][1];
			//find the manhattan dist, which is the weight of the edge
			int dist = abs(x1 - x2) + abs(y1 - y2);
			//create graph, see the graph folder for better understanding.
			//i, j will be the vertices and dist will be the weight

			graph[i].push_back(Edge(i, j, dist));
			graph[j].push_back(Edge(j, i, dist));
		}
	}
	//now, graph is ready, perform prim algo in this graph to get the min cost.
	return PrimsAlgorithm(graph);
}

int main() {
	/*
	NOTE: based on min spanning tree--> prim algorithm(done in graphs folder)
	PREREQUISITE: prim's algorithm(search prim, already done before)
	VIDEO LINK: https://www.youtube.com/watch?v=f7JOBJIC-NA
	LEETCODE LINK:
	*/
	vector<vector<int>> points = {{0, 0}, {2, 2}, {3, 10}, {5, 2}, {7, 0}};
	cout << "result" << endl;
	cout << minCostToConnectAllPoints(points);
}