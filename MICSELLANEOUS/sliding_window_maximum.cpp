#include <bits/stdc++.h>
using namespace std;

vector<int> slidingWindowMax(vector<int> arr, int k) {
	vector<int> ans;
	deque<int> q; //will hold the maximum elements.
	int j = 0;
	int i = 0;
	while (j < arr.size()) {

		while (q.size() > 0 and arr[j] > q.back())q.pop_back(); //sare chote "q" ke back se hta do

		q.push_back(arr[j]); //sare chote htane ke baad jo bda hai use push back krdo
		if (j - i + 1 == k) { //window's size hit.
			ans.push_back(q.front());
			if (arr[i] == q.front()) {
				q.pop_front();
			}
			i++;
		}
		j++;
	}
	return ans;
}

int main() {
	vector<int> arr = {1, 3, -1, -3, 5, 3, 6, 7};
	int k = 3;
	vector<int> ans = slidingWindowMax(arr, k);
	for (int i : ans)cout << i << " ";
}