#include<bits/stdc++.h>
using namespace std;

class Util {
public:
	int i;
	int j;
	int height;
	Util(int i, int j, int height) {
		this->i = i;
		this->j = j;
		this->height = height;
	}
};

//< operator overloading for priority queue
bool operator<(const Util u1, const Util u2) { //min heap
	u1.height > u2.height;
}


int trappingRainWater2(vector<vector<int>> arr) {
	priority_queue<Util> pq;
	int n = arr.size();
	int m = arr[0].size();
	vector<vector<int>> visited(n, vector<int>(m, false));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			//for boundaries.
			if (i == 0 or j == 0 or i == n - 1 or j == m - 1) {
				pq.push(Util(i, j, arr[i][j]));
				visited[i][j] = true;
			}
		}
	}

	vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, { -1, 0}};
	int water = 0;

	while (!pq.empty()) {
		Util removed = pq.top(); //min height vala niklega
		pq.pop();

		for (vector<int> dir : directions) {
			//sare directions me jaoge
			int newRow = removed.i + dir[0];
			int newCol = removed.j + dir[1];

			//check if the newRow and newCol is valid and also not visited.
			if (newRow >= 0 and newRow<n and newCol >= 0 and newCol < m
			        and visited[newRow][newCol] == false) {

				//mark newRow and newCol as visited
				visited[newRow][newCol] = true;

				//add water if the difference is positive.(think)
				if (removed.height - arr[newRow][newCol] > 0) {
					water +=  removed.height - arr[newRow][newCol];
				}

				//add Util object in the priority queue where height vary as below condition
				if (arr[newRow][newCol] >= removed.height) {
					pq.push(Util(newRow, newCol, arr[newRow][newCol]));
				}
				else { //height removed vali ki hogi(logic,think)
					pq.push(Util(newRow, newCol, removed.height));
				}
			}
		}
	}
	return water;
}

int main() {
	/*
	PREREQUISITE:
	VIDEO LINK: https://www.youtube.com/watch?v=fywyCy6Fyoo&list=PL-Jc9J83PIiE1_SifBEWRsD-fzxrvkja9&index=22
	LEETCODE LINK:
	*/
	vector<vector<int>> heightMap = {{1, 4, 3, 1, 3, 2}, {3, 2, 1, 3, 2, 4}, {2, 3, 3, 2, 3, 1}};
	cout << trappingRainWater2(heightMap);
}