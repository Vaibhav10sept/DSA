#include <bits/stdc++.h>
using namespace std;

void fun(vector<int> arr)
{
	stack<pair<int, int> > st;
	vector<int> ans;
	int n = arr.size();

	for (auto price : arr) {
		int day = 1;

		while (st.size() > 0 and  st.top().first <= price) {
			day += st.top().second;
			st.pop();
		}
		ans.push_back(day);
		st.push({price, day});

	}
	for (auto i : ans)cout << i << " ";
}
int main() {
	vector<int> arr = {100, 80, 60, 70, 60, 75, 80};


	// output: 1,1,1,2,1,4,6

	// logic: find the index of next smaller element from left
	fun(arr);
}