#include<bits/stdc++.h>
using namespace std;


int searchInNearlySortedArray(vector<int> &arr, int k) {
	/*
	WHAT IS NEARLY(ALMOST) SORTED ARRAY: Given an array which is sorted, but after sorting some elements are moved to either of the adjacent positions, i.e., arr[i] may be present at arr[i+1] or arr[i-1].
	LOGIC:
	normal binary search me ham arr[mid] pe check krte the
	isme ham ham arr[mid-1], arr[mid] and arr[mid + 1] se check krege
	left me move krne pr --> end = mid - 2 krege

	*/
	int start = 0;
	int end = arr.size() - 1;
	while (start <= end) {
		int mid = start + (end - start) / 2; //we are not using (start + end) / 2, to prevent int overflow

		if (arr[mid] == k) return mid;
		else if (mid - 1 >= start and arr[mid - 1] == k) return mid - 1;
		else if (mid + 1 <= end and arr[mid + 1] == k) return mid + 1;

		//move kidhar krna hai
		else if (k < arr[mid]) { //move left
			end = mid - 2;//rem: read above logic
		}
		else if (k > arr[mid]) { //move right
			start = mid + 2;
		}
	}
	return -1; //return -1 if not found
}

int main() {
	/*
	PREREQUISITE:
	VIDEO LINK: https://www.youtube.com/watch?v=W3-KgsCVH1U&list=PL_z_8CaSLPWeYfhtuKHj-9MpYb6XQJ_f2&index=9
	GFG LINK: https://www.geeksforgeeks.org/search-almost-sorted-array/#:~:text=A%20simple%20solution%20is%20to,present%20then%20return%20the%20index.
	*/
	vector<int> arr =  {10, 3, 40, 20, 50, 80, 70};
	int k = 20;
	cout << searchInNearlySortedArray(arr, k) << endl;
}