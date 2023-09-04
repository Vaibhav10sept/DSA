#include <bits/stdc++.h>
using namespace std;

bool comparator(vector<int> v1, vector<int> v2) {
	//sort in increasing order of ending time
	if (v1[1] == v2[1]) { //end time is same
		//then sort in increasing order of position
		return v1[2] < v2[2];
	}
	else { // v1[1] != v2[1]
		return v1[1] < v2[1];
	}

}

vector<int> nMeetingInOneRoom(vector<int> start, vector<int> end) {
	vector<vector<int>> arr; // {start, end, position(1 based indexing)}
	for (int i = 0; i < start.size(); i++) {
		arr.push_back({start[i], end[i], i + 1});
	}

	vector<int> ans;
	sort(arr.begin(), arr.end(), comparator);

	ans.push_back(arr[0][2]);
	int lastAcceptedMeetingEndTime = arr[0][1];

	for (int i = 1; i < arr.size(); i++) {
		if (arr[i][0] > lastAcceptedMeetingEndTime) { // we are not writting "<=" because -->  Start time of one chosen meeting can't be equal to the end time of the other chosen meeting.(given in question)
			//we can accomodate this meeting in one meeting room
			lastAcceptedMeetingEndTime = arr[i][1];
			ans.push_back(arr[i][2]);
		}
		else {
			//we need to leave this meeting, can't be accomodate in a single room, so don't do anything here.
		}
	}
	return ans;
}

int main() {
	//*********************************
	// VIDEO LINK: https://www.youtube.com/watch?v=II6ziNnub1Q&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=46
	// QUESTION: https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1
	// vector<int> start = {1, 3, 0, 5, 8, 5};
	// vector<int> end =  {2, 4, 6, 7, 9, 9};

	vector<int> start = {1, 1, 1};
	vector<int> end =  {4, 5, 9};
	vector<int> ans = nMeetingInOneRoom(start, end);

	cout << "max no of meetings in one room: " << endl;
	for (auto ele : ans) {
		cout << ele << " ";
	}
}