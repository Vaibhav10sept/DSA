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

bool comparator(vector<int> v1, vector<int> v2) {
	return v1[0] < v2[0];
}

int meetingRoom2(vector<vector<int>> &vec) {
	vector<int> arr;
	vector<int> dep;
	for (auto ele : vec) {
		arr.push_back(ele[0]);
		dep.push_back(ele[1]);
	}
	//sort the arr(arrival) and dep(departure) array(logic)
	sort(arr.begin(), arr.end());
	sort(dep.begin(), dep.end());

	//maintain max train at a particular time
	int n = arr.size();
	int i = 0; //for arr
	int j = 0; //for dep
	int roomCount = 0;
	while (i < n and j < n) {
		if (arr[i] < dep[j]) { //mtlb train  depart hone se pehle hi aa gae, toh we need increment max train
			//these types of questions are generic, many questions are there which uses the same logic.
			//iss if me equals vali condition may vary, read the question carefully
			roomCount++;
			i++;
		}
		else {
			i++;
			j++;
		}
	}
	return roomCount;
}

int main() {
	//*********************************
	// PREREQUISITE: "min number of platforms"
	// NOTE: we use priority queue here
	// NOTE: this is a non-intuitive approach
	// VIDEO LINK: https://www.youtube.com/watch?v=qHmAwknX6OY&list=PL-Jc9J83PIiE-TR27GB7V5TBLQRT5RnSl&index=70
	// QUESTION:
// 	1. Question will be provided with "n" meeting-schedules. A meeting-schedule is defined as (sp,ep) i.e. sp --> starting point &  ep --> ending point of an meeting. Some meeting-schedules may or maynot overlap each other.
// 2. MeetingIntervals[i] = [startingPointi,endingPointi]
// 3. A meeting-schedule represents meeting time(i.e. starting time & ending time).

// Task is to "figure out, how many minimum number of meeting rooms are required to schedule all meetings?".

// Example 1 :
//     Input : [[1,3],[2,4],[6,8],[10,14],[7,9]]
//     Output : 2
//     Explanation : Two meetings are scheduled are scheduled at a time i.e. we require atleast 2 meeting rooms to schedule meetings.

// Example 2 :
//     Input : [[1,3],[3,10],[12,20]]
//     Output : 1
//     Explanation : There is no meeting-schedule overlap i.e. 1 meetng room can do the trick.
// Example 3 :
//     Input : [[1,3],[5,8],[10,19],[15,20],[9,9]]
//     Output : 2.
	//*********************************
	vector<vector<int>> arr = {{1, 3}, {2, 4}, {6, 8}, {10, 14}, {7, 9}};
	// vector<vector<int>> arr = {{1, 3}, {3, 10}, {12, 20}};
	// vector<vector<int>> arr = {{1, 3}, {5, 8}, {10, 19}, {15, 20}};
	sort(arr.begin(), arr.end(), comparator);
	displayMatrix(arr);
	cout << "min no of rooms required are: " << meetingRoom2(arr) << endl;
}