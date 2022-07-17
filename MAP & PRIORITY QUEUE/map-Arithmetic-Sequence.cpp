#include <bits/stdc++.h>
using namespace std;

bool checkArithmaticProgression(vector<int> arr) {
	int minValue = INT_MAX;
	int maxValue = INT_MIN;
	set<int> st;
	for (int ele : arr) {
		minValue = min(minValue, ele);
		maxValue = max(maxValue, ele);
		st.insert(ele);
	}

	int commonDifference = (maxValue - minValue) / (arr.size() - 1);
	//above is the formula to find the d(common diff) in AP.
	for (int i = 0; i < arr.size(); i++) {
		int nextNumber = minValue + commonDifference * i;
		if (st.find(nextNumber) == st.end()) { //not found
			return false;
		}
	}
	return true;
}

int main() {
	/*
	NOTE: arithmatic sequence: An arithmetic sequence is a sequence where each term increases by adding/subtracting some constant k.
	VIDEO LINK: https://www.youtube.com/watch?v=_cCSWDQg9qc&list=PL-Jc9J83PIiEp9DKNiaQyjuDeg3XSoVMR&index=40
	QUESTION LINK: https://www.pepcoding.com/resources/data-structures-and-algorithms-in-java-levelup/hashmap-and-heaps/check-arithmetic-sequence-official/ojquestion
	*/
	vector<int> arr = {3, 5, 1};
	cout << "res " << checkArithmaticProgression(arr);
}