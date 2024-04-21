#include<bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> arr, int x) {
	int start = 0;
	int end = arr.size() - 1;
	int ans = arr.size(); //not found to hm arr.size return krege, given in question
	while (start <= end) {
		int mid = start + (end - start) / 2; //we are not using (start + end) / 2, to prevent int overflow

		if (arr[mid] >= x) {
			ans = mid;
			//move left, coz hme smallest index chahie which is >= x
			end = mid - 1;
		}


		else { //else move right
			start = mid + 1;
		}

	}
	return ans;
}

int main() {
	/*
	lower bound of x: is the smallest number which is just greater then or equal to x
	VIDEO LINK: https://www.youtube.com/watch?v=6zhGS79oQ4k&list=PLgUwDviBIf0pMFMWuuvDNMAkoQFi-h0ZF&index=4
	QUESTION: https://www.codingninjas.com/studio/problems/lower-bound_8165382?utm_source=youtube&utm_medium=affiliate&utm_campaign=codestudio_Striver_BinarySeries
	*/
	vector<int> arr = {1, 2, 2, 3, 3, 5};
	int x = 0;
	cout << binarySearch(arr, x);
}