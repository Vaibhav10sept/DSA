#include<bits/stdc++.h>
using namespace std;

int integerBreak(int num) {
    vector<int> dp(num + 1, 0);
    dp[1] = 1; //initialization

    for (int n = 2; n < dp.size(); n++) {
        int res = 0;
        for (int i = 1; i < n; i++) {
            int firstVal = i;
            int secondVal = n - i;
            res = max(res, firstVal * max(dp[secondVal], secondVal));
        }
        dp[n] = res;
    }

    return dp[num];
}

int main() {
    /*
    NOTE: this dp sol is derived from the rec sol.
    NOTE: wv recommended, not so intuitive
    NOTE: a recursive solution is also there.
    VIDEO: https://www.youtube.com/watch?v=nSbnoNfHPG0
    LEETCODE: https://leetcode.com/problems/integer-break/description/
    */
    int n = 10;
    cout << integerBreak(n);
}