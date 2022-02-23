#include <bits/stdc++.h>
using namespace std;

void printFibonacci(int n) {
	vector<int> arr(n + 1);
	arr[0] = 0;
	arr[1] = 1;
	for (int i = 2; i < arr.size(); i++) {
		arr[i] = arr[i - 1] + arr[i - 2];
	}

	for (auto ele : arr) cout << ele << " ";
}

int main()
{
	printFibonacci(10);
}