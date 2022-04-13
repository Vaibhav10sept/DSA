#include <bits/stdc++.h>
using namespace std;
void displaybits(int a) {
    for (int i = 10; i >= 0; i--) {
        cout << (1 & (a >> i));
    }
    cout << endl;
}
int main() {
    int  a = 9;
    displaybits(a);
    cout << "count of set bits" << endl;
    int ct = 0;
    for (int i = 31; i >= 0; i--) {
        if (1 & (a >> i)) ct++;
    }
    cout << ct << endl;
    int bit = 1;
    cout << "Is ith bit unset" << endl;
    if ((a & (1 << bit)) == 0) cout << "yes" << endl;
    else cout << "no" << endl;
    cout << "is ith bit set" << endl;
    if ((a & (1 << bit)) != 0) cout << "yes" << endl;
    else cout << "no" << endl;
    cout << "set ith bit" << endl;
    int res1 = a | (1 << bit);
    displaybits(res1);
    cout << "unset ith bit" << endl;
    int res2 = a & ~(1 << 3);
    displaybits(res2);
    cout << "toggle ith bit" << endl;
    int res3 = a ^ (1 << 2);
    displaybits(res3);



}
