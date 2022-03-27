#include <bits/stdc++.h>
using namespace std;

string maximumSwapsConstSpaceApproach(string str) {
	vector<int> lastIndex(10);
	//filling up the last index array
	for (int i = 0; i < str.size(); i++) {
		int digit = str[i] - '0';
		lastIndex[digit] = i;
	}

	for (int i = 0; i < str.size(); i++) {
		int digit = str[i] - '0';
		int larger = 9;
		while (larger > digit) {
			if (lastIndex[larger] > i) {
				swap(str[i], str[lastIndex[larger]]);
				return str;
			}
			larger--;
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
	cout << "max value no. after at most one swap is: " << maximumSwapsConstSpaceApproach(str);
}