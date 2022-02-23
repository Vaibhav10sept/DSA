#include <bits/stdc++.h>
using namespace std;

void fun(string s) {
	//sliding window
	map<char, int> mp;
	int j = 0;
	int i = 0;
	int n = s.length();
	int ans = INT_MIN;
	while (j < n) {
		mp[s[j]]++;
		if (mp.size() == j - i + 1) {
			//window ka size == mp.size() means unique
			// characters hai with no repetitions.

			ans = max(ans, j - i + 1);
		}
		if (mp.size() < j - i + 1) {
			//mtlb ki repeating characters aa gaye hai.
			while (mp.size() < j - i + 1) {
				mp[s[i]]--;
				if (mp[s[i]] == 0) mp.erase(s[i]);
				i++;
			}
		}
		j++;
	}
	cout << ans;

}
int main() {
	string s = "abcabcbb";
	fun(s);
}