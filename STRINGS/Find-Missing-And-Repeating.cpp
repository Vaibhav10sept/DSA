#include <bits/stdc++.h>
using namespace std;

vector<int> findMissingRepeating(vector<int> arr) {
	//NOTE: I wrote it myself no video no reading
	vector<int> ans;

	//FOR FINDING THE REPEATING NUMBER;
	for (int i = 0; i < arr.size(); i++) {
		int ind = abs(arr[i]) - 1;

		if (arr[ind] < 0) {
			ans.push_back(ind + 1); //repeating number
		}
		else {
			arr[ind] = abs(arr[ind]) * -1;
		}

	}

	//FOR FINDING THE MISSING NUMBER;

	for (int i = 0; i < arr.size(); i++) {
		if (arr[i] >= 0) {
			ans.push_back(i + 1);
		}
	}
	return ans;
}


int main() {
	/************************************
	 //NOTE: I wrote it myself no video no reading
	 * QUESTION: https://practice.geeksforgeeks.org/problems/find-missing-and-repeating2512/1
	// VIDEO LINK:
	//************************************/
	vector<int>	arr = {13, 33, 43, 16, 25, 19, 23, 31, 29, 35, 10, 2, 32, 11, 47, 15, 34, 46, 30, 26, 41, 18, 5, 17, 37, 39, 6, 4, 20, 27, 9, 3, 8, 40, 24, 44, 14, 36, 7, 38, 12, 1, 42, 12, 28, 22, 45};
	vector<int> ans = findMissingRepeating(arr);
	cout << ans[0] << " " << ans[1] << endl;

}


