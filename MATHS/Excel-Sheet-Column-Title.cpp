#include <bits/stdc++.h>
using namespace std;

string convertToTitle(int n) {
    string ans = "";
    while (n) {
        //why (n-1), WV recommended
        char ch = 'A' + (n - 1) % 26;
        ans = ch + ans;
        n = (n - 1) / 26;
    }
    return ans;
}

int main() {
    /*
    NOTE: this is a mathematical problem
    VIDEO LINK: youtube.com/watch?v=UcTKk2y_3s4
    LEETCODE LINK: https://leetcode.com/problems/excel-sheet-column-title/description/
    */
    int columnNumber = 701;
    cout << convertToTitle(columnNumber);
}
