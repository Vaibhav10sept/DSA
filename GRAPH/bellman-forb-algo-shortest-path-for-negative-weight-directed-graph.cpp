#include <bits/stdc++.h>
using namespace std;

vector<int> bellmanFord(vector<vector<int>> edges, int src, int V) {
	//WV
	//LOGIC:
	//V - 1 iteration of edges hogi to fill the distance array
	//DETECT THE NEGATIVE CYCLE: for nth iteration agar distance array update hoga, means negative cycle hai
	vector<int> distance(V, 1e9);
	distance[src] = 0; //this line is very imp don't forget to add this
	for (int i = 1; i < V; i++) { //V-1 iterations of edges vector
		for (vector<int> edge : edges) {
			int u = edge[0];
			int v = edge[1];
			int weight = edge[2];

			if (distance[u] != 1e9 and distance[u] + weight < distance[v]) {
				distance[v] = distance[u] + weight;
			}
		}
	}


	//one more iteration for edges vector to detect the negative cycle
	//agar iss iteration me distance vector update hota h, that means negative cycle is present.
	for (auto edge : edges) {
		int u = edge[0];
		int v = edge[1];
		int weight = edge[2];

		if (distance[u] != 1e9 and distance[u] + weight < distance[v]) {
			cout << "negative cycle is present" << endl;
			return { -1}; //given in question if negative cycle is present return {-1}
		}
	}

	return distance;
}

int main() {
	/************************************************************
	 * NOTE: bellman algo works for directed graph(if undirected graph is there, convert it to directed graph first(think, wv)) with negative weight but not for negative cycle
	 * NOTE: using bellman algo we can detect whether the graph has negative cycle or not, if it doesn't has negative cycle then we can find the shortest path also.
	NOTE: dijsktra algo is not applicable for negative weights. for negative weight use bellman ford algo
	VIDEO LINK: https://www.youtube.com/watch?v=ijpVpsmpJtQ&t=1175s
	QUEST: https://practice.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/1
	DEFINE: Bellman ford algorithm is a single-source shortest path algorithm. This algorithm is used to find the shortest distance from the single vertex to all the other vertices of a weighted graph. There are various other algorithms used to find the shortest path like Dijkstra algorithm, etc. If the weighted graph contains the negative weight values, then the Dijkstra algorithm does not confirm whether it produces the correct answer or not. In contrast to Dijkstra algorithm, bellman ford algorithm guarantees the correct answer even if the weighted graph contains the negative weight values.
	NOTE: bellman algo only works for DG(directed graph) for undirected graph convert DG to undirected graph(think , CS, WV)
	//************************************************************/

	vector<vector<int>> edges = {{0, 1, 5}, {1, 0, 3}, {1, 2, -1}, {2, 0, 1}};
	//do analysize the way input is given, it is not a graph, bss edge di hue hai in random sequence.
	int src = 2;
	int V = 3;
	vector<int> ans = bellmanFord(edges, src, V);
	for (auto ele : ans) cout << ele << " ";
}