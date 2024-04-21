#include <bits/stdc++.h>
using namespace std;

bool comparator(vector<int> v1, vector<int> v2) {
	return v1[1] > v2[1];
}

int jobSequencingProblem(vector<vector<int>> arr) {
	//sort in descending order of profit --> we need to think greedily
	sort(arr.begin(), arr.end(), comparator);
	int noOfJobsDone = 0;
	int maxProfit = 0;

	cout << "fsd " << endl;
	for (auto vec : arr) {
		cout << vec[0] << " " << vec[1] << endl;
	}

	//find he maximum no of day/deadline
	int maxDeadline = INT_MIN;
	for (vector<int> vec : arr) {
		maxDeadline = max(maxDeadline, vec[0]);
	}
	cout << "maxDeadline " << maxDeadline << endl;
	vector<int> days(maxDeadline + 1, -1);
	for (int i = 0; i < arr.size(); i++) {
		vector<int> vec = arr[i];

		int deadLine = vec[0];
		int profit = vec[1];
		if (days[deadLine] == -1) { //means use nhi hue h, so add it in maxProfit
			noOfJobsDone++;
			maxProfit += profit;

			//occupy this day
			days[deadLine] = 1;
		}
		else { // means ye vali deadline use ho chuki h, so isse pehele agr koi day khali h to use check kro and then add in job on that day, agr koi khali milta h to
			int j = deadLine - 1;
			while (j >= 1) { // why 1, coz hm 1 based indexing follow krre for days/deadlines
				if (days[j] == -1) { //hme ek day mil gya aesa jisme hm ye job kr skte h means we can do this job
					noOfJobsDone++;
					maxProfit += profit;

					//occupy this day
					days[j] = 1;
					break;
				}
				j--;
			}
		}
	}
	return maxProfit;
}

int main() {
	/*********************************
	QUESTION LINK: https://takeuforward.org/data-structure/job-sequencing-problem/
	VIDEO LINK: https://www.youtube.com/watch?v=LjPx4wQaRIs&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=48
	NOTE: this is a greedy approach problem
	OUTPUT: output is the no of jobs done and maximum profit
	//*********************************/
	vector<vector<int>> Jobs = {{3, 40}, {3, 10}, {3, 20}};
	cout << jobSequencingProblem(Jobs);
}