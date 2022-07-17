#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(vector<int> arr, int target) {
	vector<vector<int>> ans;
	//edge case
	if (arr.size() == 0) return ans;

	int n = arr.size();
	sort(arr.begin(), arr.end());

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			//here(in this "j" for loop) the technique is similar to 2 sum
			//to resolve overflowing int; *1L(typecasting to long)
			long newTarget = target - arr[i] - arr[j] * 1L;

			long long start = j + 1;
			long long end = n - 1;

			while (start < end) {
				long long twoSum = arr[start] + arr[end];
				if (twoSum < newTarget) {
					start++;
				}
				else if (twoSum > newTarget) {
					end--;
				}
				else { //twosum == newTarget
					vector<int> inner = {arr[i], arr[j], arr[start], arr[end]};
					ans.push_back(inner);

					//removing duplicacy(so that all the quads are unique)
					while (start < end and arr[start] == inner[2]) start++;
					while (start < end and arr[end] == inner[3]) end--;

				}
			}
			//removing duplicacy for "j" vala for loop
			//NOTE: "j+1" use kia not "j",coz hm for loop me h, j+1 ko check krelege to for j ko j+1 to kr dega na islie(WV)
			while (j + 1 < n and arr[j + 1] == arr[j]) j++;
		}
		//removing duplicacy for "i" vala for loop
		//NOTE: "i+1" use kia not "i",coz hm for loop me h, i+1 ko check krelege to for i ko i+1 to kr dega na islie(WV)
		while (i + 1 < n and arr[i + 1] == arr[i]) i++;
	}
	return ans;
}

int main() {
	//*********************************
	// NOTE: we use 2 sum algorithm/technique here.
	// PREREQUISITE: "2 sum"
	// VIDEO LINK: https://www.youtube.com/watch?v=4ggF3tXIAp0&t=30s
	// QUESTION: https://leetcode.com/problems/4sum/
	//*********************************
	// vector<int> arr = {1, 0, -1, 0, -2, 2};
	// int target = 0;

	vector<int> arr = {1000000000, 1000000000, 1000000000, 1000000000};
	int target = -294967296;
	vector<vector<int>> res = fourSum(arr, target);
	for (auto vec : res) {
		for (auto ele : vec) cout << ele << " ";
		cout << endl;
	}

}



