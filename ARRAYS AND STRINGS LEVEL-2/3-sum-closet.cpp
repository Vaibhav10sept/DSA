#include <bits/stdc++.h>
using namespace std;

int threeSumCloset(vector<int> arr, int target) {
	//code pattern is similar to 3 sum
	sort(arr.begin(), arr.end());
	int ans = 0;
	int ansSumDiff = INT_MAX;
	for (int i = 0; i < arr.size(); i++) {
		int sum = 0;
		int front = i + 1;
		int back = arr.size() - 1;

		while (front < back) {
			sum = arr[i] + arr[front] + arr[back];

			if (abs(target - sum) < ansSumDiff) {
				ans = sum;
				ansSumDiff = abs(target - sum);
			}

			if (sum < target) {
				front++;
			}
			else if (sum > target) {
				back--;
			}
			else {
				return sum;
			}
		}
	}
	return ans;
}

int main() {
	/*********************************
	// PREREQUISITE: "3sum-target-sum-unique-triplets"(Similar code pattern)
	// VIDEO LINK: https://www.youtube.com/watch?v=anuarmFjTGU
	// QUESTION: https://leetcode.com/problems/3sum-closest/description/
	//*********************************/
	vector<int> nums = { -1, 2, 1, -4};
	int target = 1;
	cout << threeSumCloset(nums, target);

}