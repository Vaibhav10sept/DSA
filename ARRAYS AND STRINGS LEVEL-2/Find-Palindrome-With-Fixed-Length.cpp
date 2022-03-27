#include <bits/stdc++.h>
using namespace std;

int FindPalindromeWithFixedLength(vector<int> queries, int intLength) {
	int countOfNumberDeleted  = 0;
	for (int i = 0; i < arr.size() - 1; i++) {
		if ((i - countOfNumberDeleted) % 2 == 0 and arr[i] == arr[i + 1]) {
			countOfNumberDeleted++;
		}
	}
	//check for array size after deletion, it should be even as per question
	if ((arr.size() - countOfNumberDeleted) % 2 != 0) { //if its odd
		countOfNumberDeleted++;
	}
	return countOfNumberDeleted;
}


int main() {
	//*********************************
	// VIDEO LINK:
	// LINK: https://leetcode.com/contest/weekly-contest-286/problems/find-palindrome-with-fixed-length/
	//*********************************
	vector<int> queries = {1, 2, 3, 4, 5, 90};
	int intLength = 3;
	cout << FindPalindromeWithFixedLength(queries, intLength);
}