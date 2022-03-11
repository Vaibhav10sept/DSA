#include <bits/stdc++.h>
using namespace std;

void stringCompression2( string str) {
	int i = 1;
	char ch = str[0];
	string ans;
	ans += str[0];
	int cnt = 1;

	while (i < str.size()) {
		if (str[i] == str[i - 1]) {
			cnt++;
			// cout << cnt << endl;
		}
		else {
			// string s(1, to_string(cnt));
			std::string s = std::to_string(cnt);
			if (cnt != 1) {
				ans += to_string(cnt);

			}
			// cout << to_string(cnt) << endl;
			ans.push_back(str[i]);
			cnt = 1;
		}
		i++;
	}
	if (cnt != 1) {
		ans += to_string(cnt);
	}
	cout << ans << endl;
}

int main() {
	//************************************
	// VIDEO LINK: https://www.youtube.com/watch?v=6W1MDK7nPZs&list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk&index=545
	//************************************
	string str = "aaabbbbccccefff";
	stringCompression2(str);
}


