#include <bits/stdc++.h>
using namespace std;

void print(vector<int> arr) {
	for (auto ele : arr) cout << ele << " ";
	cout << endl;
}

void reverseArray(vector<int> &arr) {
	int li = 0;
	int ri = arr.size() - 1;
	while (li < ri) {
		int temp = arr[li];
		arr[li] = arr[ri];
		arr[ri] = temp;
		li++;
		ri--;
	}
}

int main()
{
	vector<int> arr = {1, 2, 3, 4, 5, 6};
	print(arr);
}