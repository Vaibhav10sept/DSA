#include <bits/stdc++.h>
using namespace std;

int buldSwitcher4(string str) {
	int futureBulbState = 0;
	int ans = 0;
	for (char ch : str) {
		int curr = ch - '0';
		if (futureBulbState == curr) continue;
		ans++;
		futureBulbState = futureBulbState == 1 ? 0 : 1;
	}
	return ans;
}

int main() {
	//*********************************
	// VIDEO LINK: https://www.youtube.com/watch?v=VGDHph1k0tQ&list=PL-Jc9J83PIiE-TR27GB7V5TBLQRT5RnSl&index=60
	// LEETCODE LINK: NOT FOUND
	//*********************************
	string str = "001011101";
	// string str = "00000";
	cout << buldSwitcher4(str);
}