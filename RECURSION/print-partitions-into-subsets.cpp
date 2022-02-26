#include <bits/stdc++.h>
using namespace std;

int partitionIntoSubsetsDP(int n, int k) {
	//please refer to the video link below for better understanding.
	if (n < k) {
		cout << "teams formation is not possible" << endl;
		return -1;
	}
	//row(i) -> represent k(no of teams)
	//colums(j) -> represent n(no of people)
	//cell -> represent the no of ways to form a k teams using n people
	vector<vector<int>> dp(k + 1, vector<int>(n + 1));
	//base cases(think)
	//1. if n=0 or k=0 -> 0 ways
	//2. if k=1 -> 1 way -> ek team bnani hai, sbko ek team me daal do
	//3. if n<k -> 0 way -> team making not possible
	//4. if n=k -> 1 way -> sabko alag alag teams bna do
	//FORMULA: f(n,k) = k*f(n-1,k) + f(n-1,k-1)

	for (int i = 0; i < dp.size(); i++) {
		for (int j = 0; j < dp[0].size(); j++) {
			//initialization or base cases starts
			if (i == 0 || j == 0) { //1st point
				dp[i][j] = 0;
			}
			else if (i == 1) { //2nd point
				dp[i][j] = 1;
			}
			else if (j < i) { // 3rd point
				dp[i][j] = 0;
			}
			else if (i == j) { // 4th point
				dp[i][j] = 1;
			}
			else {// for every other cell
				dp[i][j] = i * dp[i][j - 1] + dp[i - 1][j - 1];
			}
		}
	}
	return dp[k][n];
}

vector<vector<string>> printPartitionsIntoSubsetsRecursion(string n, int k) {
	if (n.size() < k) { //3. if n<k -> 0 way -> team making not possible
		vector<vector<string>> bc;
		return bc;
	}
	if (n.size() == 0 and k == 0) { //1. if n=0 or k=0 -> 0 ways
		vector<vector<string>> bc;
		return bc;
	}
	if (n.size() == k) { //4. if n=k -> 1 way -> sabko alag alag teams bna do
		vector<vector<string>> bc;
		vector<string> temp;
		for (char ch : n) {
			string s(1, ch);
			temp.push_back(s);
		}
		bc.push_back(temp);
		return bc;
	}
	if (k == 1) { //2. if k=1 -> 1 way -> ek team bnani hai, sbko ek team me daal do
		vector<vector<string>> bc;
		vector<string> temp;
		temp.push_back(n);
		bc.push_back(temp);
		return bc;
	}
	//bc ends

	vector<vector<string>> currAns;

	char ch = n[0];
	string removedFirst = n.substr(1);
	vector<vector<string>> ansk1 = printPartitionsIntoSubsetsRecursion(removedFirst, k - 1);
	vector<vector<string>> ansk = printPartitionsIntoSubsetsRecursion(removedFirst, k);

	for (vector<string> strvec : ansk1) {
		string s(1, ch);
		strvec.push_back(s);
		currAns.push_back(strvec);
	}

	for (vector<string> strvec : ansk) {
		vector<string> temp = strvec;
		int i = 0;
		while (i < temp.size()) {
			vector<string> curr = temp;
			string s(1, ch);
			curr[i] = s + temp[i];
			i++;
			currAns.push_back(curr);
		}
	}
	return currAns;
}


int main()
{
	//***************************
	// video link: https://www.youtube.com/watch?v=IiAsqfjhZnY&list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk&index=515
	// NOTE: this question is similar to "friends-pairing" problem but
	// the approach used to solve it is similar to knapsack problem.
	// NOTE: there is also a DP ques "partitionIntoSubsetsDP" similar to this one
	//**************************************************
	string n = "12345"; //no of people for recursive code
	int count = 5; //no of people
	int k = 4; //no of teams
	cout << "no of ways in which " << k << " teams can be formed using " << count << " people: " << partitionIntoSubsetsDP(count, k);
	cout << endl;
	vector<vector<string>> ans = printPartitionsIntoSubsetsRecursion(n, k);
	cout << "Teams are:" << endl;
	for (vector<string> ele : ans) {
		for (string inner : ele) {
			cout << inner << " ";
		}
		cout << endl;
	}
}