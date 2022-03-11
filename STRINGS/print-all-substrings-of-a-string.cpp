#include <bits/stdc++.h>
using namespace std;

void printSubstring(string str) {
	for (int i = 0; i < str.size(); i++) {
		for (int j = 1; j <= str.size() - i; j++) {
			cout << str.substr(i, j) << endl;
		}
	}
}

int main() {
	//************************************
	// VIDEO LINK: https://www.youtube.com/watch?v=_jM3iMT4k7g&list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk&index=542
	//************************************
	string str = "abc";
	printSubstring(str);
}