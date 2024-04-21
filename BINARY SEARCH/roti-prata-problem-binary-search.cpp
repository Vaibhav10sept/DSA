#include<bits/stdc++.h>
using namespace std;

bool isValid(vector<int> arr, int n, int k, int maxTime) {
	//mid --> is the min time
	int noOfStudents = 1;
	int sum = 0;
	int totalParathaCount = 0;
	for (int i = 0; i < n; i++) {
		int rank = arr[i];
		//rank ka chef maxtime me kitne parathe bna paega
		int mul = 1;
		int cntParatha = 0;
		int timeSum = 0;
		while (true) {
			timeSum += (mul * rank);
			if (timeSum > maxTime) break;
			cntParatha++;
			mul++;
		}
		// cout << "rank " << rank << " " << cntParatha << " " << timeSum << endl;
		totalParathaCount += cntParatha;
	}
	if (totalParathaCount >= k) {
		return true;
	}
	return false;
}

int AllocateMinimumNumberOfPages(vector<int> arr, int k) {
	//watch video recommended
	//start --> max in array(for some optimization)(we can start with 0 also)
	//end --> sum of all element
	int n = arr.size();
	int start = 0;
	int end = 10e8;
	int ans = -1;

	while (start <= end) {
		int mid = start + (end - start) / 2;
		//mid --> is the max no pages that we can give to a student, and we need to minimize this(max no of pages) ie. mid

		if (isValid(arr, n, k, mid)) {
			ans = mid; //always minimum hi hoga, std::min() ki jrurt nhi, lga bhi doge toh koi farak nhi pdega
			end = mid - 1; //moving left, kyoki hame mid(max no of pages) ko minimize krna hai
		}
		else { //not valid, means mid(max no of pages) k(students) ke lie possible nhi h
			//right me jao
			start = mid + 1;
		}
	}
	return ans;
}

int main() {
	/*
	EXACTLY SAME SOLUTION: allocate minimum number of pages, split array largest sum, painter's partition problem
	STRONG PREQ: allocate minimum number of pages
	SAME PATTERN PROBLEMS:
	1. aggresive cows
	2. allocate minimum number of pages
	3. painter's partition problem
	4. split array largest sum
	5. roti prata problem
	QUESTION: https://www.spoj.com/problems/PRATA/
	VIDEO LINK: https://www.youtube.com/watch?v=-Nx1h54KzUQ
	*/

	// vector<int> arr = {1, 2, 3, 4};
	// int k = 10;
	vector<int> arr = {1, 1, 1, 1, 1, 1, 1, 1};
	int k = 8;
	// vector<int> arr = {1};
	// int k = 8;

	cout << "ans " << AllocateMinimumNumberOfPages(arr, k);
}