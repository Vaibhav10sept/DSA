#include <bits/stdc++.h>
using namespace std;


int main() {

	vector<int> arr = {12, 3, 7, 1, 6, 9};
	int tar = 5;
	int n = arr.size();
	sort(arr.begin(), arr.end());
	for (int i = 0; i < n; n++) {
		int j = i + 1;
		int k = n - 1;
		while (j < k) {
			int curr = arr[j] + arr[k] + arr[i];
			if (tar > curr) {
				j++;
			} else if (curr == tar) {
				cout << "yes";
				return 0;
			} else {
				k--;
			}
		}
	}
	cout << "no";
	return 0;
}