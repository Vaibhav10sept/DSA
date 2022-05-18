#include<bits/stdc++.h>
using namespace std;

int firstOccurenceOfAnElement(vector<int> arr, int k, int start, int end) {
	int ans = -1;
	while (start <= end) {
		int mid = start + (end - start) / 2; //we are not using (start + end) / 2, to prevent int overflow
		if (k == arr[mid]) {
			//move left coz we are searching for the first occurence
			end = mid - 1;
			ans = mid;
		}
		else if (k < arr[mid]) { //move left
			end = mid - 1;
		}
		else { //move right
			start = mid + 1;
		}
	}
	return ans; //return -1 if not found
}

int FindtheIndexOfFirst1InAnInfiniteSortedArrayOf0sAnd1s(vector<int> &arr) {
	//LOGIC: this question can be broken down into two part
	// 1. find the start and end using infinite sorting vala question
	// 2. then jo start and end milega after step 1. usme first occurence vale question se answer nikal do
	int start = 0, end = 1;

	// Find h todo binary search
	while (arr[end] < 1)
	{
		start = end;        // store previous high
		end = 2 * end;    // double high index
	}

	// at this point we have updated low and
	// high indices, Thus use binary search
	// between them
	return firstOccurenceOfAnElement(arr, 1, start, end);
}

int main() {

	/*
	PREREQUISITE: find first occurence and binary search in an infinite sorted array
	VIDEO LINK: https://www.youtube.com/watch?v=8x6dmO6XW8k&list=PL_z_8CaSLPWeYfhtuKHj-9MpYb6XQJ_f2&index=14
	*/
	vector<int> arr = {1, 1, 1, 1, 1, 1};
	cout << FindtheIndexOfFirst1InAnInfiniteSortedArrayOf0sAnd1s(arr) << endl;
}