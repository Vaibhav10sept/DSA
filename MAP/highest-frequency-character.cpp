#include<bits/stdc++.h>
using namespace std;

char highestFreqChar(string str) {
	map<char, int> mp;
	for (auto ch : str) {
		mp[ch]++;
	}
	for (auto ele : mp) cout << ele.first << " " << ele.second << endl;
	char ch;
	int maxChar = INT_MIN;
	for (auto ele : mp ) {
		if (ele.second > maxChar) {
			maxChar = ele.second;
			ch = ele.first;
		}
	}
	return ch;
}

int main() {
	string str = "abracadabara";
	cout << "highest freq character is: " << highestFreqChar(str);
}