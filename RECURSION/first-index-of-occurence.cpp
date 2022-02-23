#include <bits/stdc++.h>
using namespace std;

int firstIndex(vector<int> arr, int i, int data) {
	if (i == arr.size()) return 0;
	if (arr[i] == data) return i;
	else return firstIndex(arr, i + 1, data);
}



int main()
{
	vector<int> arr = {100, 20, 3, 4, 3, 6, 8, 3, 8, 500, 8};
	cout << firstIndex(arr, 0, 8) << endl;
}