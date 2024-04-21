#include<bits/stdc++.h>
using namespace std;

int kthFactor(int n, int k) {
    int factor = 1;
    int ans = 0;
    while (factor <= n and k) {
        if (n % factor == 0) {
            k--;
            if (k == 0) ans = factor;
        }
        factor++;
    }

    if (ans != 0) return ans;
    return -1;
}


int main() {
    /*
    LEETCODE: https://leetcode.com/problems/the-kth-factor-of-n/description/
    VIDEO:
    */
    int n = 7;
    int k = 2;
    cout << kthFactor(n, k);
}