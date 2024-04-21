#include <bits/stdc++.h>
using namespace std;

int minFlips(string str) {
	//nice logic, wv, think ,cs  dry run
	//LOGIC: there can be only two cases
	//excample if str is 110
	//then case1         101 --> even me 1 hai
	//and  case2         010 --> even me 0 hai
	string case1 = ""; //even index has 1
	string case2 = ""; //even index has 0
	int n = str.size();

	for (int i = 0; i < n; i++) {
		if (i % 2 == 0) { //even index
			case1 += '1';
			case2 += '0';
		}
		else { //odd index
			case1 += '0';
			case2 += '1';
		}
	}

	//compare case1 and case2 with given string and return the min flip
	int case1Flips = 0;
	int case2Flips = 0;
	for (int i = 0; i < n; i++) {
		if (str[i] != case1[i]) case1Flips++;
		if (str[i] != case2[i]) case2Flips++;
	}

	return min(case1Flips, case2Flips);
}


int main() {
	/************************************
	 * NOTE:
	 * QUESTION: https://practice.geeksforgeeks.org/problems/min-number-of-flips3210/1?utm_source=geeksforgeeks&utm_medium=article_practice_tab&utm_campaign=article_practice_tab
	// VIDEO LINK: https://www.youtube.com/watch?v=F0E7k6X_kt8
	//************************************/
	string s = "0001010111";
	cout << minFlips(s);
}


