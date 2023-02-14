#include <bits/stdc++.h>
using namespace std;

int digitSqSum(int n) {
    int sum = 0;
    while (n > 0) {
        sum = sum + ((n % 10) * (n % 10));
        n = n / 10;
    }
    return sum;
}

bool isHappy(int n) {
    set<int> st;
    while (n != 1) {
        if (st.find(n) != st.end()) { //found
            return false;
        }
        st.insert(n);

        n = digitSqSum(n);
    }
    return true;
}

int main() {
    /*
    NOTE: this is a mathematical problem
    VIDEO LINK: https://www.youtube.com/watch?v=Egw03gI-Tf0
    LEETCODE LINK: https://leetcode.com/problems/happy-number/solutions/2676462/c-5-approaches-o-n-o-logn-0-ms-solution-w-explanation/
    */
    int n = 2;
    bool ans = isHappy(n);
    if (ans) cout << "yes";
    else cout << "no";
}
