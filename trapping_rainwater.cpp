#include <bits/stdc++.h>
using namespace std;

vector<int> rightmax(vector<int> arr) {
	vector<int> ans(arr.size());
	ans[ans.size() - 1] = arr[arr.size() - 1];

	for (int i = arr.size() - 2; i >= 0; i--) {
		ans[i] = max(arr[i], ans[i + 1]);
	}
	return ans;
}
int main() {
	std::vector<int> arr = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
	vector<int> right = rightmax(arr);
	// for (int i : right)cout << i << endl;
	int ans = 0;
	int leftmax = arr[0];
	for (int i = 0; i < arr.size(); i++) {
		leftmax = max(arr[i], leftmax);
		int minh = min(leftmax, right[i]);
		int reduced = minh - arr[i];
		ans += reduced;

	}
	cout << ans;
}