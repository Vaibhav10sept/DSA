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

	int i = 0;
	int n = arr.size();

	if (n % 2 == 1) { // size is odd
		p.min = arr[0];
		p.max = arr[0];
		i = 1;
		//think, maene kia, CS
	}

	while (i < n - 1) { //second last ele tk jaega
		// i and i+1 ke bich comparison hoga
		if (arr[i] > arr[i + 1]) {
			if (arr[i] > p.max) {
				p.max = arr[i];
			}
			if (arr[i + 1] < p.min) {
				p.min = arr[i + 1];
			}
		}
		else { //arr[i] <= arr[i+1]
			if (arr[i] < p.min) {
				p.min = arr[i];
			}
			if (arr[i + 1] > p.max) {
				p.max = arr[i + 1];
			}
		}
		i += 2;
	}
	return p;
}

int main()
{
	/*
	VIDEO LINK: https://www.youtube.com/watch?v=7CffAoGhKpo
	QUESTION LINK: https://www.geeksforgeeks.org/maximum-and-minimum-in-an-array/
	*/
	vector<int> arr = {1, 5, 2, 3};
	print(arr);
	struct Pair ans = maxMinArray(arr);
	cout << "max " << ans.max << endl;
	cout << "Min " << ans.min << endl;
}