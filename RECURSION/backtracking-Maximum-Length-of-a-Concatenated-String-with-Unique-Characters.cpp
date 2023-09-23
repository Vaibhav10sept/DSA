#include <bits/stdc++.h>
using namespace std;

bool alreadyPickedOrContainsDuplicate(string str, vector<bool> &visited) {
	//self check for duplicates chars
	vector<bool> selfCheck(26, false);
	for (char ch : str) {
		int idx = ch - 'a';
		if (selfCheck[idx]) return true;
		else selfCheck[idx] = true;

		//check in the visited array if any of the char is used before or not
		if (visited[idx]) return true;
	}

	return false;
}

void rec(int ind, int currLength, vector<bool> &visited, vector<string> &arr, int &maxLength) {
	if (ind == arr.size()) { //time to update the maxlengh
		maxLength = max(maxLength, currLength);
		return;
	}
	if (ind > arr.size()) return;
	//BC ends

	//check if arr[ind] characters are already taken or arr[ind] contains repeating chars.
	if (alreadyPickedOrContainsDuplicate(arr[ind], visited)) {
		rec(ind + 1, currLength, visited, arr, maxLength); // move to next index
		return;
	}

	//now, we can use arr[ind]
	//mark all the chars of arr[ind] to visited
	for (char ch : arr[ind]) {
		visited[ch - 'a'] = true;
	}
	//again same algo to generate subset(pick and not pick)

	//pick
	rec(ind + 1, currLength + arr[ind].size(), visited, arr, maxLength);

	//backtrack: unmark all the chars of arr[ind] to unvisited
	for (char ch : arr[ind]) {
		visited[ch - 'a'] = false;
	}

	//not pick
	rec(ind + 1, currLength, visited, arr, maxLength);
	return;
}

int maxLengthConcatenatedString(vector<string> arr) {
	vector<bool> visited(26, false);
	int maxLength = INT_MIN;
	rec(0, 0, visited, arr, maxLength);
	return maxLength;
}

int main()
{
	/*
	PREQ: get subsequence or subset(kinda hint mil skti h approach ke liye)
	NOTE: wv recommended
	VIDEO: https://www.youtube.com/watch?v=DIJQ8zLeVEk
	LEETCODE: https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/description/

	//NOTE: SUBSEQUENCE AND SUBSET BOTH ARE SAME THING
	//NOTE: SO TOTAL THERE ARE: 2^N SUBSEQUENCES/SUBSETS

	//NOTE: SUBSTRING AND SUBARRAY ARE ALMOST SAME THINGS(DOUBTFULL HAI)
	//NOTE: TOTAL THERE ARE N*(N+1)/2 SUBSTRING/SUBARRAY

	//DIFFERENCE BETWEEN SUBARRAY AND SUBSEQUENCE: SUBARRAY ARE
	//CONTINUES MEANS YOU CANNOT LEAVE ANY ELEMENT IN BETWEEN
	//WHILE SUBSEQUENCE ARE DISCONTINUOUS BUT THE SEQUENCE IS PRESERVED.
	*/
	// vector<string> arr = {"cha", "r", "act", "ers"};
	vector<string> arr = {"abcdefghijklmnopqrstuvwxyz"};
	cout << maxLengthConcatenatedString(arr);
}