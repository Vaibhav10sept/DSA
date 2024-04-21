#include <bits/stdc++.h>
using namespace std;

void dfs(int node, map<int, vector<int>> graph, set<int> &visited, vector<int> &ans) {
	if (visited.find(node) != visited.end()) //found --> already visited hai to return ho jao
		return;
	//BC ends

	ans.push_back(node);
	visited.insert(node);

	//call dfs for the adjacent node of node
	for (int adj : graph[node]) {
		dfs(adj, graph, visited, ans);
	}

}

vector<int> RestoreArrayFromAdjacentPairs(vector<vector<int>> arr) {
	//create a graph using the arr
	map<int, vector<int>> graph; //undrirected graph
	for (auto vec : arr) {
		graph[vec[0]].push_back(vec[1]);
		graph[vec[1]].push_back(vec[0]); //undirected graph
	}

	//find the teminal(head or tail) node, means starting node, jaha se array start hoga(wv, see question)
	int head = 0;
	for (auto it : graph) {
		if (it.second.size() == 1) { //this is the head
			head = it.first;
		}
	}

	//now, do DFS and fill the ans array
	vector<int> ans;
	set<int> visited;

	dfs(head, graph, visited, ans);

	return ans;
}

int main() {
	/************************************************************
	 * NOTE: we use DFS here
	 * QUESTION: https://leetcode.com/problems/restore-the-array-from-adjacent-pairs/description/
	 VIDEO: https://www.youtube.com/watch?v=emF5eAYR3Nk
	//************************************************************/
	vector<vector<int>> adjacentPairs = {{2, 1}, {3, 4}, {3, 2}};
	vector<int> ans = RestoreArrayFromAdjacentPairs(adjacentPairs);
	for (auto ele : ans) cout << ele << " ";
}