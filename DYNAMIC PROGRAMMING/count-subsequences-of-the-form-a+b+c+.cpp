#include <bits/stdc++.h>
using namespace std;


int countSubsequencesOfTheFormABC(string str) {
	//Please watch attached video(link) for more understanding.
	int a = 0;
	int ab = 0;
	int abc = 0;
	for (char ch : str) {
		if (ch == 'a') {
			a = 2 * a + 1;
		}
		else if (ch == 'b') {
			ab = 2 * ab + a;
		}
		else { //'c'
			abc = 2 * abc + ab;
		}
	}
	return abc;
}

void printSubsequencesOfTheFormABCRecursive(string ans, string ques) {

	if (ques.size() == 0) {
		bool b = false;
		bool c = false;
		bool pass = true;
		if (ans[0] != 'a') {
			return;
		}
		for (int i = 1; i < ans.size(); i++) {
			if (ans[i] == 'a') {
				if (ans[i - 1] != 'a') {
					pass = false;
					break;
				}
			}
			else if (ans[i] == 'b') {
				b = true;
				if (ans[i - 1] != 'a' and ans[i - 1] != 'b') {
					pass = false;
					break;
				}
			}
			else {
				c = true;
				if (ans[i - 1] != 'b' and ans[i - 1] != 'c') {
					pass = false;
					break;
				}
			}
		}
		if (pass and b and c) cout << ans << endl;
		return;
	}
	int ch = ques[0];
	//remove 0th from ques
	string restOfQuestion = ques.substr(1);// bc
	string s(1, ch);
	printSubsequencesOfTheFormABCRecursive(ans , restOfQuestion);
	printSubsequencesOfTheFormABCRecursive(ans + s, restOfQuestion);

}

int main()
{
	//***************************
	// video link: https://www.youtube.com/watch?v=IV9pbZsi5cc&list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk&index=487
	//NOTE: SUBSEQUENCE AND SUBSET BOTH ARE SAME THING
	//NOTE: SO TOTAL THERE ARE: 2^N SUBSEQUENCES/SUBSETS

	//NOTE: SUBSTRING AND SUBARRAY ARE ALMOST SAME THINGS(DOUBTFULL HAI)
	//NOTE: TOTAL THERE ARE N*(N+1)/2 SUBSTRING/SUBARRAY

	//DIFFERENCE BETWEEN SUBARRAY AND SUBSEQUENCE: SUBARRAY ARE
	//CONTINUES MEANS YOU CANNOT LEAVE ANY ELEMENT IN BETWEEN
	//WHILE SUBSEQUENCE ARE DISCONTINUOUS BUT THE SEQUENCE IS PRESERVED
	//IN BOTH.
	//**************************************************
	string str = "abcabc";
	cout << "count is: " << countSubsequencesOfTheFormABC(str) << endl;
	printSubsequencesOfTheFormABCRecursive("", str);
}