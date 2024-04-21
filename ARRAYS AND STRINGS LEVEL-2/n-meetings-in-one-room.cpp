#include <bits/stdc++.h>
using namespace std;

bool comparator(vector<int> v1, vector<int> v2) {
	//sort in increasing order of ending time
	if (v1[1] == v2[1]) { //end time is same
		//then sort in increasing order of start time
		return v1[0] < v2[0];
	}
	else { // v1[1] != v2[1]
		return v1[1] < v2[1];
	}

}

int nMeetingInOneRoom(vector<int> start, vector<int> end) {
	vector<vector<int>> arr; // {start, end}
	for (int i = 0; i < start.size(); i++) {
		arr.push_back({start[i], end[i]});
	}

	int ans = 1;
	sort(arr.begin(), arr.end(), comparator);
	int lastAcceptedMeetingEndTime = arr[0][1];

	for (int i = 1; i < arr.size(); i++) {
		if (arr[i][0] > lastAcceptedMeetingEndTime) { // we are not writting "<=" because -->  Start time of one chosen meeting can't be equal to the end time of the other chosen meeting.(given in question)
			//we can accomodate this meeting in one meeting room
			lastAcceptedMeetingEndTime = arr[i][1];
			ans++;
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

	vector<int> start =  {1, 3, 0, 5, 8, 5};
	vector<int> end =  {2, 4, 6, 7, 9, 9};
	cout << "max no of meetings in one room: " << nMeetingInOneRoom(start, end);

}