#include <bits/stdc++.h>
using namespace std;

bool validPallindrome(string s) {
	int i = 0;
	int j = s.length() - 1;
	while (i < j)
	{
		while (i < j && !isalnum(s[i]))i++;
		while (i < j && !isalnum(s[j]))j--;
		s[i] = tolower(s[i]);
		s[j] = tolower(s[j]);
		if (s[i] != s[j]) {
			return false;
		}
		i++;
		j--;
	}
	return true;
}

int main() {
	/*
	*********************************
	VIDEO LINK:
	*********************************
	*/
	string s = "A man, a plan, a canal: Panama";
	cout << validPallindrome(s);
}