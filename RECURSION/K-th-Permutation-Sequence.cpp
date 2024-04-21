#include <bits/stdc++.h>
using namespace std;

string KPermutationSequence(int n, int k) {
	//create an array of n size with element from 1 to n
	vector<int> arr;
	for (int i = 1; i <= n; i++) arr.push_back(i);


	//precomputation: create an array which stores the factorial of 0 to 9;
	vector<int> factorialArray(10);
	factorialArray[0] = 1;
	factorialArray[1] = 1;

	for (int i = 2; i <= 9; i++) {
		factorialArray[i] = factorialArray[i - 1] * i;
	}
	// for (auto ele : arr) cout << ele << " ";

	//wv recommended
	string ans = "";
	int i = 1; //I have this not in video
	k = k - 1;//bcoz of 0 based indexing, rem don't forget this step(wv)

	while (true) {
		int blockSize = factorialArray[n - i];

		int index = k / blockSize;
		cout << "blockSize " << blockSize << endl;
		ans += to_string(arr[index]);
		//remove arr[index] from the arr
		arr.erase(arr.begin() + index);
		//SYNTAX FOR ERASE(VECTOR):
		// vector_name.erase(position);    for deletion at specific position
		// vector_name.erase(starting_position, ending_position);    // for deletion in range

		if (arr.size() == 0) { //means sare numbers ans me insert ho gae h, isliye arr khali ho gya
			break;
		}
		k = k % blockSize;
		blockSize = blockSize / arr.size();
		i++;
	}

	return ans;
}

int main()
{
	/*
	NOTE: I have added few things that are not in video, think, cs
	VIDEO: https://www.youtube.com/watch?v=wT7gcXLYoao
	LEETCODE: https://leetcode.com/problems/permutation-sequence/description/
	*/
	int n = 3;
	int k = 3;
	// cout << getPermutation(n, k);
	cout << KPermutationSequence(n, k);
}