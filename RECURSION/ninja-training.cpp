#include <bits/stdc++.h>
using namespace std;

int recursiveHelper(int day, int lastTask, vector<vector<int>> arr) {
	if (day == arr.size() - 1) { //last index
		int maxPoints = INT_MIN;
		for (int task = 0; task < 3; task++) {
			if (task != lastTask)
				maxPoints = max(maxPoints, arr[day][task]);
		}
		return maxPoints;
	}
	//BC ends

	int maxPoints = INT_MIN;
	for (int task = 0; task < 3; task++) {
		if (task != lastTask) {
			int points = arr[day][task] + recursiveHelper(day + 1, task, arr);
			maxPoints = max(maxPoints, points);
		}
	}

	return  maxPoints;
}

int ninjaTraining(vector<vector<int>> arr) {
	int lastChoice = -1;
	return recursiveHelper(0, lastChoice, arr);
}


int main()
{
	/***********************************************
	PREQ: max sum non adjacent elements
	NOTE: this is rec, DP solution is also present.
	QUESTION: https://www.codingninjas.com/studio/problems/ninja-s-training_3621003
	video link: https://www.youtube.com/watch?v=AE39gJYuRog&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=10
	****************************************************/
	vector<vector<int>> arr = {{1, 2, 5}, {3, 1, 1}, {3, 3, 3}};

	cout << "max merit points is: " << ninjaTraining(arr);
}