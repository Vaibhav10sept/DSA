#include <bits/stdc++.h>
using namespace std;

void PrintEncoding(string ques, string ans) {
	if (ques.size() == 0) {
		cout << ans << endl;
		return;
	}
	else if (ques.size() == 1) {
		char ch = ques[0];
		int chv = ch - '0';// chv = character value; character to int conversion
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
		int chv = ch - '0';// chv = character value; character to int conversion
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
	//***************************
	// there is a question "COUNT ENCODINGS" which counts all possible encodings
	// (you can search it using ctrl + p)
	// "print encoding" is recursive while "count encodings" is DP.
	//**************************************************
	PrintEncoding("1012", "");
}
