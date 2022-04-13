#include <bits/stdc++.h>
using namespace std;

string maximumSwaps(string str) {
	//this code is written by me
	vector<int> rightMaxIdx(str.size());
	rightMaxIdx[str.size() - 1] = str.size() - 1;
	int rightMax = str.size() - 1;
	//filling the right max index array
	for (int i = str.size() - 2; i >= 0; i--) {
		int val = str[i] - '0';
		if (val > str[rightMax] - '0') {
			rightMax = i;
		}
		rightMaxIdx[i] = rightMax;
	}

	for (auto ele : rightMaxIdx) cout << ele << " ";
	cout << endl;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] != str[rightMaxIdx[i]]) {
			swap(str[i], str[rightMaxIdx[i]]);
			//coz at most one swap is allowed, so we are returning after the first swap.
			return str;
		}
	}
	return str;

}

int main() {
	//*********************************
	// VIDEO LINK: https://www.youtube.com/watch?v=IiAd7twX0xU&list=PL-Jc9J83PIiE-TR27GB7V5TBLQRT5RnSl&index=35
	// QUESTION:
	// 1. You are given a number in form of String.
	// 2. You can swap two digits at most once to get the maximum valued number in that string.
	// 3. Return the maximum valued number you can get in form of string.
	//*********************************
	string str = "2736";
	// string str = "98765";
	cout << "max value no. after at most one swap is: " << maximumSwaps(str);
}