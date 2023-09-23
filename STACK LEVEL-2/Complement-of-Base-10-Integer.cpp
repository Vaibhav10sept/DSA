#include<bits/stdc++.h>
using namespace std;

int complementOfBase10Integer(int n) {
    // NOTE: wv recommended
    // NOTE: this question me hme kae bitwise operator ke concepts seekhne ko milege

    if (n == 0) return 1; //edge case

    int temp = n;
    int mask = 0;

    //here, we are creating a mask of n(temp)
    while (temp != 0) {
        temp = temp >> 1;
        mask = mask << 1;
        mask = mask | 1;
    }

    int ans = (~n) & mask; //think, cs, wv
    return ans;
}


int main() {
    /*
    NOTE: wv recommended
    NOTE: this question me hme kae bitwise operator ke consepts seekhne ko milege
    VIDEO: https://www.youtube.com/watch?v=0fwrMYPcGQ0
    LEETCODE: https://leetcode.com/problems/complement-of-base-10-integer/description/
    */
    int n = 10;
    cout << complementOfBase10Integer(n);
}