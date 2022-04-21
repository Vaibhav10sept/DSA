#include<bits/stdc++.h>
using namespace std;

vector<int> FirstNegativeNumberineveryWindowofSizeK(vector<int> arr, int k) {
	int i = 0;
	int j = 0;
	vector<int> ans;
	//i --> represent start of window
	//j --> represent end of window
	//j-i+1 --> is the size of window

	queue<int> q;
	while (j < arr.size()) {
		if (arr[j] < 0) q.push(arr[j]);
		if (j - i + 1 == k) {
			//calculation
			if (!q.empty()) {
				ans.push_back(q.front());
			}
			else {
				ans.push_back(0);
			}

			//now, move the window
			if (arr[i] == q.front()) {
				q.pop();
			}
			i++;
		}
		j++;
	}
	return ans;
}

int main() {
	/*
	LOGIC: here we use map
	*/
	vector<int> arr = { -8, 2, 3, -6, 10};
	int k = 2;
	//output: -8 0 -6 -6

	vector<int> ans = FirstNegativeNumberineveryWindowofSizeK (arr, k);
	for (int ele : ans) cout << ele << " ";
}