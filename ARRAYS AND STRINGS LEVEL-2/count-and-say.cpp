#include <bits/stdc++.h>
using namespace std;

string countAndSay(int n) {
	if (n == 1) return "1";
	if (n == 2) return "11";

	string str = "11";
	for (int i = 3; i <= n; i++) {
		string temp = "";
		str.append("&"); //ek extra char add krte h, kuch bhi add kr skte h doesn't matter, dry run krke dekho pta chl jaega add krne ki jrurt kyo h.
		int count = 1;
		for (int j = 1; j < str.size(); j++) {
			if (str[j - 1] == str[j]) {
				count++;
			}
			else {
				temp += to_string(count);
				temp += str[j - 1];
				count = 1;
			}
		}
		str = temp;

	}
	return str;
}

int main()
{
	/*
	VIDEO: https://www.youtube.com/watch?v=1YUqtoT9YoE
	QUESTION: https://leetcode.com/problems/count-and-say/description/
	*/

	int n = 4;
	cout << countAndSay(n);
}