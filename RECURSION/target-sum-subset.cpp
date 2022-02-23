#include <bits/stdc++.h>
using namespace std;

void targetSumSubset(vector<int> arr, int target, int sum, int idx, string set) {
	if (idx == arr.size()) {
		if (sum == target) {
			cout << set << endl;

		}
		return;
	}
	//LOGIC: EK BAAR INDEX TO SET AND SUM ME INCLUDE KREGE
	//OR DOOSRI BAAR NHI KREGE.

	//set me include krege ki recursive call
	targetSumSubset(arr, target, sum + arr[idx], idx + 1, set + " "  + to_string(arr[idx]));
	//set me include nahi krege ki recursive call
	targetSumSubset(arr, target, sum, idx + 1, set);
}



int main()
{
	//********************************
	//LINK: https://www.geeksforgeeks.org/subarraysubstring-vs-subsequence-and-programs-to-generate-them/

	//NOTE: SUBSEQUENCE AND SUBSET BOTH ARE SAME THING
	//NOTE: SO TOTAL THERE ARE: 2^N SUBSEQUENCES/SUBSETS

	//NOTE: SUBSTRING AND SUBARRAY ARE ALMOST SAME THINGS(DOUBTFULL HAI)
	//NOTE: TOTAL THERE ARE N*(N+1)/2 SUBSTRING/SUBARRAY

	//DIFFERENCE BETWEEN SUBARRAY AND SUBSEQUENCE: SUBARRAY ARE
	//CONTINUES MEANS YOU CANNOT LEAVE ANY ELEMENT IN BETWEEN
	//WHILE SUBSEQUENCE ARE DISCONTINUOUS BUT THE SEQUENCE IS PRESERVED
	//IN BOTH.
	//***********************************
	vector<int> arr = {10, 20, 30, 40, 50, 60};
	targetSumSubset(arr, 70, 0, 0, "");
}