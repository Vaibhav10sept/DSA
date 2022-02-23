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

void printSubarrays(vector<int> arr) {
	for (int i = 0; i < arr.size(); i++) {
		for (int j = i; j < arr.size(); j++) {
			for (int k = i; k <= j; k++) {
				cout << arr[k] << " ";
			}
			cout << endl;
		}
	}

}

int main()
{
	vector<int> arr = {10, 20, 30};
	printSubarrays(arr);
}