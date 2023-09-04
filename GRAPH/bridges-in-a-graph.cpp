#include <bits/stdc++.h>
using namespace std;

vector < vector<int>> constructGraph(vector < vector<int>> edges, int V) {
	vector < vector<int>> graph(V);

	for (int i = 0; i < edges.size(); i++) {
		int v = edges[i][0];
		int u = edges[i][1];

		graph[v].push_back(u);
		graph[u].push_back(v); //coz undirected graph h, bridges in graph ka question undirected graph me hi hota hai.
	}

	return graph;
}

void dfs(int node, int parent, vector<bool> &visited, vector<int> &discoveryTime,
         vector<int> &lowestTime, int &timer, vector<vector<int>> &result, vector<vector<int>> & graph) {
	//WV recommended
	visited[node] = true;
	discoveryTime[node] = lowestTime[node] = timer;
	timer++;

	for (int neighbour : graph[node]) {

		if (neighbour == parent) {
			continue;
		}

		if (!visited[neighbour]) {
			dfs(neighbour, node, visited, discoveryTime, lowestTime, timer, result, graph);

			//post recursive phase
			lowestTime[node] = min(lowestTime[neighbour], lowestTime[node]);

			//check if the edges between you(node) and your neighbour is a bridge or not.
			if (lowestTime[neighbour] > discoveryTime[node]) { //there is a bridge(think, CS, WV)
				vector<int> ans;
				ans.push_back(node);
				ans.push_back(neighbour);
				result.push_back(ans);
			}
		}
		else { //neighbour is already visited and not parent.
			//means it is a back edge
			lowestTime[node] = min(lowestTime[node], discoveryTime[neighbour]);
		}
	}
}

vector<vector<int>> getBridgesInAGraph(vector<vector<int>> graph) {
	int n = graph.size();
	vector<int> discoveryTime(n, -1);
	vector<int> lowestTime(n, -1);
	int timer = 0;
	int parent = -1;
	vector<bool> visited(n, false);
	vector<vector<int>> result;

	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			dfs(i, parent, visited, discoveryTime, lowestTime, timer, result, graph);
		}
	}

	return result;
}

int main() {
	/************************************************************
	 * NOTE: we use DFS here
	 * PREREQUISITE: DFS
	 * QUESTION: https://practice.geeksforgeeks.org/problems/bridge-edge-in-graph/1
	 * QUESTION: https://www.codingninjas.com/codestudio/problem-details/bridges-in-graph_893026
	 VIDEO: https://www.youtube.com/watch?v=qrAub5z8FeA&list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw&index=29
	 VIDEO FOR CODE: https://www.youtube.com/watch?v=CiDPT1xMKI0
	DEFINE: An edge in an undirected connected graph is a bridge if removing it disconnects the graph. For a disconnected undirected graph, the definition is similar, a bridge is an edge removal that increases the number of disconnected components.
	//************************************************************/
	int V = 5;
	int E = 3;
	vector<vector<int>> edges = {{0, 1}, {3, 1}, {1, 2}, {3, 4}};

	vector<vector<int>> graph = constructGraph(edges, V);

	vector<vector<int>> ans = getBridgesInAGraph(graph);

	//print the answer
	for (auto vec : ans) {
		for (auto ele : vec) {
			cout << ele << " ";
		}
		cout << endl;
	}
}