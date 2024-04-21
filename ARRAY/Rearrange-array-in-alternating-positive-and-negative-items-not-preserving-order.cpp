#include <bits/stdc++.h>
using namespace std;

void rearrangeInAlternatingPositiveAndNegative(vector<int> &arr) {
	int i = 0;
	int j = arr.size() - 1;

	while (i < j) {
		if (arr[i] >= 0) {
			i++;
		}
		else {
			swap(arr[i], arr[j]);
			j--;
		}
	}
	//now, array has first positve ele and then all the negative elemnts
	// for (auto ele : arr) cout << ele << " ";
	// cout << endl;
	//put the ele in alternating negative and positive
	i = 0;
	j = arr.size() - 1;
	while (i < arr.size()) {
		swap(arr[i], arr[j]);
		i += 2;
		j--;
	}
}

int main()
{
	//*****************************
	// QUESTION LINK: https://www.geeksforgeeks.org/rearrange-array-alternating-positive-negative-items-o1-extra-space/
	// VIDEO LINK: https://www.youtube.com/watch?v=zUPMACE0uBs
	//*****************************************
	vector<int> arr = { -5, -2, 5, 2, 4, 7, 1, 8, 0, -8 };
	rearrangeInAlternatingPositiveAndNegative(arr);
	cout << "res" << endl;
	for (auto ele : arr) cout << ele << " ";
}