#include <bits/stdc++.h>
using namespace std;

int SubarraysSumsDivisiblebyK(vector<int> arr, int k) {
	int sum = 0;
	int count = 0;
	map<int, int> mp; //remainder,freq.
	mp[0] = 1; //coz 0 reminder ki freq 1 hai(think)

	for (int i = 0; i < arr.size(); i++) {
		sum += arr[i];

		int rem = sum % k;
		if (rem < 0) rem += k; //convert negative rem to positive rem.

		if (mp.find(rem) != mp.end()) { //found
			int count += mp[rem];
			mp[rem]++;
		}
		else {
			mp[rem] = 1;
		}
	}
	return count;
}

int main() {
	/*
	PREREQUISITE: Longest Subarray with Sum Divisible by K
	VIDEO LINK: https://www.youtube.com/watch?v=QM0klnvTQzk&list=PL-Jc9J83PIiEp9DKNiaQyjuDeg3XSoVMR&index=31
	*/
	vector<int> arr = {2, 3, 5, 4, 5, 3, 4}; //op:4
	int k = 3;
	cout << "ans " << SubarraysSumsDivisiblebyK(arr, k);
}