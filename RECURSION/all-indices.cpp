#include <bits/stdc++.h>
using namespace std;

void allIndices(vector<int> arr, int i, int data, vector<int> &ans) {
	if (i == arr.size()) return;
	if (data == arr[i]) {
		ans.push_back(i);
	}
	allIndices(arr, i + 1, data, ans);

}

int main()
{
	vector<int> arr = {100, 20, 3, 4, 3, 6, 8, 3, 8, 500, 8};
	vector<int> ans;
	allIndices(arr, 0, 8, ans);
	for (auto ele : ans) cout << ele << endl;
}