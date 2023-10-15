#include <bits/stdc++.h>
using namespace std;

vector<int> leftnextsmallerindex(vector<int> arr) {
	vector<int> ans(arr.size());
	// ans[0] = -1;
	stack<int> st;
	// st.push(0);
	for (int i = 0; i < arr.size(); i++) {
		while (st.size() > 0 and arr[st.top()] >= arr[i]) st.pop();

		if (st.empty()) {
			ans[i] = -1;
		} else {
			ans[i] = st.top();
		}

		st.push(i);
	}
	return ans;
}

vector<int> rightnextsmallerindex(vector<int> arr) {
	vector<int> ans(arr.size());
	// ans[arr.size() - 1] = arr.size();
	stack<int> st;
	// st.push(arr.size() - 1);
	for (int i = arr.size() - 1; i >= 0; i--) {
		while (st.size() > 0 and arr[st.top()] > arr[i]) st.pop();

		if (st.empty()) {
			ans[i] = arr.size();
		} else {
			ans[i] = st.top();

		}

		st.push(i);
	}
	return ans;

}

int sumSubarrayMins(vector<int> arr) {
	// NOTE: WV higly recommended
	int mod = 1e9 + 7;
	vector<int> nextSmallerIndexLeftAns = leftnextsmallerindex(arr);
	vector<int> nextSmallerIndexRightAns = rightnextsmallerindex(arr);
	long sum = 0;

	for (int i = 0; i < arr.size(); i++) {
		cout << nextSmallerIndexLeftAns[i] << " " << nextSmallerIndexRightAns[i] << endl;
	}

	for (int i = 0; i < arr.size(); i++) {
		int rightAns = nextSmallerIndexRightAns[i];
		int leftAns = nextSmallerIndexLeftAns[i];

		int leftLen = abs(i - leftAns);
		int rightLen = abs(rightAns - i);

		//here, hm ek formula use krre which is use can come up yourself, ie, no of subarray that have arr[i] as minimum
		long long noOfSubHaveIAsMin = (leftLen * rightLen);
		sum = (sum + (arr[i] * noOfSubHaveIAsMin)) % mod;
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
	cout << "Res " << sumSubarrayMins(arr);
}