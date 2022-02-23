#include <bits/stdc++.h>
using namespace std;

void print(vector<int> arr) {
	for (auto ele : arr) cout << ele << " ";
	cout << endl;
}

void ceilAndFloor(vector<int> arr, int data) {
	int left = 0;
	int right = arr.size() - 1;
	int ceil = 0;
	int floor = 0;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (data < arr[mid]) {
			right = mid - 1;
			ceil = arr[mid];
		}
		else if (data > arr[mid] ) {
			left = mid + 1;
			floor = arr[mid];
		}
		else {
			// data found
			floor = arr[mid];
			ceil = arr[mid];
			break;
		}
	}
	cout << "floor " << floor << "\n" << "ceil " << ceil << endl;

}

int main()
{
	vector<int> arr = {10, 20, 30, 40, 50, 60};
	print(arr);
	ceilAndFloor(arr, 25);
}