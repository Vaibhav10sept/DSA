#include <bits/stdc++.h>
using namespace std;

void printStringPermutations(string ques, string ans) {
    if (ques.size() == 0) {
        cout << ans << endl;
        return;
    }
    for (int i = 0; i < ques.size(); i++) {
        char ch = ques[i];
        string restOfQuestion = ques;
        restOfQuestion.erase(i, 1);
        string s(1, ch);
        printStringPermutations(restOfQuestion, ans + s);
    }
}


int main() {
    //******************************************
    // NOTE: total no of permutations: size!
    // VIDEO LINK:  https://www.youtube.com/watch?v=sPAT_DbvDj0
    //******************************************
    string str = "abc";
    printStringPermutations(str, "");
}
