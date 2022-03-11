#include <bits/stdc++.h>
using namespace std;

void stringCompression1( string str) {
	string ans(1, str[0]);
	for (int i = 1; i < str.size(); i++) {
		if (str[i] != str[i - 1]) {
			ans.push_back(str[i]);
		}
	}
	cout << ans << endl;

}
int main() {
	//************************************
	// VIDEO LINK: https://www.youtube.com/watch?v=6W1MDK7nPZs&list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk&index=545
	//************************************
	string str = "aaabbbbcccceefff";
	stringCompression1(str);
}


