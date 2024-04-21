#include <bits/stdc++.h>
using namespace std;

void PrintPermutationsArrayHelper(vector<int> arr, vector<int> ans, vector<bool> &pickedUp) {
	if (ans.size() == arr.size()) { //BC
		//print ans array
		for (auto ele : ans ) cout << ele << " ";
		cout << endl;
	}

	for (int i = 0; i < arr.size(); i++) {
		if (pickedUp[i] == false) {
			ans.push_back(arr[i]);
			pickedUp[i] = true;
			PrintPermutationsArrayHelper(arr, ans, pickedUp);
			//backtrack -- think, draw, use pen paper
			ans.pop_back();
			pickedUp[i] = false;
		}
	}
}

void PrintPermutationsArray(vector<int> arr) {
	vector<int> ans;
	vector<bool> pickedUp(false);
	PrintPermutationsArrayHelper(arr, ans, pickedUp);
}

int main() {
	/*
	solution link: https://takeuforward.org/data-structure/print-all-permutations-of-a-string-array/#:~:text=Example%201%3A%20Input%3A%20arr%20%3D,return%20all%20the%20possible%20permutations.
	NOTE: I wrote this code myself
	*/
	vector<int> arr = {1, 2, 3};
	PrintPermutationsArray(arr);
}