#include <bits/stdc++.h>
using namespace std;

void printper( string ques, string ans, int n) {
	if (ques.length() == n) {
		cout << ans << endl;
		return;
	}

	printper(ques, ans + ques[n], n + 1);
	printper(ques, ans, n + 1);

}
int main() {
	string str = "abc";
	printper(str, "", 0);
}


