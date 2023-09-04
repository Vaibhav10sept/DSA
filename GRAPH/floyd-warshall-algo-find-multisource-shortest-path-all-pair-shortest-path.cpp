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

void floydWarshall(vector<vector<int>> &arr) {
	//WV highly recommended
	//we use DP here
	//storage: in arr[i][j] --> signify the distance(cost) for vertix(node) i to j
	//convert all -1 to infinite(1e9) (requirement of the quesetion)
	int n = arr.size();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == -1) {
				arr[i][j] = 1e9;
			}
			else if (i == j) { //distance for i to i(same vertix) is zero(CS)
				arr[i][j] = 0;
			}
		}
	}

	for (int via = 0; via < n; via++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				arr[i][j] = min(arr[i][j], arr[i][via] + arr[via][j]);
			}
		}
	}

	//convert all 1e9 to -1 (requirement of the qusetion)
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == 1e9) {
				arr[i][j] = -1;
			}
		}
	}

	//TO DETECT NEGATIVE CYCLE:
	// --> agr koi bhi path in the form i to i means arr[i][j] where i==j,
	// contains negative distance thats means negative cycle is there.
	// in this question ye need nhi h, bss ek loop lga dena like below:
	// for(int i=0;i<n;i++) {
	// 	if(arr[i][i] < 0) {
	// 		//has negative cycle;

	// 	}
	// }

}

int main() {
	/************************************************************
	 VIDEO: https://www.youtube.com/watch?v=YbY8cVwWAvw&list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw&index=23
	 QUESTION: https://practice.geeksforgeeks.org/problems/implementing-floyd-warshall2042/1
	DEFINE: It is an algorithm for finding the shortest path between all the pairs of vertices in a weighted graph. This algorithm follows the dynamic programming approach to find the shortest path.
	NOTE: it can detect the negative cycle as in bellman ford algo
	NOTE: it is applicable for DG(directed graph), for undirected graph you can convert undirected graph to DG by splitting the edges(WV)
	//************************************************************/

	vector<vector<int>> matrix = {{0, 1, 43}, {1, 0, 6}, { -1, -1, 0}};
	floydWarshall(matrix);
	displayMatrix(matrix);
}