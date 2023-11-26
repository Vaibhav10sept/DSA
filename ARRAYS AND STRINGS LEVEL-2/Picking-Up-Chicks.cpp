#include<bits/stdc++.h>
using namespace std;

void pickUpChicks(int n, int k, int b, int t, vector<int> x, vector<int> v) {
	//NOTE: wv
	int cntOfSlowChicks = 0;
	int noOfSwaps = 0;
	int cntOfChicksReachTheBarn = 0;

	for (int i = n - 1; i >= 0; i--)  {
		int maxDist = v[i] * t; //using formula: distance = speed * time
		int requiredDist = b - x[i];

		if (requiredDist > maxDist) { //this chick cannot reach the barn
			cntOfSlowChicks++;
		}
		else { //this chick can reach the barn
			cntOfChicksReachTheBarn++;
			noOfSwaps += cntOfSlowChicks;
		}

		if (cntOfChicksReachTheBarn >= k) {
			break;
		}
	}

	if (cntOfChicksReachTheBarn >= k) {
		cout << "reach is " << noOfSwaps << " swaps" << endl;
	}
	else cout << "impossible" << endl;
}

int main() {
	//**************************************
	// NOTE: good qeustion nice logic
	// NOTE: wv
	//VIDEO LINK: https://www.youtube.com/watch?v=vrRWIbhGK7o
	// QUESTION LINK: https://www.spoj.com/problems/GCJ101BB/
	//*******************************************
	int n = 5;
	int k = 3;
	int b = 10;
	int t = 5;
	vector<int> x = {0, 2, 5, 6, 7};
	vector<int> v = {1, 1, 1, 1, 4};
	pickUpChicks(n, k, b, t, x, v);
}

