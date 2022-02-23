#include <bits/stdc++.h>
using namespace std;

void PrintEncoding(string ques, string ans) {
	if (ques.size() == 0) {
		cout << ans << endl;
		return;
	}
	else if (ques.size() == 1) {
		char ch = ques[0];
		int chv = ch - '0';// chv = character value
		if (chv == 0) return;
		else {
			char code = (char)('a' + chv - 1); // ex: converts '1' to 'a'
			ans += code;
			cout << ans << endl;
		}
	}
	//basecases over
	else {
		char ch = ques[0];
		int chv = ch - '0';// chv = character value
		string restOfString = ques.substr(1);
		if (chv == 0) return;
		else {
			char code = 'a' + chv - 1; // ex: converts '1' to 'a'
			PrintEncoding(restOfString, ans + code);
		}

		string ch12 = ques.substr(0, 2); // first 2 char ki string
		string restOfQuestion = ques.substr(2);

		int chv12 = stoi(ch12);

		if (chv12 <= 26) {
			char code = 'a' + chv12 - 1; // ex: converts '1' to 'a'
			PrintEncoding(restOfQuestion, ans + code);
		}
	}
}



int main()
{
	//********************************
	//QUESTION LINK: https://www.youtube.com/watch?v=jUo0Qis4FKU&list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk&index=415
	//***********************************
	PrintEncoding("123", "");
}