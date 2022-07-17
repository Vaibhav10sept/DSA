#include <bits/stdc++.h>
using namespace std;

bool PairswithEqualSum(vector<int> arr) {
	set<int> st;

	for (int i = 0; i < arr.size(); i++) {
		for (int j = i + 1; j < arr.size(); j++) {
			int sum = arr[i] + arr[j];
			if (st.find(sum) != st.end()) { //found
				return true;
			}
			else st.insert(sum);
		}
	}
	return false;
}

int main() {
	/*
	PREREQUISITE:
	VIDEO LINK: https://www.youtube.com/watch?v=11U8TjquNjY&list=PL-Jc9J83PIiEp9DKNiaQyjuDeg3XSoVMR&index=36
	QUESTION:
	*/
	vector<int> arr = {0, 1, 0, 2, 0, 1, 0};
	cout << "ans " << PairswithEqualSum(arr);
}