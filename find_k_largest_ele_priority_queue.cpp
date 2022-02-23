#include<bits/stdc++.h>
using namespace std;


int main() {
	int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	int n = 9;
	int k = 3;
	priority_queue<int, vector<int> , greater<int> > q;
	for (auto i : arr) {
		q.push(i);
		if (q.size() > k) q.pop();
	}
	while (q.size() > 0 ) {

		cout << q.top() << endl;
		q.pop();
	}
}