#include <bits/stdc++.h>
using namespace std;

void print(vector<int> arr) {
	for (auto ele : arr) cout << ele << " ";
	cout << endl;
}

int binarySearch(vector<int> arr, int data) {
	int left = 0;
	int right = arr.size() - 1;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (data == arr[mid]) {
			return mid;

		}
		else if (data < arr[mid]) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
	cout << "not found" << endl;
	return -1;

}

int main()
{
	vector<int> arr = {1, 2, 3, 4, 5, 6};
	print(arr);
	cout << "found at index: " << binarySearch(arr, 4);
}