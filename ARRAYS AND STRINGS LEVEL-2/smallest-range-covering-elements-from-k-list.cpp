#include <bits/stdc++.h>
using namespace std;

class Util {
public:
	int minRange;
	int vectorIdx;
	int idx;
	Util(int minRange, int vectorIdx, int idx): minRange(minRange), vectorIdx(vectorIdx), idx(idx)
	{

	}
};

// struct CompareAge {
// 	bool operator()(Util const & p1, Util const & p2) {
// 		// return "true" if "p1" is ordered before "p2", for example:
// 		return p1.minRange > p2.minRange;
// 	}
// };

// operator overloading for priority queue
// this is minimum priority queue(min heap)
bool operator< (const Util &first, const Util &second) {
	return first.minRange > second.minRange;
}

vector<int> smallestRangeInKLists(vector<vector<int>> arr) {
	vector<int> ans = { -100000, 100000};
	int k = arr.size();
	int maxRange = INT_MIN;
	// priority_queue<Util, vector<Util>, CompareAge> pq;
	priority_queue<Util> pq; //this is min heap
	//insert an object for every vector in array of vector
	for (int i = 0; i < k; i++) {
		pq.push(Util(arr[i][0], i, 0));
		maxRange = max(maxRange, arr[i][0]);
	}

	while (true) {
		Util util = pq.top();
		pq.pop();
		//updating the range if found a smaller one.
		if (ans[1] - ans[0] > maxRange - util.minRange) {
			ans[0] = util.minRange;
			ans[1] = maxRange;
		}
		util.idx++;
		//check is idx is out of range for that vector, if yes then break(think)
		vector<int> curr = arr[util.vectorIdx];
		if (util.idx == curr.size()) {
			break;
		}
		// adding the updated min in util using util.idx.
		util.minRange = curr[util.idx];
		//updating the maxRange
		maxRange = max(maxRange, curr[util.idx]);
		pq.push(util);
	}
	return ans;
}

int main() {
	//*********************************
	// VIDEO LINK: https://www.youtube.com/watch?v=aH-2Sig2H2Q&list=PL-Jc9J83PIiE-TR27GB7V5TBLQRT5RnSl&index=36
	// QUESTION:
	// You have k lists of sorted integers in non-decreasing order.
	// Find the smallest range that includes at least one number from each of the
	// k lists.
	// We define the range [a, b] is smaller than range [c, d] if b - a < d - c or a < c if b - a == d - c.
	//*********************************
	vector<vector<int>> arr = {{4, 10, 15, 24, 26}, {0, 9, 12, 20}, {5, 18, 22, 30}};
	vector<int> ans = smallestRangeInKLists(arr);
	for (auto ele : ans) cout << ele << " ";
}