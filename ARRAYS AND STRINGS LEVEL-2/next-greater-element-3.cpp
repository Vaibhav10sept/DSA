#include <bits/stdc++.h>
using namespace std;

int nextGreaterElement3(string str) {
	int minDigit = INT_MAX;
	int minIdx = str.size() - 1;
	int dipIdx = -1;
	int i = str.size() - 1;

	//finding the dipIdx.
	while (i > 0) {
		if (str[i] > str[i - 1]) {
			dipIdx = i - 1;
			break;
		}
		i--;
	}
	if (dipIdx == -1) {
		return stoi(str);
	}

	//find the just greater element(ceil) for dip element.
	int ceil = INT_MAX;
	int ceilIdx;
	for (int j = i; j < str.size(); j++) {
		if (str[j] > str[dipIdx]) {
			if (str[j] < ceil) {
				ceil = str[j];
				ceilIdx = j;
			}
		}
	}

	//swap ceil and dip.
	swap(str[ceilIdx], str[dipIdx]);

	// reverse the string after the dip.(think)
	if (i > 0)
		reverse(str.begin() + i, str.end());

	return stoi(str);
}

int main() {
	//*********************************
	// VIDEO LINK: https://www.youtube.com/watch?v=eAfJJyaAmes
	// QUESTION:
	// 1. Given a positive number 'n' in form of String.
	// 2. Find the smallest number which has exactly the same digits existing in the number 'n' and is greater in value than 'n'.
	// 3. If no such positive number exists, return -1 as string.
	//*********************************
	string num = "34";

	cout << nextGreaterElement3(num);
}