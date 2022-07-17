#include <bits/stdc++.h>
using namespace std;

int lengthLongestSubarrayWith0Sum(vector<int> arr) {
	//LOGIC: agr sum repeat hota h, to uss range me sum zero hua hoga tbhi sum repeat hua hai,think WV
	//WV: watch video
	map<int, int> mp; //sum,index
	int maxLen = INT_MIN;
	int sum = 0;

	mp[0] = -1;

	for (int i = 0; i < arr.size(); i++) {
		sum += arr[i];

		if (mp.find(sum) == mp.end()) { //nhi mila
			mp[sum] = i;
		}
		else { //mil gya
			int len = i - mp[sum];
			if (len > maxLen) maxLen = len;
		}
	}
	return maxLen;
}

int main() {
	/*
	VIDEO LINK: https://www.youtube.com/watch?v=_yGf2rxwZlA&list=PL-Jc9J83PIiEp9DKNiaQyjuDeg3XSoVMR&index=6
	QUESTION LINK: https://www.geeksforgeeks.org/find-the-largest-subarray-with-0-sum/
	*/
	cout << "ans" << endl;
	vector<int> arr = {15, -2, 2, -8, 1, 7, 10, 23};
	cout << lengthLongestSubarrayWith0Sum(arr) << endl;
}