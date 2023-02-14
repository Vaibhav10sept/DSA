#include <bits/stdc++.h>
using namespace std;

//APPROACH: question, answer vali approach

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
	// NOTE: there is a backtracking problem "backtracking-premutations"
	// NO OF PERMUTATIONS = N!
	//***********************************
	PrintPermutations("01", "");
}