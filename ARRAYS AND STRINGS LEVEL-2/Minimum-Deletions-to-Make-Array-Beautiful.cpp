#include <bits/stdc++.h>
using namespace std;

int MinimumDeletionstoMakeArrayBeautiful (vector<int> arr) {
	int countOfNumberDeleted  = 0;
	for (int i = 0; i < arr.size() - 1; i++) {
		if ((i - countOfNumberDeleted) % 2 == 0 and arr[i] == arr[i + 1]) {
			countOfNumberDeleted++;
		}
	}

	//check for array size after deletion, it should be even as per question
	if ((arr.size() - countOfNumberDeleted) % 2 != 0) { //if its odd
		countOfNumberDeleted++;
	}
	return countOfNumberDeleted;
}


int main() {
	//*********************************
	// VIDEO LINK: https://www.youtube.com/watch?v=xzsAFSFiVF8
	// LINK: https://leetcode.com/contest/weekly-contest-286/problems/minimum-deletions-to-make-array-beautiful/
	//*********************************
	vector<int> arr = {1, 1, 2, 2, 3, 3};
	cout << MinimumDeletionstoMakeArrayBeautiful(arr);
}