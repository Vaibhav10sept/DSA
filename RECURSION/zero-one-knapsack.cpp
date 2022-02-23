#include <bits/stdc++.h>
using namespace std;

void zeroOneKnapsackRecursive(int idx, int sum, int &ans, vector<int> value, vector<int> weight, int capacity) {
	//base case
	if (capacity < 0) return;
	if (capacity == 0) {
		ans = std::max(ans, sum);
		return;
	}
	if (idx == value.size()) {
		ans = std::max(ans, sum);
		return;
	}
	//base case ends


	//include kr rhe hai
	zeroOneKnapsackRecursive(idx + 1, sum + value[idx], ans, value, weight, capacity - weight[idx]);
	//include nahi kr rahe hai
	zeroOneKnapsackRecursive(idx + 1, sum, ans, value, weight, capacity);

}

int main()
{
	//**************************
	//I WROTE THIS CODE BY WATCHING DP PROBLEM OF ZERO ONE
	//KNAPSACK(PEPCODING).
	//******************************************
	vector<int> value = {15, 14, 10, 45, 30};
	vector<int> weight = {2, 5, 1, 3, 4};
	int capacity = 7;
	int ans;
	zeroOneKnapsackRecursive(0, 0, ans, value, weight, capacity);
	cout << "result " << ans << endl;
}