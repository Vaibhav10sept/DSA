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
vector<int> inverseArray(vector<int> arr) {
	vector<int> res(arr.size());
	for (int i = 0; i < arr.size(); i++) {
		res[arr[i]] = i;
	}
	return res;
}

int main()
{
	vector<int> arr = {3, 4, 1, 2, 0};
	print(arr);
	vector<int> res = inverseArray(arr);
	print(res);
}