#include <bits/stdc++.h>
using namespace std;

void print(vector<int> arr) {
	for (auto ele : arr) cout << ele << " ";
	cout << endl;
}

void rotateArray(vector<int> &arr, int r) {
	// handling negative rotations
	if (r < 0) {
		r += arr.size();
	}

	// handling rotations more than the size of array.
	r = r % arr.size();


	// 3 step process
	// divide array in two parts
	// 1. reverse first part
	// 2. reverse second part
	// 3. reverse the whole array

	std::reverse(arr.begin(), arr.end() - r);
	std::reverse(arr.end() - r, arr.end());
	std::reverse(arr.begin(), arr.end());
}

int main()
{
	vector<int> arr = {1, 2, 3, 4, 5, 6};
	print(arr);
	rotateArray(arr, 2);
	print(arr);
}