#include<bits/stdc++.h>
using namespace std;

bool isPowerOfTwo(int n) {
    if (n < 1) return false; //edge case
    if (n == 1) return true; //edge case

    long long val  = 2;
    while (val < n) {
        val = val * 2;
    }

    if (val == n) return true;
    return false;
}


int main() {
    /*
    NOTE: I wrote this code without any help
    VIDEO:
    LEETCODE: https://leetcode.com/problems/power-of-two/description/
    */
    int n = 3;
    if (isPowerOfTwo(n)) {
        cout << "true" << endl;
    }
    else cout << "false";
}