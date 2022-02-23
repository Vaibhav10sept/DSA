#include <bits/stdc++.h>
using namespace std;

void displayArrayReverse(vector<int> arr, int i) {
	if (i == arr.size()) return;
	displayArrayReverse(arr, i + 1);
	cout << arr[i] << endl;
}

int main()
{
	vector<int> arr = {1, 2, 3, 4, 5};
	displayArrayReverse(arr, 0);
}