#include <bits/stdc++.h>
using namespace std;

void rearrangeInAlternatingPositiveAndNegative(vector<int> &arr) {
	int i = 0;
	int j = arr.size() - 1;

	while (i < j) {
		if (arr[i] < 0) { // means negative elemnt hoga
			swap(arr[i], arr[j]);
			i++;
			j--;
		}
		else { //arr[i] > 0 --> positive elemnt hoga
			i++;
		}
	}
	//now, array has first positve ele and then all the negative elemnts
	for (auto ele : arr) cout << ele << " ";
}

int main()
{
	//*****************************
	// QUESTION LINK: https://www.geeksforgeeks.org/rearrange-array-alternating-positive-negative-items-o1-extra-space/
	// VIDEO LINK: https://www.youtube.com/watch?v=zUPMACE0uBs
	//*****************************************
	vector<int> arr = {1, 2, 3, -4, -1, 4};
	rearrangeInAlternatingPositiveAndNegative(arr);
	for (auto ele : arr) cout << ele << " ";
}