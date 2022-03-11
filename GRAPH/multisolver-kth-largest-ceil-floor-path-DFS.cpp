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
	string path;
	int weight;
	UtilPair(int wt, string path) {
		weight = wt;
		this->path = path;
	}
};

//some global variables
int smallestWeightPath = INT_MAX;
string smallestPath = "";
int largestWeightPath = INT_MIN;
string largestPath = "";
int ciel = INT_MAX;
string cielPath = "";
int floorWt = INT_MIN;
string floorWtPath = "";
priority_queue<UtilPair> pq;
// we are doing operator overloading through this
bool operator<(const UtilPair& p1, const UtilPair& p2)
{
	//HERE, WE ARE MAKING MIN PRIORITY QUEUE.(MEANS SMALLEST VALUE WILL BE ON TOP)
	return p1.weight > p2.weight;
}

void multiSolver(vector<vector<Edge>> graph, int src, int dest, vector<bool> &visited, string path, int weight, int vertix, int k) {
	//bc
	if (src == dest) {
		//find k larger paths
		if (pq.size() < k) {
			pq.push(UtilPair(weight, path));
		}
		else {
			if (pq.top().weight < weight) {
				pq.pop();
				pq.push(UtilPair(weight, path));
			}
		}
		//ceil
		if (weight >= vertix) {
			if (weight < ciel) {
				cielPath = path;
				ciel = weight;
			}
		}
		//floor
		if (weight < vertix) {
			if (weight > floorWt) {
				floorWtPath = path;
				floorWt = weight;
			}
		}
		//largest path
		if (weight > largestWeightPath) {
			largestWeightPath = weight;
			largestPath = path;
		}
		//smallest path
		if (weight < smallestWeightPath) {
			smallestWeightPath = weight;
			smallestPath = path;
		}
		cout << path << " @ " << weight << endl;
		return;
	}
	//bc ends

	visited[src] = true;
	for (Edge edge : graph[src]) {
		if (visited[edge.neighbour] == false) {
			multiSolver(graph, edge.neighbour, dest, visited, path + to_string(edge.neighbour), weight + edge.weight, vertix, k);
		}
	}
	//backtrack(think, same logic as in "floodFill"(recursion))
	visited[src] = false;
}

int main() {
	//************************************************************
	//VIDEO LINK: https://www.youtube.com/watch?v=PSy0yJQx050&list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk&index=524
	//NOTE: prerequisite is "all path"
	//NOTE: ciel -> just larger or smallest in larger
	//NOTE: floorWt -> just smaller or largest in smaller
	//************************************************************
	// INPUT:
	// 7
	// 9
	// 0 1 10
	// 1 2 10
	// 2 3 10
	// 0 3 40
	// 3 4 2
	// 4 5 3
	// 5 6 3
	// 4 6 8
	// 2 5 5
	// 0
	// 6
	// 30
	// 4
	vector<vector<Edge>> graph = constructGraphFromInput();
	int src, dest, k, vertix;
	cin >> src >> dest;
	cin >> vertix >> k;
	vector<bool> visited(graph.size(), false);
	multiSolver(graph, src, dest, visited, to_string(src), 0, vertix, k);
	cout << "smallest weight path: " << smallestPath << " @ " << smallestWeightPath << endl;
	cout << "greatest weight path: " << largestPath << " @ " << largestWeightPath << endl;
	cout << "ceil of " << vertix << " is: " << cielPath << " @ " << ciel << endl;
	cout << "floor of " << vertix << " is: " << floorWtPath << " @ " << floorWt << endl;
	cout << k << " largest paths is:" << endl;
	cout << pq.top().path << " @ " << pq.top().weight << endl;
	cout << k << " larger paths are:" << endl;
	while (!pq.empty()) {
		cout << pq.top().path << " @ " << pq.top().weight << endl;
		pq.pop();
	}

}