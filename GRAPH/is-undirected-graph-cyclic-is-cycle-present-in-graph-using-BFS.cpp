#include <bits/stdc++.h>
using namespace std;

bool isUndirectedGraphCyclic(vector<vector<int>> edges, int n) {
	// * NOTE: this code is writeen by me after WV
	// NOTE: the code is modified video me parentVertex ko carry krne ko bola h, but actually hme parent ki jrurt hi ni h BFS me, so mene code ko change kia, think, cs
	//create graph from the edges(given in parameter)
	vector<vector<int>> graph(n);
	for (vector<int> vec : edges) { //NOTE: -1 coz vertex are given in 1 based indexing in the question soo -1 se 0 based indexing me convert kr dia(cs)
		graph[vec[0] - 1].push_back(vec[1] - 1);
		graph[vec[1] - 1].push_back(vec[0] - 1); //undirected graph hai to dono vertex me push hogi(think, cs)
	}

	queue<int> q;
	vector<bool> visited(n, false);

	//get connected components vala loop
	for (int i = 0; i < graph.size(); i++) {
		if (visited[i] == false) {
			q.push(i);
			while (!q.empty()) {
				int vertex = q.front();
				q.pop();
				if (visited[vertex] == true) { //already visited, means cycle hai
					//cycle hai
					return true;
				}

				//mark visited
				visited[vertex] = true;

				for (int adj : graph[vertex]) {
					if (visited[adj] == false) { //add only unvisited neighbour
						q.push(adj);
					}
				}
			}
		}
	}
	return false;
}

int main() {
	/************************************************************
	 * NOTE: this code is writeen by me after WV
	// NOTE: the code is modified video me parentVertex ko carry krne ko bola h, but actually hme parent ki jrurt hi ni h BFS me, so mene code ko change kia, think, cs
	//VIDEO LINK: https://www.youtube.com/watch?v=BPlrALf1LDU&t=150s
	* QUESTION: https://www.codingninjas.com/studio/problems/1062670?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=1
	//************************************************************/
	// int n = 3;
	// vector<vector<int>> edges = {{1, 2}, {2, 3}, {1, 3}};

	int n = 3;
	vector<vector<int>> edges = {{1, 2}, {2, 3}};

	if (isUndirectedGraphCyclic(edges, n)) {
		cout << "yes cyclic" << endl;
	}
	else {
		cout << "non cyclic" << endl;
	}
}