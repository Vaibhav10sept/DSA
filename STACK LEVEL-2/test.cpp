#include<bits/stdc++.h>
using namespace std;

void displayMatrix(vector<vector<int>> arr) {
    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < arr[i].size(); j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}


void dfs(int node, int target, vector<bool> &visited, vector<vector<int>> &graph, vector<int> ans, vector<vector<int>> &res) {
    if (node == target) {
        ans.push_back(node);
        res.push_back(ans);
        return;
    }


    ans.push_back(node);
    visited[node] = true;
    for (auto adj : graph[node]) {
        if (visited[adj] == false) {
            dfs(adj, target, visited, graph, ans, res);
        }
    }

    //backtrack
    ans.pop_back();
    visited[node] =
}

vector<vector<int>> fun(vector<vector<int>> graph) {
    vector<vector<int>> res;
    vector<int> ans;
    int n = graph.size();
    vector<bool> visited(n);

    dfs(0, n - 1, visited, graph, ans, res);
    return res;
}

int main() {
    /*

    */

    vector<vector<int>> graph = {{1, 2}, {3}, {3}, {}};
    vector<vector<int>> ans = fun(graph);
    displayMatrix(ans);

}