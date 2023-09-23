#include<bits/stdc++.h>
using namespace std;


void dfs(int node, vector<vector<int>> &graph, vector<bool> &visited) {
    visited[node] = true;

    for (int adj : graph[node]) {
        if (visited[adj] == false) {
            dfs(adj, graph, visited);
        }
    }
}

int getConnectedComponents(vector<vector<int>> arr) {
    // NOTE: i wrote this code by myself, no video
    int n = arr.size();
    vector<vector<int>> graph(n);

    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < arr[0].size(); j++) {
            if (arr[i][j] == 1) {
                graph[i].push_back(j);
            }
        }
    }


    //get connected components vala logic
    vector<bool> visited(n);
    int countOfConnectedComponents = 0;
    for (int i = 0; i < graph.size(); i++) {
        if (visited[i] == false) {
            countOfConnectedComponents++;
            dfs(i, graph, visited);
        }
    }
    return countOfConnectedComponents;
}


int main() {
    /*
    STRONG PREQ: get connected components(same code)
    NOTE: i wrote this code by myself, no video
    LEETCODE: https://leetcode.com/problems/number-of-provinces/description/
    */

    vector<vector<int>> isConnected = {{1, 1, 0}, {1, 1, 0}, {0, 0, 1}};
    cout << getConnectedComponents(isConnected);

}