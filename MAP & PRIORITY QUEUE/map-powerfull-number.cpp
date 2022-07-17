#include <bits/stdc++.h>
using namespace std;

vector<int> powerfulIntegers(int x, int y, int bound) {
	//WV
	set<int> st;
	for (int i = 1; i < bound; i *= x) {
		//ye loop asese chlega: x^1,x^2,x^3,....
		for (int j = 1; i + j <= bound; j *= y) {
			st.insert(i + j);
			if (y == 1) break; //edge case, taki infinite looping na ho
		}
		if (x == 1) break; //edge case, taki infinite looping na ho
	}
	vector<int> ans(st.begin(), st.end());
	return ans;
}

int main() {
	/*
	PREREQUISITE:
	VIDEO LINK: https://www.youtube.com/watch?v=PniLCiboQ8E&list=PL-Jc9J83PIiEp9DKNiaQyjuDeg3XSoVMR&index=47
	QUESTION LINK: https://leetcode.com/problems/powerful-integers/
	*/
	int x = 2;
	int y = 3;
	int bound = 10;

	vector<int> arr = powerfulIntegers(x, y, bound);
	for (int ele : arr) cout << ele << " ";
}