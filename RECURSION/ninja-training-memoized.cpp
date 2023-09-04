#include <bits/stdc++.h>
using namespace std;

int recursiveHelper(int day, int lastTask, vector<vector<int>> arr, vector<vector<int>> &memoized) {
	if (day == arr.size() - 1) { //last day/index
		int maxPoints = INT_MIN;
		for (int task = 0; task < 3; task++) {
			if (task != lastTask)
				maxPoints = max(maxPoints, arr[day][task]);
		}
		return maxPoints;
	}
	//BC ends

	if (memoized[day][lastTask] != -1) return memoized[day][lastTask];

	int maxPoints = INT_MIN;
	for (int task = 0; task < 3; task++) {
		if (task != lastTask) {
			int points = arr[day][task] + recursiveHelper(day + 1, task, arr, memoized);
			maxPoints = max(maxPoints, points);
		}
	}

	return memoized[day][lastTask] = maxPoints;
}

int ninjaTraining(vector<vector<int>> arr) {
	vector<vector<int>> memoized(arr.size(), vector<int>(4, -1)); //4 size column coz neeche hm 3 idx pass kre so to make memoized[day][lastTask] valid we need to make memoized column of size 4 to make 3rd index possible
	return recursiveHelper(0, 3, arr, memoized); //don't pass -1 in second argument, think CS read above comment
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