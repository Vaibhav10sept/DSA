#include<bits/stdc++.h>
using namespace std;

bool isPowerOfTwo(int n) {
    //NOTE: read the below appraoch explanation and think
    if (n <= 0) return false; //edges case

    return ((n & (n - 1)) == 0); //think, read the approach below.
}


int main() {
    /*
    Let's take some good exampes :
    number->binary form
    3->0000 0011
    4->0000 0100
    5->0000 0101
    6->0000 0110
    7->0000 0111
    8->0000 1000
    The observation we can conclude is that the number which is a
    power of two has always compulsoryily 1 true bit.

    Now consider :-
    bit representation of 7  -> 0111
    bit representation of 8  -> 1000
    bitwise AND of 7 and 8 -> 0000
    we are gonna use this property for for all numbers which are powers of two

    LEETCODE: https://leetcode.com/problems/power-of-two/description/
    */
    int n = 3;
    if (isPowerOfTwo(n)) {
        cout << "true" << endl;
    }
    else cout << "false";
}