#include <bits/stdc++.h>
using namespace std;

string stringWithASCIIDifference(string &str) {
	string ans(1, str[0]);

	for (int i = 1; i < str.size(); i++) {
		int diff = (int)str[i] - (int)str[i - 1];
		ans += to_string(diff);
		ans += str[i];
	}
	return ans;
}

int main()
{
	//******************************************
// A 65
// Z 90
// a 97
// z 122
	// VIDEO LINK: 	https://www.youtube.com/watch?v=PHtNm0B9Ig4&list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk&index=548
	//******************************************
	string str = "abdgca";
	cout << "result: " << stringWithASCIIDifference(str) << endl;
}