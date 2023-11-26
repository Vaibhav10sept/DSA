#include <bits/stdc++.h>
using namespace std;

int countSting(string str) {
	//non itiutive logic, wv
	int curr = 1;
	int prev = 0;
	int countOfSubstrings = 0;

	for (int i = 1; i < str.size(); i++) {
		if (str[i - 1] == str[i]) curr++;

		else { //str[i-1] != str[i]
			countOfSubstrings += min(prev, curr);
			prev = curr;
			curr = 1;
		}
	}

	countOfSubstrings += min(prev, curr);

	return countOfSubstrings;
}


int main() {
	/************************************
	 * NOTE: wv if requried
	 * QUESTION: https://leetcode.com/problems/count-binary-substrings/
	// VIDEO LINK: https://www.youtube.com/watch?v=OJWKzff4Ivg
	//************************************/
	string s = "00110011";
	cout << countSting(s);

}


