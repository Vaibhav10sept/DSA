#include <bits/stdc++.h>
using namespace std;

int sortArrayByParity(vector<int> &arr) {
	int i = 0; // marks the end of odd segment
	int j = 0; // marks the end of even segment

	while (i < arr.size()) {
		if (arr[i] % 2 == 0) { // even hai
			swap(arr[i], arr[j]);
			i++;
			j++;
		}
		else { // odd hai
			i++;
		}
	}
}

int main() {
	//********************************
	// NOTE: two pointers approach is used here
	// SIMILAR: sort array of 0 and 1.
	// VIDEO LINK: https://www.youtube.com/watch?v=SdOfZrmItps&list=PL-Jc9J83PIiE-TR27GB7V5TBLQRT5RnSl&index=17
	// QUESTION:
	// 1. Given an array nums of non-negative integers.
	// 2. Arrange elements of array in specific order, all even elements followed by odd elements. [even -> odd]
	// 3. Preserve the order of Even elements without using extra space.
	// 4. Hence question is order specific so you have to match your output in order of given output.
	//*********************************
	vector<int> arr = {9, 3, 8 , 7 , 6 , 2, 3};
	cout << "original array:" << endl;
	for (auto ele : arr) cout << ele << " ";
	cout << endl;
	sortArrayByParity(arr);
	cout << "after sorting:" << endl;
	for (auto ele : arr) cout << ele << " ";
}