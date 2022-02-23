#include <bits/stdc++.h>
using namespace std;

void rec(string ques, string ans) {
	if (ques.length() == 0) {
		cout << ans << endl;
		return;
	}
	for (int i = 0; i < ques.length(); i++) {
		char ch = ques[i];
		string left = ques.substr(0, i);
		string right = ques.substr(i + 1);
		string roq = left + right;
		rec(roq, ans + ch);
	}

}
int main() {
	string str;
	cin >> str;
	rec(str, "");
	return 0;

}

