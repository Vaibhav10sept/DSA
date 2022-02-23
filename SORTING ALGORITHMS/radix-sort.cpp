#include<bits/stdc++.h>
using namespace std;

void countSort(vector<int> &arr, int exp) {
	vector<int> ans(arr.size());
	vector<int> freq(10);

	//NOTE: "ele/exp%10" this will give us the digit.
	//filling up the freq array.
	for (int ele : arr) {
		freq[ele / exp % 10]++;
	}

	//creating prefix sum array from freq array
	for (int i = 1; i < freq.size(); i++) {
		freq[i] += freq[i - 1];
	}

	//filling up the ans array by iterating the arr backward(to make it stable sorting algo)
	for (int i = arr.size() - 1; i >= 0; i--) {
		ans[freq[(arr[i] / exp) % 10] - 1] = arr[i];
		freq[(arr[i] / exp) % 10]--;
	}

	//filling original array with the help of ans array.
	for (int i = 0; i < ans.size(); i++) {
		arr[i] = ans[i];
	}

}

void radixSort(vector<int> &arr) {
	int maxElement = *max_element(arr.begin(), arr.end());
	int exp = 1;
	while (exp < maxElement) {
		countSort(arr, exp);
		exp *= 10;
	}
}

int main() {
	//**************************************
	//NOTE: dependency on count sort(with some modifications)
	//VIDEO LINK: https://www.youtube.com/watch?v=a5e7RgCdel0&list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk&index=510
	//radix sort is an stable sorting algorithm as count sort
	//*******************************************
	vector<int> arr = {5, 665, 234, 5687, 124, 485, 258};
	radixSort(arr);
	for (auto ele : arr) cout << ele << " ";
}

