#include<bits/stdc++.h>
using namespace std;

vector<int> Maximumofallsubarraysofsizek(vector<int> arr, int k) {
	int i = 0;
	int j = 0;
	vector<int> ans;
	// i --> represent start of window
	// j --> represent end of window
	// j-i+1 --> is the size of window

	priority_queue<int> pq; //max heap(default in cpp)
	while (j < arr.size()) {
		pq.push(arr[j]);
		if (j - i + 1 == k) {
			if (!pq.empty()) {
				ans.push_back(pq.top());
			}

			//now,slide the window.
			if (pq.top() == arr[i]) {
				pq.pop();
			}
			i++;
		}
		j++;
	}
	return ans;
}

int main() {
	/*
	NOTE: here we use priority queue
	VIDEO LINK: https://www.youtube.com/watch?v=xFJXtB5vSmM&list=PL_z_8CaSLPWeM8BDJmIYDaoQ5zuwyxnfj&index=6
	*/
	vector<int> arr = {8, 5, 10, 7, 9, 4, 15, 12, 90, 13};
	int k = 4;
	vector<int> ans = Maximumofallsubarraysofsizek(arr, k);
	for (auto ele : ans)cout << ele << " ";
}