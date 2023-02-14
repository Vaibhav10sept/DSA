#include <bits/stdc++.h>
using namespace std;

vector<string> printRodCutting(int n) {
	if (n == 0) {
		vector<string> bc;
		bc.push_back("");
		return bc;
	}

	vector<string> curr;
	for (int i = 1; i <= n; i++) {
		vector<string> RecAns = printRodCutting(n - i);
		for (auto str : RecAns) {
			str.append(to_string(i));
			curr.push_back(str);
		}
	}
	return curr;
}

int main()
{
	//***************************
	// video link: https://www.youtube.com/watch?v=eQuJb5gBkkc
	// PEPCODING LINK: https://www.pepcoding.com/resources/data-structures-and-algorithms-in-java-levelup/dynamic-programming/rod-cutting-official/ojquestion
	//**************************************************
	// vector<int> arr = {1, 5, 8, 9, 10, 17, 17, 20};
	int n = 3; //length of rod
	vector<string> res = printRodCutting(n);
	for (auto str : res) cout << str << endl;

}