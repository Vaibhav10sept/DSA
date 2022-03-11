#include<bits/stdc++.h>
using namespace std;

void countSort(vector<string> &arr, int div, int mod, int range) {
	vector<string> ans(arr.size());
	vector<int> freq(range);

	//NOTE: "ele/exp%10" this will give us the digit.
	//filling up the freq array.
	for (string ele : arr) {
		freq[stoi(ele) / div % mod]++;
		// cout << ele / div % mod << endl;
	}

	//creating prefix sum array from freq array
	for (int i = 1; i < freq.size(); i++) {
		freq[i] += freq[i - 1];
	}

	//filling up the ans array by iterating the arr backward(to make it stable sorting algo)
	for (int i = arr.size() - 1; i >= 0; i--) {
		ans[freq[stoi(arr[i]) / div % mod] - 1] = arr[i];
		freq[stoi(arr[i]) / div % mod]--;
	}

	//filling original array with the help of ans array.
	for (int i = 0; i < ans.size(); i++) {
		arr[i] = ans[i];
	}

}


void dateSort(vector<string> &arr) {
	countSort(arr, 1000000, 100, 32); // for days
	countSort(arr, 10000, 100, 13); // for month
	countSort(arr, 1, 10000, 2501); // for year
}

int main() {
	//**************************************
	//VIDEO LINK: https://www.youtube.com/watch?v=YdzCuP6LwVg&list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk&index=538
	//application of radix sort
	//pehle date sort hogi, fir months, fir year(think)
	//*******************************************
	vector<string> arr = { "11081987", "12041989", "12041996", "20101996" , "05061997"};

	dateSort(arr);
	for (auto ele : arr) cout << ele << endl;
}

