#include <bits/stdc++.h>
using namespace std;

bool compareInterval(int a, int b)
{
	return abs(a) < abs(b);
}

bool doublePairArray(vector<int> arr) {
	//WV recommended
	if (arr.size() == 0) return true;

	map<int, int> freqMap; //int,freq
	for (int ele : arr) freqMap[ele]++;

	sort(arr.begin(), arr.end(), compareInterval);

	for (int ele : arr) {
		if (freqMap[ele] == 0) continue; //means kisi or value ke lie ye as a double use ho gya h


		if (freqMap.find(2 * ele) == freqMap.end()) { //not found
			//means double value doesn't exist
			return false;
		}

		if (freqMap.find(2 * ele) != freqMap.end() and freqMap[2 * ele] == 0) { //found
			//means double value exits but its freq is 0
			return false;
		}

		//decrease freq of both.
		freqMap[ele]--;
		freqMap[2 * ele]--;
	}
	return true;
}

int main() {
	/*
	VIDEO LINK: https://www.youtube.com/watch?v=ZOITpH3RDAk&list=PL-Jc9J83PIiEp9DKNiaQyjuDeg3XSoVMR&index=39
	QUESTION LINK: https://leetcode.com/problems/array-of-doubled-pairs/
	*/
	vector<int> arr = {2, 1, 2, 6};
	cout << "res " << doublePairArray (arr);
}