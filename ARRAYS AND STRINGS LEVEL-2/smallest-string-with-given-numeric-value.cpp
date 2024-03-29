#include <bits/stdc++.h>
using namespace std;

string smallestStringGivenNumericValue(int n, int k) {
	vector<char> arr(n);
	//sabme 'a' bhar do
	for (int i = 0; i < arr.size(); i++) {
		arr[i] = 'a';
		k--;
	}
	int idx = arr.size() - 1;
	//last se chlte hue, k>=26 ke lie 'z' fill krdo
	while (k >= 26) {
		arr[idx] = 'z';
		k = k + 1 - 26; //"+1" coz hm 'a' ki jgh 'z' bhar rhe toh 'a' ka '+1' hoga jo 'a' ko bharte samay hmne minus kia tha
		idx--;
	}
	//now k is less than 26, toh koi ek alphabet isko fullfill kr skta hai.
	arr[idx] = (char)k + 'a';

	//array ko string bnake return krdo
	string ans = "";
	for (auto ele : arr) {
		ans.push_back(ele);
	}
	return ans;
}

int main() {
	//*********************************
	// VIDEO LINK:
	// QUESTION: https://leetcode.com/problems/smallest-string-with-a-given-numeric-value/
	// The numeric value of a lowercase character is defined as its position (1-indexed) in the alphabet, so the numeric value of a is 1, the numeric value of b is 2, the numeric value of c is 3, and so on.

	// The numeric value of a string consisting of lowercase characters is defined as the sum of its characters' numeric values. For example, the numeric value of the string "abe" is equal to 1 + 2 + 5 = 8.

	// You are given two integers n and k. Return the lexicographically smallest string with length equal to n and numeric value equal to k.

	// Note that a string x is lexicographically smaller than string y if x comes before y in dictionary order, that is, either x is a prefix of y, or if i is the first position such that x[i] != y[i], then x[i] comes before y[i] in alphabetic order.
	//*********************************
	int n = 3;
	int k = 27;
	cout << smallestStringGivenNumericValue(n, k);

}