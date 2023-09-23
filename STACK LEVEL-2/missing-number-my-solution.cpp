#include<bits/stdc++.h>
using namespace std;

int missingNumber(vector<int> arr) {
    //i wrote this without video or solution, just all by myself
    bool isZeroPresent = false;
    bool isOnePresent = false;
    for (int i = 0; i < arr.size(); i++) {
        int ele = arr[i];
        if (ele == 0) {
            isZeroPresent = true;
            arr[i] = 1;
        }
        else if (ele == 1) isOnePresent = true;

    }

    if (isZeroPresent == false) return 0;
    if (isOnePresent == false) return 1;

    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] != 0) {
            int ind = abs(arr[i]) - 1;
            // cout << "ind " << ind << " " << arr.size() << endl;
            arr[ind] = -1 * abs(arr[ind]);
        }
    }

    // cout << "print" << endl;
    // for (auto ele : arr) cout << ele << " ";
    // cout << endl;

    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] >= 0) return i + 1;
    }
}


int main() {
    /*
    NOTE: i wrote this without video or solution, just all by myself
    STRONG PREREQUISITE: first missing positive
    */
    vector<int> arr = {1, 0, 2};
    cout << "ans " << missingNumber(arr);
}