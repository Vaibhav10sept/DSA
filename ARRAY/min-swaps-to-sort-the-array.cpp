#include <bits/stdc++.h>
using namespace std;

int minSwaps(vector<int>&arr)
{
	//wv recommended
	vector<pair<int, int>> vec; //pair -> ele,index
	for (int i = 0; i < arr.size(); i++) {
		vec.push_back({arr[i], i});
	}
	sort(vec.begin(), vec.end());


	int swapCounts = 0;
	for (int i = 0; i < arr.size(); i++) {
		int ind = vec[i].second;
		if (ind != i) { //swaping hue hai
			swap(vec[i], vec[ind]);
			i--; //think, wv, smjh aa gya tha
			swapCounts++;
		}
	}
	return swapCounts;
}

int main()
{
	/*
	NOTE: good question wv recommended
	QUESTION: https://practice.geeksforgeeks.org/problems/minimum-swaps/1
	VIDEO: https://www.youtube.com/watch?v=1BxbBgNSwHo&t=826s
	*/
	vector<int> nums = {10, 19, 6, 3, 5};
	cout << minSwaps(nums);
}