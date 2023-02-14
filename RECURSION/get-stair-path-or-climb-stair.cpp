#include <bits/stdc++.h>
using namespace std;

vector<string> getStairPath(int n) {
	if (n == 0) {
		vector<string> baseResult;
		baseResult.push_back("");
		return baseResult;
	}
	if (n < 0) {
		vector<string> baseResult;
		return baseResult;
	}

	vector<string> n1 = getStairPath(n - 1);
	vector<string> n2 = getStairPath(n - 2);
	vector<string> n3 = getStairPath(n - 3);


	vector<string> myResult;
	for (string val : n1) {
		myResult.push_back("1" + val);
	}
	for (string val : n2) {
		myResult.push_back("2" + val);
	}
	for (string val : n3) {
		myResult.push_back("3" + val);
	}
	return myResult;
}



int main()
{
	//********************************
	// QUESTION VIDEO LINK: https://www.youtube.com/watch?v=hMJAlbJIS7E&list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk&index=399
	//***********************************
	vector<string> ans;
	ans = getStairPath(5);
	for (auto val : ans) cout << val << endl;
}