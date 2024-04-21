#include <bits/stdc++.h>
using namespace std;

int deleteAndEarn(vector<int>& arr) { //wv recommended
	int maxElement = *max_element(arr.begin(), arr.end());
	vector<int> count(maxElement + 1, 0);

	//filling the count array with the count of each element from the arr
	//basically index of count is the number from arr and count[index] contains the count of index(element of arr)
	for (int ele : arr) {
		count[ele]++;
	}

	//using include exclude technique as in house robber
	int exclude = 0;
	int include = 0;
	for (int i = 1; i < count.size(); i++) { //i=0 or i=1 se start krne pe submit hota h, 0 se start kro ya 1 se dono submit ho rhe hai.
		int tempInclude = include;
		include = exclude + (i * count[i]);
		exclude = max(exclude, tempInclude);
	}

	return max(include, exclude);
}

int main()
{
	/***************************
	STRONG PREREQUISITE: dp 1d house robber(somewhat the code flow is same, bss kuch extra cheezo ka dhyaan rkhna pdta hai)
	NOTE: a rec solution is also there.
	NOTE: I write this code after going throught the attached video.
	video link: https://www.youtube.com/watch?v=qVfjmkL1naw&t=658s
	LEETCODE: https://leetcode.com/problems/delete-and-earn/description/
	//********************************
	//********************************
	//STEPS TO SOLVE DP PROBLEMS(TABULATION):
	//1. THINK ABOUT STORAGE AND MEANING
	//2. THINK ABOUT DIRECTION OF THE PROBLEM(FROM SMALLER PROBLEM TO LARGER PROBLEM)
	//3. FINALLY TRAVEL AND SOLVE
	//**********************************************/
	vector<int> arr = {3, 4, 2};
	cout << deleteAndEarn(arr);
}