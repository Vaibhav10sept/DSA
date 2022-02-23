#include<bits/stdc++.h>
using namespace std;

void countSort(vector<int> &arr) {
	vector<int> ans(arr.size());
	int maxElement = *std::max_element(arr.begin(), arr.end());
	int minElement = *std::min_element(arr.begin(), arr.end());
	int range = maxElement - minElement + 1;
	vector<int> freq(range);

	//filling up the freq array.
	for (auto ele : arr) {
		freq[ele - minElement]++;
	}

	//creating prefix sum array from freq array
	for (int i = 1; i < freq.size(); i++) {
		freq[i] = freq[i - 1] + freq[i];
	}

	//filling up the ans array. by iterating the arr backward(to make it stable sorting algo)
	for (int i = arr.size() - 1; i >= 0; i--) {
		ans[freq[arr[i] - minElement] - 1] = arr[i];
		freq[arr[i] - minElement]--;
	}

	for (int ele : ans) cout << ele << " ";
}

int main() {
	//**************************************
	//USE CASE: when the data is large and the data doesn't vary much(is in range),
	//like rank list. example: rank list in an examination.
	//VIDEO LINK: https://www.youtube.com/watch?v=p-OyKUgIrx4&list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk&index=504
	//count sort is an stable sorting algorithm.
	//*******************************************
	vector<int> arr = {5, 3, 2, 8, 6, 9, 9, 9, 9, 10};
	countSort(arr);
}

