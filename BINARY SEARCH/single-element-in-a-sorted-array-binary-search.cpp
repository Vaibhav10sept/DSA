#include<bits/stdc++.h>
using namespace std;

int singleElementInSortedArray(vector<int> arr) {
	//WV recommended
	int start = 0;
	int end = arr.size() - 1;
	int n = arr.size();
	int mid;

	//if one size array
	if (arr.size() == 1) return arr[0];

	//boundary check, checking if 0 or size-1 index is the single element or not
	if (arr[0] != arr[1]) return arr[0];
	if (arr[n - 1] != arr[n - 2]) return arr[n - 1];

	while (start <= end) {
		mid = start + (end - start) / 2;
		//check for whether arr[mid] is the single element or not
		if (arr[mid] != arr[mid - 1] and arr[mid] != arr[mid + 1]) { //it is the single element
			return arr[mid];
		}

		//now, where to move and on which condition?
		//logic(wv recommended, think or CS)
		//left half me --> first instance of double element -> even index pe
		//                 second instance of double element -> odd index pe
		//right half me --> first instance of double element -> odd index pe
		//                  second instance of double element -> even index pe
		//iss logic se hm decide krege ki left jana h right

		if ((mid % 2 == 0 and arr[mid + 1] == arr[mid]) or
		        (mid % 2 == 1 and arr[mid - 1] == arr[mid])) { //move to right
			start = mid + 1;
		}
		else { //move to left
			end = mid - 1;
		}
	}
	return -1;
}

int main() {
	/*
	NOTE: WV highly recommended
	QUESTION: https://takeuforward.org/data-structure/search-single-element-in-a-sorted-array/
	VIDEO LINK: https://www.youtube.com/watch?v=nMGL2vlyJk0
	*/
	vector<int> arr = {1, 1, 2, 3, 3, 4, 4, 8, 8};
	cout << singleElementInSortedArray(arr);
}