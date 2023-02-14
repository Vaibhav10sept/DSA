#include <bits/stdc++.h>
using namespace std;

// int nextGreaterElement3(string str) {
// 	int minDigit = INT_MAX;
// 	int minIdx = str.size() - 1;
// 	int dipIdx = -1;
// 	int i = str.size() - 1;

// 	//finding the dipIdx.
// 	while (i > 0) {
// 		if (str[i] > str[i - 1]) {
// 			dipIdx = i - 1;
// 			break;
// 		}
// 		i--;
// 	}
// 	//NOTE: 'i', dipidx ke ek age hoga.
// 	//edge case, number is already in maximum form, so directly return the number.
// 	if (dipIdx == -1) {
// 		return -1;
// 	}

// 	//finding

// 	//find the just greater element(ceil) for dip element.
// 	int ceil = INT_MAX;
// 	int ceilIdx;
// 	for (int j = i; j < str.size(); j++) {
// 		if (str[j] > str[dipIdx]) {
// 			if (str[j] < ceil) {
// 				ceil = str[j];
// 				ceilIdx = j;
// 			}
// 		}
// 	}

// 	//swap ceil and dip.
// 	swap(str[ceilIdx], str[dipIdx]);

// 	// reverse the string after the dip.(think)
// 	if (i > 0)
// 		reverse(str.begin() + i, str.end());

// 	return stoi(str);
// }

int nextGreaterElement3(string str) {
	//1. find first dip from right
	int i = str.size() - 2;
	while (i >= 0 and str[i] >= str[i + 1])  {
		i--;
	}

	if (i == -1) return -1;

	//find the just greater than ith index ele(which is the dip)
	int k = str.size() - 1;
	while (str[i] >= str[k]) {
		k--;
	}

	//swap i and k index values
	swap(str[i], str[k]);

	// reverse the string after the dip.(think)
	if (i >= 0)
		reverse(str.begin() + i + 1, str.end());


	// object from the class stringstream
	stringstream geek(str);

	long long x;
	geek >> x;

	if (x > INT_MAX) return -1;
	return x;
}

int main() {
	//*********************************
	// VIDEO LINK: https://www.youtube.com/watch?v=eAfJJyaAmes
	// QUESTION:
	// 1. Given a positive number 'n' in form of String.
	// 2. Find the smallest number which has exactly the same digits existing in the number 'n' and is greater in value than 'n'.
	// 3. If no such positive number exists, return -1 as string.
	//*********************************
	// string num = "2147483486";
	string num = "1200000";

	cout << "answer " << nextGreaterElement3(num);
}