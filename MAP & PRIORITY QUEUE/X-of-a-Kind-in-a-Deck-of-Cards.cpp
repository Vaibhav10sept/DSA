#include <bits/stdc++.h>
using namespace std;

int getGcdRecursive(int a, int b) {
	if (a == 0) return b;
	else if (b == 0) return a;

	getGcdRecursive(b, a % b);
}

bool XOfaKindInaDeckofCards(vector<int> arr) {
	//WV
	map<int, int> mp; //int vs freq

	//creating the freq map
	for (int ele : arr) {
		mp[ele]++;
	}

	int gcd = 0;

	for (auto it : mp) {
		//here, we are finding the gcd/hcf of all the frequencies in the map
		gcd = getGcdRecursive(gcd, it.second);
	}

	if (gcd > 1) {
		//agr gcd 1 nhi h to true, we don't want gcd as 1(THINK, WV)
		return true;
	}
	else {//gcd 1 aae h to false hoga.
		return false;
	}
}

int main() {
	/*
	NOTE: HCF/GCD nikalna hai isme(read question and think)
	PREREQUISITE: gcd-recursive.
	VIDEO LINK: https://www.youtube.com/watch?v=UvpXInRkZ3Q&list=PL-Jc9J83PIiEp9DKNiaQyjuDeg3XSoVMR&index=50
	QUESTION LINK: https://leetcode.com/problems/powerful-integers/
	*/
	vector<int> deck = {1, 2, 3, 4, 4, 3, 2, 1};
	cout << XOfaKindInaDeckofCards(deck);
}