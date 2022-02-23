#include <bits/stdc++.h>
using namespace std;


void printSubsetsRecursive(vector<int> arr, string ans, int idx) {
	if (idx >= arr.size()) {
		cout << ans << endl;
		return;
	}
	printSubsetsRecursive(arr, ans + " " + to_string(arr[idx]), idx + 1);
	printSubsetsRecursive(arr, ans, idx + 1);

}

int main()
{
	int test = 10;
	vector<int> arr = {1, 2, 3};
	printSubsetsRecursive(arr, "" , 0);
}