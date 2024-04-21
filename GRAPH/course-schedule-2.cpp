#include <bits/stdc++.h>
using namespace std;

vector<int> courseSchedule(int n, vector<vector<int>> edges) {
	vector<vector<int>> graph(n);
	//* LOGIC: topological only possible in DAG, if the graph is not acyclic then the topo ans array will not have the same size as graph.size() (think, cs, WV)
	//using BFS
	//step 1: find the indegree of all the vertixes
	vector<int> indegree(graph.size(), 0);
	// adjlist
	for (auto x : edges) {
		graph[x[1]].push_back(x[0]);
		indegree[x[0]]++;
	}

	//step 2: put the 0 indegree into the queue
	queue<int> q;
	for (int i = 0; i < graph.size(); i++) {
		if (indegree[i] == 0) {
			q.push(i);
		}
	}

	vector<int> topologicalSort;
	while (!q.empty()) {
		int removedNode = q.front();
		q.pop();
		topologicalSort.push_back(removedNode);

		//reduce the indegree of all adjacent node from the remove node
		for (auto edge : graph[removedNode]) {
			indegree[edge]--;
			if (indegree[edge] == 0) {
				q.push(edge);
			}
		}
	}

	if (topologicalSort.size() != graph.size()) {
		//means topo sort me sare vertixes nhi aae, that means graph DAG ni h, so it's acyclic return false
		return {};
	}
	return topologicalSort;
}

int main() {
	/************************************************************
	 * LOGIC: course scheduling tbhi possible h, jb cycle na ho, islie topological sort use krke hm cycle detect kr rhe hai
	 * STRONG PREQ: topological sort(almost same code)
	 * NOTE: same question DFS se bhi kia h dekh lo
	 * NOTE: DAG(directed acyclic graph) ke liye bhi topological sorting possible h
	 * NOTE: acyclic, directed graph ki hi topological sorting possible ho skti h(think, CS)
	 * agr cycle h ya undirected graph h to ordering possible nhi ho skti(think, CS)
	DEFINE: A topological sort (sometimes also called a linearization) of a directed graph is a list of the vertices in such an order that if there is a directed path from vertex v to vertex w , then v precedes w in the list. (The graph must be acyclic in order for this to work.
	//VIDEO LINK: https://www.youtube.com/watch?v=73sneFXuTEg&list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw&index=14
	//NOTE: we use BFS here.
	LEETCODE: https://leetcode.com/problems/course-schedule-ii/description/
	//************************************************************/

	int  numCourses = 4;
	vector<vector<int>> prerequisites = {{1, 0}, {2, 0}, {3, 1}, {3, 2}};
	vector<int> ans = courseSchedule(numCourses, prerequisites);
	for (auto ele : ans) cout << ele << " ";

}