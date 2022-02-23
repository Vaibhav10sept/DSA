#include <bits/stdc++.h>
using namespace std;

void PrintPermutations(string ques, string ans) {
	if (ques.size() == 0) {
		cout << ans << endl;
		return;
	}

	for (int i = 0; i < ques.size(); i++) {
		char ch = ques[i];
		string restOfQuestion = ques;
		restOfQuestion.erase(i, 1);
		PrintPermutations(restOfQuestion, ans + ch);
	}

}



int main()
{
	//********************************
	// NO OF PERMUTATIONS = N!
	//***********************************
	PrintPermutations("abc", "");
}