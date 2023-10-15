#include<bits/stdc++.h>
using namespace std;

bool isValid(vector<int> arr, int n, int k, int mid) {
	//mid --> is the max no pages
	int noOfStudents = 1;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += arr[i];
		if (sum > mid) {
			//mid is max no pages, toh agr sum max se exceed kr jae toh no of student bdane pdege.
			noOfStudents++;
			sum = arr[i];
		}

		if (noOfStudents > k) return false;
	}
	return true;
}

int AllocateMinimumNumberOfPages(vector<int> arr, int k) {
	//watch video recommended
	//start --> max in array(for some optimization)(we can start with 0 also)
	//end --> sum of all element
	int n = arr.size();
	int start = *max_element(arr.begin(), arr.end());
	int sum = 0;
	for (auto ele : arr) sum += ele;
	int end = sum;
	int ans = -1;

	//edge case
	if (n < k) {
		//no of books, no of students se kam, not possible, coz hr ek student ko kam se kam ek book to deni hi hai
		return -1;
	}

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
	NOTE: array can be unsorted.
	QUESTION: https://leetcode.com/problems/split-array-largest-sum/description/
	VIDEO LINK: https://www.youtube.com/watch?v=thUd_WJn6wk&list=PLgUwDviBIf0pMFMWuuvDNMAkoQFi-h0ZF&index=20
	*/
	vector<int> arr = {48, 90};
	int k = 2;

	cout << AllocateMinimumNumberOfPages(arr, k);
}