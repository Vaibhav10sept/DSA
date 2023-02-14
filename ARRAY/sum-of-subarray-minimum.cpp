#include <bits/stdc++.h>
using namespace std;

vector<int> nextSmallerIndexRight(vector<int> arr) {
	stack<int> st;
	vector<int> ans(arr.size(), 0);

	for (int i = arr.size() - 1; i >= 0; i--) {
		int ele = arr[i];
		while (!st.empty() and arr[st.top()] > ele) {
			st.pop();
		}
		if (st.empty()) {
			ans[i] = arr.size() - i;
		}
		else { // stack is not empty
			ans[i] = abs(i - st.top());
		}
		st.push(i);
	}

	return ans;
}

vector<int> nextSmallerIndexLeft(vector<int> arr) {
	stack<int> st;
	vector<int> ans(arr.size());

	for (int i = 0; i < arr.size(); i++) {
		int ele = arr[i];
		while (!st.empty() and arr[st.top()] >= ele) {
			st.pop();
		}
		if (st.empty()) {
			ans[i] = i + 1;
		}
		else { //stack is not empty
			ans[i] = abs(i - st.top());

		}
		st.push(i);
	}

	return ans;
}

int sumSubarrayMins(vector<int> arr) {
	// NOTE: WV higly recommended
	vector<int> nextSmallerIndexLeftAns = nextSmallerIndexLeft(arr);
	vector<int> nextSmallerIndexRightAns = nextSmallerIndexRight(arr);
	int sum = 0;

	for (int i = 0; i < arr.size(); i++) {
		cout << nextSmallerIndexLeftAns[i] << " " << nextSmallerIndexRightAns[i] << endl;
	}

	for (int i = 0; i < arr.size(); i++) {
		int rightAns = nextSmallerIndexRightAns[i];
		int leftAns = nextSmallerIndexLeftAns[i];

		//here, hm ek formula use krre which is use can come up yourself, ie, no of subarray that have arrr[i] as minimum
		int noOfSubHaveIAsMin = rightAns * leftAns;
		sum += (arr[i] * noOfSubHaveIAsMin);
	}

	return sum;
}

int main()
{
	/****************************************
	 * VIDEO LINK: https://www.youtube.com/watch?v=9-TXIVEXX2w&t=12s
	 * VIDEO LINK: https://www.youtube.com/watch?v=Ulb3ixSpE4Y
	 * LEETCODE LINK: https://leetcode.com/problems/sum-of-subarray-minimums/description/
	 * PREREQUISITE: next/previous smaller element index (stack)
	 * NOTE: WV higly recommended
	 * **************************************/
	vector<int> arr = {71, 55, 82, 55};
	cout << sumSubarrayMins(arr);
}