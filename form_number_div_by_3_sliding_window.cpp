#include <bits/stdc++.h>
using namespace std;
void fun(int arr[], int n , int k) {
	string sum = "";
	string ans;
	int i = 0, j = 0;
	while (j < n) {
		sum += to_string(arr[j++]);
		// cout << sum << endl;
		while (j - i  > k) {
			int sz = to_string(arr[i++]).size();
			while (sz--) sum.erase(0, 1);
		}
		if (j - i  == k) {
			int sm = 0;
			for (auto ch : sum) {
				int dig = ch - '0';
				sm += dig;
			}
			if (sm % 3 == 0) ans = sum;
		}
	}

	cout << ans;
}

int main() {
	// int arr[] = {2, 3, 1, 2, 4, 3};
	int arr[] = {84, 23, 45, 12, 56, 82};

	int x = 3;
	fun(arr, 6, x);
}