#include <bits/stdc++.h>
using namespace std;

void fun(string arr, int k) {
	//sliding window
	int n = arr.size();
	map<char, int> mp;
	int j = 0, i = 0, ans = INT_MIN;
	int start, end;
	while (j < n) {
		mp[arr[j]]++;
		if (mp.size() == k) {
			ans = max(ans, j - i + 1);
			start = i;
			end = j;
		}
		if (mp.size() > k ) {
			while (mp.size() > k ) {
				mp[arr[i]]--;
				if (mp[arr[i]] == 0)  mp.erase(arr[i]);
				i++;
			}
		}

		j++;
	}
	cout << ans << endl;
	cout << arr.substr(start, end);
}

int main() {
	string s = "abababacbgcbcbababa";
	int k = 4;

	fun(s, k);
}