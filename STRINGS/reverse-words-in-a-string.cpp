#include <bits/stdc++.h>
using namespace std;

string reverseWordsInAString(string str) {
	//this code is written by me, koi video ni dekhi bs neeche link pe jake solution dekha tha fr khud se ye code likha
	int i = 0;
	string temp = "";
	string ans = "";
	while (i < str.size()) {
		char ch = str[i];
		if (ch != ' ') {
			temp += ch;
		}
		else { //ch == ' '
			if (ans == "") ans = temp;
			else ans = temp + " " + ans;
			temp = "";
			//to remove more than one ' '.(ye logic mene likha h)
			while (i + 1 < str.size() and str[i + 1] == ' ') i++;
		}
		i++;
	}

	//for the last word
	//If not empty string then add to the result(Last word is added)
	if (temp != "") {
		if (ans != "") ans = temp + " " + ans;
		else ans = temp;
	}

	return ans;
}

int main()
{
	/*
	QUESTION: https://takeuforward.org/data-structure/reverse-words-in-a-string/
	*/
	string s = "  hello world  ";
	cout << reverseWordsInAString(s);
}