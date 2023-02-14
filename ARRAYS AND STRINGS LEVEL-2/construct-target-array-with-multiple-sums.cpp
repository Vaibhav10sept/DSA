// SKIPPED AS HARD
#include<bits/stdc++.h>
using namespace std;

bool constructTargetArrayWithMultipleSums(vector<int> arr) {
	//leetcode hard question
	//watch video recommended
	//NOTE: we are moving backwards(watch video)
	long sum = 0;
	priority_queue<long> pq; //max heap(default max heap hoti h in cpp)

	for (long ele : arr) {
		pq.push(ele); //add all ele in pq.
		sum += ele;
	}

	while (pq.top() != 1) {
		long maxValue = pq.top();
		pq.pop();
		int remainingSum = sum - maxValue;

		//think, WV
		if (remainingSum <= 0 or remainingSum >= maxValue) return false;

		int newValue = maxValue % remainingSum;
		sum = remainingSum + newValue; //this is new sum(or previous sum)
		pq.push(newValue > 0 ? newValue : sum);
	}

	return true;
}

int main() {
	//*********************************
	// VIDEO LINK: https://www.youtube.com/watch?v=wVBMvVc5Na4&list=PL-Jc9J83PIiE-TR27GB7V5TBLQRT5RnSl&index=54
	// QUESTION: https://leetcode.com/problems/construct-target-array-with-multiple-sums/
	//*********************************
	vector<int> arr {1, 1, 10};
	bool ans = constructTargetArrayWithMultipleSums(arr);
	if (ans) cout << "true";
	else cout << "false";
}