#include <bits/stdc++.h>
using namespace std;

class Node {
public:
	string dest;
	double weight;
	Node(string dest, double weight) {
		this->dest = dest;
		this->weight = weight;
	}
};

map<string, vector<Node>> buildGraph(vector<vector<string>> equations, vector<double> values) {
	map<string, vector<Node>> graph;
	for (int i = 0; i < equations.size(); i++) {
		string src = equations[i][0];
		string dest = equations[i][1];

		graph[src].push_back(Node(dest, values[i]));
		//dest se src pe values[i] ka reciprocal store hoga as weight(think, watch video)
		graph[dest].push_back(Node(src, 1 / values[i]));
	}
	return graph;
}

double dfs(string src, string dest, set<string> &visited, map<string, vector<Node>> graph) {
	//this is recursive DFS(not exactly same as DFS it has some modification in it).
	if (graph.find(src) == graph.end() or graph.find(dest) == graph.end()) {
		//if src or dest is not present in the graph return -1;
		return -1.0;
	}
	if (src == dest) {
		return 1;
	}

	if (visited.find(src) != visited.end()) return -1; //already visited
	//base conditions ends

	//add to the visited set.
	visited.insert(src);
	//iterate through the vertices connect to src and make recursive call to dfs
	for (Node node : graph[src]) {
		if (visited.find(node.dest) == visited.end()) { //not found -> node.dest is not visited, call dfs
			double ans = dfs(node.dest, dest, visited, graph);
			if (ans != -1) {
				return node.weight * ans;
			}
		}
	}
	return -1.0;
}

vector<double> evaluateDivision(vector<vector<string>> equations, vector<double> values, vector<vector<string>> queries) {
	//this will be a directed graph.(think)
	map<string, vector<Node>> graph = buildGraph(equations, values);
	vector<double> ans;

	//iterate through queries and find the ans of each query using DFS and store it in ans vector
	for (vector<string> query : queries) {
		set<string> visited;
		//query[0] --> src;
		//query[1] --> dest;
		ans.push_back(dfs(query[0], query[1], visited, graph));
	}
	return ans;
}

int main() {
	//************************************************************
	//VIDEO LINK: https://www.youtube.com/watch?v=UcDZM6Ap5P4
	//LEETCODE: https://leetcode.com/problems/evaluate-division/
	//NOTE: we use DFS here.
	//************************************************************

	vector<vector<string>> equations = {{"a", "b"}, {"b", "c"}};
	vector<double> values = {2.0, 3.0};
	vector<vector<string>> queries = {{"a", "c"}, {"b", "a"}, {"a", "e"}, {"a", "a"}, {"x", "x"}};
	vector<double> ans = evaluateDivision(equations, values, queries);
	cout << "res" << endl;
	for (auto ele : ans) cout << ele << " ";
}

