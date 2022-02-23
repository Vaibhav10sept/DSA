#include <bits/stdc++.h>
using namespace std;

void displayArray(vector<int> arr, int i) {
	if (i == arr.size()) return;
	cout << arr[i] << endl;
	displayArray(arr, i + 1);
}

int main()
{
	vector<int> arr = {1, 2, 3, 4, 5};
	displayArray(arr, 0);
}