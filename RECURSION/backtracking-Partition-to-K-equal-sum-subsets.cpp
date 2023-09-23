#include <bits/stdc++.h>
using namespace std;

bool rec(int ind, int numOfSubsets, int currSum, int targetSum,  vector<bool> &alreadyPickedUp, vector<int> &arr) {
	if (numOfSubsets == 0) {
		//sare subset(k) bna liye h return true(yhi to krna tha na hme)
		return true;
	}
	if (currSum == targetSum) { //ek subset aesa mil gya jiska sum target sum ke equal h
		//to ab hm or subsets ki search krege jiska sum target sum ke equal h uske liye ek new call hoge rec ko with everything reset to the original call(think, cs, wv)
		return rec(0, numOfSubsets - 1, 0, targetSum, alreadyPickedUp, arr);
	}
	if (currSum > targetSum) return false;
	if (ind >= arr.size()) return false;
	//BC ends

	if (alreadyPickedUp[ind]) { //already used ho chuka h kisi or subset ko bnane me to, age badh jao next index me jao
		return rec(ind + 1, numOfSubsets, currSum , targetSum, alreadyPickedUp, arr);
	}
	else { //this ind is not used before in any other subsets
		//now, remember, to mark it as visited(alreadypicked)
		alreadyPickedUp[ind] = true;
		//pattern is same as we make subset (pick and not pick way)

		//pick recursive call
		bool pick = rec(ind + 1, numOfSubsets, currSum + arr[ind], targetSum, alreadyPickedUp, arr);

		//backtracking(mark ind as not picked up)
		alreadyPickedUp[ind] = false;

		//not pick recursive call
		bool notPick = rec(ind + 1, numOfSubsets, currSum, targetSum, alreadyPickedUp, arr);

		//hm or operator se return krege, means agr pick ya notpick kisi se bhi true aya to true return hoga, agr dono se false aya to false return hoga(cs, think)
		return pick or notPick;
	}
}

bool partitionKEqualSumSubsets(vector<int> arr, int k) {
	vector<bool> alreadyPickedUp(arr.size(), false);
	int sum = 0;
	for (auto ele : arr) {
		sum += ele;
	}
	//logic: agr sum of all element in arr is not divisble by k that means return false(think, cs)
	//logic: jo sum hme find krna h vo to all element ke sum ko k se divide krke milega or agr k se fully divide na ho to return false krdo(cs, wv)

	if (sum % k != 0) return false; //edge case
	sum = sum / k;
	return rec(0, k, 0, sum, alreadyPickedUp, arr);
}


int main()
{
	/*
	NOTE: gives TLE, no other solution that can submit is there.
	NOTE: not that intuitive solution(wv recommended)
	VIDEO: https://www.youtube.com/watch?v=h_6MldQ8vB8
	VIDEO: https://www.youtube.com/watch?v=mBk4I0X46oI
	LEETCODE: https://leetcode.com/problems/partition-to-k-equal-sum-subsets/description/
	*/
	vector<int> arr = {10, 6, 9, 5, 8, 7, 10, 4, 3, 7, 7, 7, 2, 1, 6, 6};
	int k = 7;
	if (partitionKEqualSumSubsets(arr, k)) {
		cout << "true" << endl;
	}
	else cout << "false" << endl;
}