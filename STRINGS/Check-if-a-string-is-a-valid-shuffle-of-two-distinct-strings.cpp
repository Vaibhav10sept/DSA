#include <bits/stdc++.h>
using namespace std;

bool checkIsValidShuffle(string first, string second, string result) {
	// * NOTE: wv if required, easy h think, dry run, try yourself
	int l1 = first.size();
	int l2 = second.size();
	int l3 = result.size();
	int i = 0; //pointer to first string
	int j = 0; //pointer to second string
	int k = 0; //pointer to result string

	while (k < l3) {
		if (first[i] == result[k]) i++;
		else if (second[j] == result[k]) j++;
		else { //result[k] is not equal to both first and second that means, it is not a valid substring return false
			return false;
		}
		k++;
	}

	//agr k l3 tk pahuch gya means sare element of result is in first or second in the same order, return true
	if (k == l3) return true;
	return false;
}


int main() {
	/************************************
	 * NOTE: you cannot submit this question as leetcode me nhi h.
	 * NOTE: wv if required, easy h think, dry run, try yourself
	 * QUESTION: https://www.programiz.com/java-programming/examples/check-valid-shuffle-of-strings
	// VIDEO LINK: https://www.youtube.com/watch?v=qN_vwYtvFUM
	//************************************/
	string first = "XY";
	string second = "12";
	vector<string> results = {"1XY2", "Y1X2", "Y21XX"};

	for (auto str : results) {
		if (checkIsValidShuffle(first, second, str)) {
			cout << "yes" << endl;
		}
		else cout << "no" << endl;
	}

}


