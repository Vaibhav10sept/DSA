#include<bits/stdc++.h>
using namespace std;

int celebrityProblem(vector<vector<int>> arr) {
	stack<int> st;
	for (int i = 0; i < arr.size(); i++) {
		st.push(i);
	}

	while (st.size() >= 2) {
		// do pop krege
		int i = st.top();
		st.pop();
		int j = st.top();
		st.pop();

		if (arr[i][j] == 1) {
			//if i knows j
			//then i can never be the celebrity, so don't put i back into the stack
			st.push(j);
		}
		else {
			//if i doesn't know j that means j can never be the celebrity, so don't push j in the stack
			st.push(i);
		}
	}

	//now while ke bad hmare paas ek hi element rh jaega stack me
	//which will be the potential element to be the celebrity(WV)

	int potentialCelebrity = st.top();
	//now, we are checking that the potentialCelebrity can be the celebrity or not
	for (int i = 0; i < arr.size(); i++) {
		if (i != potentialCelebrity) {
			if (arr[i][potentialCelebrity] == 0 or arr[potentialCelebrity][i] == 1) {
				//think CS WV
				cout << "no celebrity found" << endl;
				return -1;
			}
		}
	}
	return potentialCelebrity;
}
int main() {
	/*
	VIDEO LINK: https://www.youtube.com/watch?v=CiiXBvrX-5A
	LEETCODE LINK: https://practice.geeksforgeeks.org/problems/the-celebrity-problem/1
	*/
	vector<vector<int>> arr = {
		{0, 1, 0},
		{0, 0, 0},
		{0, 1, 0}
	};
	cout << celebrityProblem(arr);
}