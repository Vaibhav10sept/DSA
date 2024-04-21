#include<bits/stdc++.h>
using namespace std;

double angleBetweenHands(int hours, int minutes) {
    //logic: to find degree move in one hour: 12 hours --> 360 degree
    // 1 hour --> 30 degree
    //logic: to find degree move in one minute: 60 minute --> 360 degree
    // 1 minute --> 6 degree
    // we'll use this calculation to solve
    //NOTE: rem minute hand ke movement se hour hand bhi thoda sa move hota hai, to use bhi degree calculation me consider krna mt bhulna

    float degreeHour = (hours + (float)minutes / 60) * 30;
    double degreeMinute = minutes * 6;
    // cout << "tes " << degreeHour << " " << degreeMinute << endl;
    double degreeDiff = abs(degreeHour - degreeMinute);
    if (degreeDiff > 180) {
        degreeDiff = 360 - degreeDiff;
    }
    return degreeDiff;
}

int main() {
    /*
    VIDEO: https://www.youtube.com/watch?v=FK_wnA0ERBQ
    LEETCODE: https://leetcode.com/problems/angle-between-hands-of-a-clock/
    */
    int hour = 1;
    int minutes = 57;
    cout << angleBetweenHands(hour, minutes);
}