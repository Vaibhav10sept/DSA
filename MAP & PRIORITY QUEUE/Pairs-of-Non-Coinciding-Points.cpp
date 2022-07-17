#include <bits/stdc++.h>
using namespace std;

int numOfPairs(vector<int> X, vector<int> Y, int N) {
	//WV recommended
	//NOTE: this is a mathematical problem, need to find the formula then there is nothing in this question
	/*DERIVATION OF FORMULA:
	MANHATTEN DISTANCE = EUCLIDEAN DISTANCE
	AFTER SOLVING FURTHER WE GET THE FINAL FORMULA AS:(WV)
	|x2-x1||y2-y1| = 0;
	we get,
	x2 = x1 ______(1)
	or, y2 = y1 _________(2)
	*/
	int ans = 0;
	map<int, int> xFreqMap;
	map<int, int> yFreqMap;
	map<string, int> xyFreqMap;

	for (int i = 0; i < X.size(); i++) {
		int x = X[i];
		int y = Y[i];
		string xy = x + "*" + y;

		ans += xFreqMap[x] + yFreqMap[y] - 2 * xyFreqMap[xy];

		//update the map
		xFreqMap[x]++;
		yFreqMap[y]++;
		xyFreqMap[xy]++;
	}
	return ans;
}

int main() {
	/*
	NOTE: this is a mathematical problem, need to find the formula then there is nothing in this question
	VIDEO LINK: https://www.youtube.com/watch?v=7UVJYPT3-uI&list=PL-Jc9J83PIiEp9DKNiaQyjuDeg3XSoVMR&index=61
	QUESTION LINK: https://practice.geeksforgeeks.org/problems/pairs-of-non-coinciding-points4141/1
	*/
	int N = 3;
	vector<int> X = {1, 2, 1};
	vector<int> Y = {2, 3, 3};
	cout << "result" << endl;
	cout << numOfPairs(X, Y, N);
}