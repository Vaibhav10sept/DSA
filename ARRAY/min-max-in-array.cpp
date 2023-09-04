#include <bits/stdc++.h>
using namespace std;

void print(vector<int> arr) {
	for (auto ele : arr) cout << ele << " ";
	cout << endl;
}

struct Pair {
	int min;
	int max;
};


struct Pair maxMinArray(vector<int> arr) {
	struct Pair p;
	p.min = INT_MAX;
	p.max = INT_MIN;

	for (auto ele : arr) {
		if (ele > p.max) p.max = ele;
		if (ele < p.min) p.min = ele;
	}
	return p;
}

int main()
{
	/*
	VIDEO LINK: https://www.youtube.com/watch?v=7CffAoGhKpo
	QUESTION LINK: https://www.geeksforgeeks.org/maximum-and-minimum-in-an-array/
	*/
	vector<int> arr = {1, 5};
	print(arr);
	struct Pair ans = maxMinArray(arr);
	cout << "max " << ans.max << endl;
	cout << "Min " << ans.min << endl;
}