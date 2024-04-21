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
	int weight;

	UtilPair(int vertix, string path, int weight) {
		this->vertix = vertix;
		this->path = path;
		this->weight = weight;
	}
};

//we are doing operator overloading so that we can implement priority queue.
bool operator<(const UtilPair p1, const UtilPair p2) {
	//min heap
	return p1.weight > p2.weight;
}

vector<int> dijsktrasAlgorithm(vector<vector<int>> graph[], int src, int V) {
	// Create a priority queue for storing the nodes as a pair {dist,node}
	// where dist is the distance from source to the node.
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q; //min heap
	q.push({0, src});
	vector<int> distance(V);
	vector<bool> visited(V);
	while (!q.empty()) {
		//step 1. remove
		int node = q.top().second;
		int dist = q.top().first;
		q.pop();

		//check if already visited
		if (visited[node]) {
			continue;
		}

		//step 2. mark visited
		visited[node] = true;

		//step 3. work(print)
		distance[node] = dist;
		// cout << node << " via " << removed.path << " @ " << removed.weight << endl;

		//step 4. add its unvisited neighbour
		for (auto edge : graph[node]) {
			if (visited[edge[0]] == false) {
				q.push({dist + edge[1], edge[0]});
			}
		}
	}
	return distance;
}

int main() {
	//************************************************************
	// NOTE: dijsktra algo is not applicable for negative weights. for negative weight use bellman ford algo
	//VIDEO LINK: https://www.youtube.com/watch?v=V6H1qAeB-l4&list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw&index=20
	// QUESTION: https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1
	//NOTE: we use priority queue data structure here
	//NOTE: dijkstra's algo -> shortest path in terms of weight
	//NOTE: to find shortest path in terms of edge use BFS.
	//NOTE: the only diff betweeen dijkstra's algo and BFS is we use
	//priority queue in dijkstra's algo
	//STEPS: remove, mark(visited), work(print), add
	//************************************************************

	int V = 2;
	vector<vector<int>> graph[] = {{{1, 9}}, {{0, 9}}};
	int src = 0;

	vector<int> ans = dijsktrasAlgorithm(graph, src, V);
	for (auto ele : ans) cout << ele << " ";
}