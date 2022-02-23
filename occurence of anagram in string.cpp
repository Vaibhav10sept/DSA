
// // Given a list of non negative integers, arrange them in such a
// manner that they form the largest number possible.The result is
// going to be very large, hence return the result in the form of a string.
// //         N = 5
// //             Arr[] = {3, 30, 34, 5, 9}
// //                     Output: 9534330
#include <bits/stdc++.h>
using namespace std;


void countana(string pat, string str) {
	int i, j;
	i = 0;
	j = 0;
	map<char, int> mp;
	for (auto i : pat) {
		mp[i]++;
	}
	int ans = 0;
	int cnt = mp.size();
	int k = pat.length();
	// cout << "k " << k << endl;
	// cout << "count " << cnt << endl;
	// cout << "str lentgh " << str.length() << endl;


	while (j < str.length()) {


		if (mp.find(str[j]) != mp.end()) {
			mp[str[j]]--;
			if (mp[str[j]] == 0) cnt--;
			// cout << "j" << j << endl;

		}
		if ((j - i + 1) < k) {
			cout << "K " << k << endl;
			j++;
			// cout << "windown " << j - i + 1 << endl;

		}

		else if ((j - i + 1) == k) {
			// cout << "cont " << j << endl;
			// cout << "cont i " << i << endl;
			// cout << "" << i << endl;



			if (cnt == 0) {
				ans++;
			}
			if (mp.find(str[i]) != mp.end()) {
				if (mp[str[i]] == 0) cnt++;
				mp[str[i]]++;
			}
			i++;
			j++;
		}


	}


	cout << ans << endl;
}

int main() {
	string pat = "aaba";
	string str = "aabaabaa";
	countana(pat, str);

}


