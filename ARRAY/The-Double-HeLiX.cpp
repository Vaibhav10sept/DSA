#include <bits/stdc++.h>
using namespace std;

int doubleHelix(vector<int> a, vector<int> b) {
	// NOTE: nice question think, cs, dry run, wv
	// NOTE: arr1 and arr2 are sorted in increasing order
	int i = 0;
	int j = 0;
	int sum1 = 0;
	int sum2 = 0;
	int ans = 0;
	while (i < a.size() and j < b.size()) {
		if (a[i] < b[j]) {
			sum1 += a[i];
			i++;
		}
		else if (b[j] < a[i]) {
			sum2 += b[j];
			j++;
		}
		else { //a[i] == b[j]
			ans = ans + max(sum1, sum2) + a[i];
			sum1 = 0;
			sum2 = 0;
			i++;
			j++;
		}
	}

	//for the remainging elements in a and b
	//only one while will execute, think, cs
	while (i < a.size()) {
		sum1 += a[i];
		i++;
	}
	while (j < b.size()) {
		sum2 += b[j];
		j++;
	}

	ans = ans + max(sum1, sum2);
	return ans;
}



int main()
{
	/*
	NOTE: nice question think, cs, dry run, wv
	PREQ: code pattern is similar to merge two sorted array.
	NOTE: arr1 and arr2 are sorted in increasing order
	VIDEO: https://www.youtube.com/watch?v=w-6YHcGmSxM
	QUESTION: https://www.spoj.com/problems/ANARC05B/
	*/
	vector<int> arr1 = {3, 5, 7, 9, 20, 25, 30, 40, 55, 56, 57, 60, 62};
	vector<int> arr2 = {1 , 4 , 7 , 11, 14, 25 , 44, 47, 55, 57, 100};
	cout << "ans " << doubleHelix(arr1, arr2);
}