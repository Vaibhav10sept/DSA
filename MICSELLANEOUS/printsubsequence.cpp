#include <bits/stdc++.h>
using namespace std;

void pss(string ques, string ans) {
	if (ques.length() == 0) {
		cout << ans << endl;
		return;
	}
	char ch = ques[0];
	string ros = ques.substr(1);
	// cout << ch << endl;

	pss(ros, ans + "");
	pss(ros, ans + ch);
}

int main() {
	string str = "abc";
	cin >> str;
	pss(str, "");

}