#include <bits/stdc++.h>
using namespace std;

int selectKcities(int n, int k, vector<vector<int>>& arr) {

}

int main() {
	/*********************************
	NOTE:
	// VIDEO LINK:
	// QUESTION: https://practice.geeksforgeeks.org/problems/k-centers-problem/1?utm_source=geeksforgeeks&utm_medium=ml_article_practice_tab&utm_campaign=article_practice_tab
	//*********************************/
	int n = 4;
	int k = 2;
	vector<vector<int>>  arr = {{0, 10, 7, 6},
		{10, 0, 8, 5},
		{7, 8, 0, 12},
		{6, 5, 12, 0}
	};
	cout << selectKcities(n, k, arr);
}