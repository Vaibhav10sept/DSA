#include <bits/stdc++.h>
using namespace std;

void displayMatrix(vector<vector<int>> arr) {
	for (int i = 0; i < arr.size(); i++) {
		for (int j = 0; j < arr[i].size(); j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}

int cityWithSmallestNeighbors(vector<vector<int>> edges, int n, int distanceThreshold) {
	//WV highly recommended
	//we use floyd warshall algorithm

	//create arr(adjacency matrix) using edges
	vector<vector<int>> arr(n, vector<int>(n, 1e9));
	for (auto edge : edges) {
		int u = edge[0];
		int v = edge[1];
		int weight = edge[2];
		arr[u][v] = weight;
		arr[v][u] = weight; //bidirectional h
	}

	//we use DP here
	//storage: in arr[i][j] --> signify the min distance(cost) for vertix(node) i to j
	for (int via = 0; via < n; via++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i == j) arr[i][j] = 0;
				else {
					arr[i][j] = min(arr[i][j], arr[i][via] + arr[via][j]);
				}
			}
		}
	}
	displayMatrix(arr);
	//traverse the arr and find the nodes whose distance is under threshold distance
	int ansCity = 0;
	int lowestNoCitiesReachableUnderThershold = INT_MAX;
	for (int i = 0; i < n; i++) {

		int noOfCitiesReachable = 0;
		for (int j = 0; j < n; j++) {
			if (arr[i][j] <= distanceThreshold) {
				noOfCitiesReachable++;
			}
		}

		if (noOfCitiesReachable <= lowestNoCitiesReachableUnderThershold) {
			ansCity = i;
			lowestNoCitiesReachableUnderThershold = noOfCitiesReachable;
		}
	}
	return ansCity;
}

int main() {
	/************************************************************
	 * STRONG PREQ: floyd warshall algo
	 VIDEO: https://www.youtube.com/watch?v=PwMVNSJ5SLI
	 LINK: https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/
	DEFINE: It is an algorithm for finding the shortest path between all the pairs of vertices in a weighted graph. This algorithm follows the dynamic programming approach to find the shortest path.
	//************************************************************/

	int n = 5;
	int distanceThreshold = 2;
	vector<vector<int>> edges = {{0, 1, 2}, {0, 4, 8}, {1, 2, 3}, {1, 4, 2}, {2, 3, 1}, {3, 4, 1}};
	cout << "ans " << cityWithSmallestNeighbors(edges, n, distanceThreshold);
}