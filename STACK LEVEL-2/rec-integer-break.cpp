#include<bits/stdc++.h>
using namespace std;

int rec(int n, vector<int> &memo) {
    if (n == 1) return 1;
    //BC ends

    if (memo[n] != -1) return memo[n];

    int res = 0;
    for (int i = 1; i < n; i++) {
        int firstVal = i;
        int secondVal = n - i;
        res = max(res, firstVal * max(rec(secondVal, memo), secondVal));
    }
    return memo[n] = res;
}

int integerBreak(int n) {
    vector<int> memo(n + 1, -1);
    return rec(n, memo);
}

int main() {
    /*
    NOTE: wv recommended, not so intuitive
    NOTE: a dp solution is also there.
    VIDEO: https://www.youtube.com/watch?v=nSbnoNfHPG0
    LEETCODE: https://leetcode.com/problems/integer-break/description/
    */
    int n = 10;
    cout << integerBreak(n);
}