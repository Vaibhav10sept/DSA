#include<bits/stdc++.h>
using namespace std;

int missingNumber(vector<int> arr) {
    // NOTE: simple intuitive solution
    int n = arr.size();
    int sumN = 0;
    for (int i = 0; i <= n; i++) sumN += i;

    int sum  =  0;
    for (int ele : arr) sum += ele;

    return sumN - sum;
}


int main() {
    /*
    NOTE: simple intuitive solution
    VIDEO: https://www.youtube.com/watch?v=WnPLSRLSANE
    LEETCODE: https://leetcode.com/problems/missing-number/description/
    */
    vector<int> arr = {9, 6, 4, 2, 3, 5, 7, 0, 1};
    cout << "ans " << missingNumber(arr);
}