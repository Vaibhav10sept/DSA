#include <bits/stdc++.h>
using namespace std;

int maxSumNonAdjacentElement(vector<int> arr) {
	//Please watch attached video(link) for more understanding.
	int exclude = 0;
	int include = arr[0];
	// exclude and include works as a DP storage for this question
	// exclude --> means for a particular index not ending at arr[i](exclude), non adjacent subsets till arr[i] ka max sum kitna hoga vo store kroge.
	// include --> means for a particular index must end at arr[i](include), non adjacent subsets till arr[i] ka max sum kitna hoga vo store kroge.
	// exclude/include --> me max sum store hota h
	for (int i = 1; i < arr.size(); i++) {
		int temp = include;
		include = exclude + arr[i];
		exclude = std::max(temp, exclude);
	}

	return std::max(include, exclude);
}

int houseRobber2(vector<int> arr) {
	if (arr.size() == 1) return arr[0];
	vector<int> exceptFirstValue(arr.begin() + 1, arr.end());
	vector<int> exceptLastValue(arr.begin(), arr.end() - 1);

	//removing the first value call
	int withoutFirstAns = maxSumNonAdjacentElement(exceptFirstValue);
	int withoutLastAns = maxSumNonAdjacentElement(exceptLastValue);

	return max(withoutLastAns, withoutFirstAns);
}

int main()
{
	/***************************
	 * STRONG PREREQUISITE: house robber (only a slight change in the code of house robber will give you the solution for this problem)
	PREREQUISITE: maximum sum non adjacent element.
	NOTE: we can use the same code as in max sum non adjacent element.
	video link: https://www.youtube.com/watch?v=3WaxQMELSkw&t=49s
	//********************************
	//********************************
	//STEPS TO SOLVE DP PROBLEMS(TABULATION):
	//1. THINK ABOUT STORAGE AND MEANING
	//2. THINK ABOUT DIRECTION OF THE PROBLEM(FROM SMALLER PROBLEM TO LARGER PROBLEM)
	//3. FINALLY TRAVEL AND SOLVE
	//**********************************************/
	vector<int> cost = {1, 2, 3};
	cout << houseRobber2(cost);
}