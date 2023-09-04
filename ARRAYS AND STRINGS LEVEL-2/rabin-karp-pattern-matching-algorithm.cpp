#include <bits/stdc++.h>
using namespace std;

//********************************
//CODE NOT WORKING
//***********************************

vector<int> patternMatchingAlgorithm(string txt, string pat) {
	int n = 1e5 + 3;
	int m = 1e9 + 7;
	int d = 31; //jisse multiple krege could be any number 26 liya kyo 26 alphabet hote h

	vector<long long> powers(n);
	powers[0] = 1;  //something to the power 0, 1 hota h
	for (int i = 1; i < n; i++) {
		powers[i] = (powers[i - 1] * d) % m;
	}
	//above is precomputation

	vector<int> ans;
	long long hpat = 0; //hash pattern
	long long htxt = 0; //hash text
	for (int i = 0; i < pat.size(); i++)
	{
		// hpat *= d;
		hpat = (hpat + (pat[i] - 'A' + 1) * powers[i % pat.size()]) % m;
		cout << "hpat " << hpat << endl;
	}

	//sliding window kinda pattern below
	int i = 0, j = 0;
	while (j < txt.size()) {
		// htxt *= d;
		htxt = (htxt + (txt[j] - 'A' + 1) * powers[j % pat.size()]) % m;


		if (j - i + 1 == pat.size()) {
			cout << "i " << i << " " << j << " " << htxt << " " << hpat << endl;
			if (htxt == hpat) {
				ans.push_back(i);
			}

			//shifting window, to ith char remove krre from htxt below:
			// htxt = htxt - ((txt[i] - 'A' + 1) * pow(d, j - i));
			int valueOfIthChar = (txt[i] - 'A' + 1) * powers[i % pat.size()];
			cout << "value ith " << valueOfIthChar << endl;
			htxt = (htxt - valueOfIthChar) % m;
			cout << "after htxt " << htxt << endl;
			i++;
		}
		j++;
	}
	return ans;
}

int main()
{
	//********************************
	//CODE NOT WORKING
	//***********************************
	string txt = "CODENCODE", pat = "CODE";
	vector<int> ans = patternMatchingAlgorithm(txt, pat);
	for (auto ele : ans) cout << ele << ", ";
	cout << endl;
}