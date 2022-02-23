
#include <bits/stdc++.h>
using namespace std;

int main() {
	int arr[] = {2, 8, 4, 7, 4, 7, 6, 9, 1, 6, 4, 5, 3, 7};
	int sz = sizeof(arr) / sizeof(int);
	vector<int> ans;
	int k = 3;
	deque<int> q;
	int j = 0;
	int i = 0;
	while (j < sz) {


		while (	q.size() > 0 and arr[j] > q.back())q.pop_back();



		q.push_back(arr[j]);
		if (j - i + 1 == k) {

			// cout << "assn " << q.front() << endl;
			ans.push_back(q.front());
			if (arr[i] == q.front()) {
				q.pop_front();
			}
			i++;
		}
		j++;
	}

	for (int i : ans)cout << i << " ";
}