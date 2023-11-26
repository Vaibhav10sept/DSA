#include <bits/stdc++.h>
using namespace std;

int timeNeededToInform(int n, int headID, vector<int> manager, vector<int> informTime) {

}

int main() {
	/************************************************************
	 * STRONG PREQ:
	 VIDEO:
	 LINK: https://leetcode.com/problems/time-needed-to-inform-all-employees/
	//************************************************************/

	int n = 6;
	int headID = 2;
	vector<int> manager = {2, 2, -1, 2, 2, 2};
	vector<int> informTime = {0, 0, 1, 0, 0, 0};

	cout << "ans " << timeNeededToInform(n, headID, manager, informTime);
}