#include <bits/stdc++.h>
using namespace std;

void printper( string ques, string ans, int idx) {
	if (ques.length() == idx) {
		cout << ans << endl;
		return;
	}

	printper(ques, ans + ques[idx], idx + 1);
	printper(ques, ans, idx + 1);

}
int main() {
	//************************************
	// VIDEO LINK: https://www.youtube.com/watch?v=_jM3iMT4k7g&list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk&index=542
	//************************************
	string str = "abc";
	printper(str, "", 0);
}


