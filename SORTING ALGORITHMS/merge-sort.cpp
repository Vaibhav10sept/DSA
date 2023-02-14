#include<bits/stdc++.h>
using namespace std;

vector<int> mergeTwoSortedArray(vector<int> leftSortedHalf, vector<int> rightSortedHalf) {
	vector<int> ans(leftSortedHalf.size() + rightSortedHalf.size());
	int i = 0;
	int j = 0;
	int k = 0;

	while (i < leftSortedHalf.size() and j < rightSortedHalf.size()) {
		if (leftSortedHalf[i] < rightSortedHalf[j]) {
			ans[k] = leftSortedHalf[i];
			i++;
			k++;
		}
		else {
			ans[k] = rightSortedHalf[j];
			k++;
			j++;
		}
	}

	while (i < leftSortedHalf.size()) {
		ans[k] = leftSortedHalf[i];
		i++;
		k++;
	}
	while (j < rightSortedHalf.size()) {
		ans[k] = rightSortedHalf[j];
		j++;
		k++;
	}

	return ans;
}

vector<int> mergeSort(vector<int> arr,  int low, int high) {
	if (low == high) { //single value array is sorted, think
		vector<int> baseArray;
		baseArray.push_back(arr[low]);
		return baseArray;
	}

	int mid = (low + high) / 2;
	vector<int> leftSortedHalf = mergeSort(arr, low, mid);
	vector<int> rightSortedHalf =  mergeSort(arr, mid + 1, high);
	return mergeTwoSortedArray(leftSortedHalf, rightSortedHalf);
}

int main() {
	//**************************************
	//video link: https://www.youtube.com/watch?v=aiUHB-3EOg8&list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk&index=500
	//*******************************************
	vector<int> arr = {5, 9, 8, 2, 1, 4, 3};
	vector<int> ans = mergeSort(arr, 0, arr.size() - 1);
	for (int ele : ans) cout << ele << " ";
}