#include <bits/stdc++.h>
using namespace std;

void printSubsets(vector<int> arr) {
	int limit = pow(2, arr.size()); // no. of subset = 2 raise to the power arr.size()
	for (int i = 0; i < limit; i++) {
		string set = "";
		int temp = i;

		for (int j = arr.size() - 1; j >= 0; j--) { // loop ulta chl rah logic
			// convert i to binary and use 0 and 1 to determine your subset(logic)
			int r = temp % 2;
			temp /= 2;
			if (r == 0) {
				set = "_ " + set;
			}
			else { // r == 1
				set = to_string(arr[j]) + " " + set;
			}
		}
		cout << set << endl;
	}
}

int main()
{
	//NOTE: count of all subarray --> n(n+1)/2
	//NOTE: count of all subsets --> 2^n
	vector<int> arr = {1, 2, 3};
	printSubsets(arr);
}