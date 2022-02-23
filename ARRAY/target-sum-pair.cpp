#include <bits/stdc++.h>
using namespace std;

int targetSumPair(vector<int> arr, int target) {
	int left = 0;
	int right = arr.size() - 1;
	sort(arr.begin(), arr.end());
	while (left < right) {
		if (arr[left] + arr[right] < target) {
			left++;
		}
		else if (arr[left] + arr[right] > target) {
			right--;
		}
		else { //equal hai
			cout << arr[left] << " " << arr[right] << endl;
			left++;
			right--;
		}
	}
}

int main()
{
	//*****************************
	//NOTE: two pointer approach
	// video link: https://www.youtube.com/watch?v=4t9jv9AkVdE&list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk&index=508
	// time complexity: nlogn
	//*****************************************
	vector<int> arr = {7, 15, 3, 18, 6, 4, 19, 2, 12, 11, 9};
	int target = 15;
	targetSumPair(arr, target);
}