#include <bits/stdc++.h>
using namespace std;

bool isVowel(char ch) {
	if (ch == 'a' or ch == 'e' or ch == 'i' or ch == 'o' or ch == 'u'
	        or ch == 'A' or ch == 'E' or ch == 'I' or ch == 'O' or ch == 'U') {
		return true;
	}
	return false;
}

void reverseVowelsOfAString(string &str) {
	int i = 0;
	int j = str.size() - 1;
	while (i < j) {
		if (isVowel(str[i]) and isVowel(str[j])) {
			swap(str[i], str[j]);
			i++;
			j--;
		}
		else {
			while (isVowel(str[i]) == false and i < j) i++;
			while (isVowel(str[j]) == false and i < j) j--;
		}
	}
}

int main() {
	//*********************************
	// NOTE: tow pointers approach is used here.
	// VIDEO LINK: https://www.youtube.com/watch?v=hgtH9FIZrOE&list=PL-Jc9J83PIiE-TR27GB7V5TBLQRT5RnSl&index=25
	// QUESTION:
	// 1. Given a string 's'.
	// 2. Reverse only all the vowels in the string and return it.
	// 3. The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both cases.
	//*********************************
	string str = "hello";
	reverseVowelsOfAString(str);
	cout << str << endl;
}