#include <bits/stdc++.h>
using namespace std;

string mySwap(string str, int i, int j) {
	char temp = str[i];
	str[i] = str[j];
	str[j] = temp;
	return str;
}


void helperRecursive(string str, int k, string &maxString) {
	// cout << "str " << str << endl;
	if (str > maxString) {
		maxString = str;
	}
	if (k == 0) {
		return;
	}
	for (int i = 0; i < str.size() - 1; i++) {
		for (int j = i + 1; j < str.size(); j++) {
			if (str[j] > str[i] and (str[j] - '0') % 2 == (str[i] - '0') % 2) {
				string swapped = mySwap(str, i, j);
				helperRecursive(swapped, k - 1, maxString);
			}
		}
	}
}

string maxNumberAfterSwappingSameParity(string str, int k) {
	if (str.size() == 2) {
		if (str[0] % 2 == str[1] % 2) {
			sort(str.begin(), str.end(), greater<char>());
			return str;
		}
		else {
			return str;
		}
	}
	string maxString = "";

	for (int i = 0; i < str.size() - 1; i++) {
		for (int j = i + 1; j < str.size(); j++) {
			if (str[j] > str[i] and (str[j] - '0') % 2 == (str[i] - '0') % 2) {
				string swapped = mySwap(str, i, j);
				helperRecursive(swapped, k - 1, maxString);
			}
		}
	}
	if (maxString.size() == 0) {
		maxString = str;
	}
	return maxString;
}

int main()
{
	/*
	this is a leetcode contest question solution
	*/
	string str = "6459287";
	int k = str.size() / 2 + 2; //IDK why maene +2 kia, bina +2 ye question submit nhi hora tha, wrong answer aa rha tha
	cout << maxNumberAfterSwappingSameParity(str, k);
}