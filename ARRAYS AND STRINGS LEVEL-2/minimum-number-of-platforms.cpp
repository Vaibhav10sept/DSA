#include <bits/stdc++.h>
using namespace std;

int minNumberOfplatforms(vector<int> arr, vector<int> dep) {
	//sort the arr(arrival) and dep(departure) array(logic)
	sort(arr.begin(), arr.end());
	sort(dep.begin(), dep.end());

	//maintain max train at a particular time
	int n = arr.size();
	int i = 0; //for arr
	int j = 0; //for dep
	int count = 0;
	while (i < n and j < n) {
		if (arr[i] <= dep[j]) { //mtlb train  depart hone se pehle hi aa gae, toh we need increment max train
			//these types of questions are generic, many questions are there which uses the same logic.
			//iss if me equals vali condition may vary, read the question carefully
			count++;
			i++;
		}
		else {
			i++;
			j++;
		}
	}
	return count;
}

int main() {
	//*********************************
	// PREREQUISITE: "merge-intervals" and "meeting-rooms-2-chronogical-order"
	// SAME CODE: meeting-rooms-2-chronogical-order
	// ACTUAL VIDEO LINK: https://www.youtube.com/watch?v=qHmAwknX6OY&list=PL-Jc9J83PIiE-TR27GB7V5TBLQRT5RnSl&index=71
	// VIDEO LINK: https://www.youtube.com/watch?v=FkJZlZHWUyk&list=PL-Jc9J83PIiE-TR27GB7V5TBLQRT5RnSl&index=68
	// QUESTION:
// 	1. We have arrival and departure times of all trains that reach a railway station.
// 2. We have to find the minimum number of platforms required for the railway station so that no train is kept waiting.
// 3. Consider that all the trains arrive on the same day and leave on the same day.
// 4. Arrival and departure time can never be the same for a train but we can have arrival time of one train equal to departure time of the other.
// 5. At any given instance of time, same platform can not be used for both departure of a train and arrival of another train. In such cases, we need different platforms.
	//*********************************
	vector<int> arr = {900, 940, 950, 1100, 1500, 1800};
	vector<int> dep = {910, 1200, 1120, 1130, 1900, 2000};
	cout << minNumberOfplatforms(arr, dep);
}