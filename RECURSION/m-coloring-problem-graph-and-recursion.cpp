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

vector<vector<Edge>> constructGraphFromInput(vector<pair<int, int>> data, int n) {
	// n --> no of vertices
	vector<vector<Edge>> graph(n);
	for (int i = 0; i < data.size(); i++) {
		int v1, v2;
		v1 = data[i].first;
		v2 = data[i].second;
		graph[v1].push_back(Edge(v1, v2));
		graph[v2].push_back(Edge(v2, v1));
	}
	return graph;
}

bool isPossibleToPutThisColor(vector<vector<Edge>> graph, int node, int color, vector<int> colorsTracker) {
	//check for all the adjacent node/vertex of the node, if anyone has that color then return false, otherwise return true
	for (Edge edge : graph[node]) {
		if (colorsTracker[edge.neighbour] == color)
			return false;
	}

	return true;
}

bool mColoringProblem(vector<vector<Edge>> graph, int node, vector<int> colorsTracker, int n, int m) {
	if (node == n) {
		return true;
	}
	// BC ends

	//try to put all 1 to m colors in the node
	for (int color = 1; color <= m; color++) {
		if (isPossibleToPutThisColor(graph, node, color, colorsTracker)) {
			colorsTracker[node] = color;
			if (mColoringProblem(graph, node + 1, colorsTracker, n, m)) {
				return true;
			}

			//backtrack
			colorsTracker[node] = -1;
		}
	}

	//we have tried all the m colors but still kisi se bhi hme true nhi mila, islie ab hm false return krege(CS, think)
	return false;
}


int main()
{
	/*
	PREQ: soduko solver
	SAME PATTERN QUESTION: soduko solver
	NOTE: ye code mene likha, video dekhne ke baad. approach smjhli and then khud se code likh dia.
	QUESTION: https://takeuforward.org/data-structure/m-coloring-problem/
	VIDEO: https://www.youtube.com/watch?v=wuVwUK25Rfc&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=60
	*/
	int n = 4; // no of vertices
	int m = 3; //at max no of colors
	vector<pair<int, int>> edge = {
		{0, 1},
		{1, 2},
		{2, 3},
		{3, 0},
		{0, 2},
	};
	vector<vector<Edge>> graph = constructGraphFromInput(edge, n);
	vector<int> colorsTracker(n, -1);
	cout << "result " << mColoringProblem(graph, 0, colorsTracker, n, m);

}