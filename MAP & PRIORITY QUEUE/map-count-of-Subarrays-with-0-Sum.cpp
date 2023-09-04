#include <bits/stdc++.h>
using namespace std;

int countSubarrayWith0Sum(vector<int> arr) {
	//LOGIC: agr sum repeat hota h, to uss range me sum zero hua hoga tbhi sum repeat hua hai,think WV
	//WV: watch video
	map<int, int> mp; //sum,freq of that sum.
	int sum = 0;
	int count = 0;

	//think
	mp[0] = 1;

	for (int i = 0; i < arr.size(); i++) {
		sum += arr[i];

		if (mp.find(sum) == mp.end()) { //nhi mila
			mp[sum] = 1;
		}
		else { //mil gya
			//WV for below logic
			count += mp[sum];
			mp[sum]++; //freq dba do
		}
	}
	return count;
}

int main() {
	/*
	PREREQUISITE: largest subarray with 0 sum
	VIDEO LINK: https://www.youtube.com/watch?v=C9-n_H7dsvU&list=PL-Jc9J83PIiEp9DKNiaQyjuDeg3XSoVMR&index=7
	QUESTION LINK:
	*/
	cout << "ans" << endl;
	vector<int> arr = {2, 8, -3, -5, 2, -4, 6, 1, 2, 1 - 3, 4};
	cout << countSubarrayWith0Sum(arr) << endl;
}