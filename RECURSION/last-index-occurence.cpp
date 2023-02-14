#include <bits/stdc++.h>
using namespace std;

int lastIndex(vector<int> arr, int i, int data) {
	if (i == arr.size()) return -1;

	int res = lastIndex(arr, i + 1, data);
	if (res != -1) return res; //post recusion order --> means last index mil chuka h, to jo mila h use hi return krdo
	else {
		if (data == arr[i]) return i; //means, abhi tk last index nhi mila h, toh yhi last index hoga, return krdo
	}
	return -1;
}



int main()
{
	vector<int> arr = {100, 20, 3, 4, 3, 6, 8, 3, 8, 500, 8};
	cout << lastIndex(arr, 0, 8) << endl;
}