#include <bits/stdc++.h>
using namespace std;

bool isPallindrome(string str) {
	int i = 0;
	int j = str.size() - 1;
	while (i < j) {
		if (str[i] != str[j]) {
			return false;
		}
		i++;
		j--;
	}
	return true;
}

void printPallindromicSubstrings( string str) {
	for (int i = 0; i < str.size(); i++) {
		for (int j = 1; j <= str.size() - i; j++) {
			string sub = str.substr(i, j);
			if (isPallindrome(sub)) {
				cout << sub << endl;
			}
		}
	}
}
int main() {
	//************************************
	// VIDEO LINK: https://www.youtube.com/watch?v=_jM3iMT4k7g&list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk&index=542
	//************************************
	string str = "abcc";
	printPallindromicSubstrings(str);
}


