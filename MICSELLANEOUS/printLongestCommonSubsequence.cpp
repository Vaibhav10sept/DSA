//recursive code hai ye---dp nhi use ki hai isme
#include <bits/stdc++.h>
using namespace std;
string res = "";
int rec(string s1, string s2, int m, int n, string ans) {
	if (m == 0 or n == 0) {
		if (ans.length() > res.length()) {
			res = ans;
		}
		// cout << ans << endl;
		return 0;
	}
	if (s1[m - 1] == s2[n - 1] ) {
		// res += s1[m - 1];
		ans += s1[m - 1];
		return 1 + rec(s1, s2, m - 1, n - 1, ans);
	}
	else {
		return max(rec(s1, s2, m - 1, n, ans),
		           rec(s1, s2, m , n - 1, ans));
	}
}



int main() {
	string s1 = "aacbcf";
	string s2 = "aacbcf";
	int m = s1.length();
	int n = s2.length();

	int ans = rec(s1, s2, m, n, "");
	cout << ans << endl;
	reverse(res.begin(), res.end());
	cout << res << endl;


}