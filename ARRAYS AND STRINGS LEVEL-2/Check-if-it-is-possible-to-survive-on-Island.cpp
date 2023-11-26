#include <bits/stdc++.h>
using namespace std;

int minimumDays(int s, int n, int m) {
	// N – The maximum unit of food you can buy each day.
	// S – Number of days you are required to survive.
	// M – Unit of food required each day to survive.

	if (m > n) return -1; //think, cs

	//total valid days in which we can actually buy, means remove sundays
	int cntOfSundays = s / 7;
	int totalValidDays = s - cntOfSundays;

	int totalFoodRequired = s * m;

	int days = totalFoodRequired / n;
	if (totalFoodRequired % n != 0) {
		days++;
	}

	if (totalValidDays >= days) return days;
	return -1;
}

int main() {
	/*********************************
	// VIDEO LINK: https://www.youtube.com/watch?v=Wq4Sn20dHr8
	// QUESTION: https://practice.geeksforgeeks.org/problems/check-if-it-is-possible-to-survive-on-island4922/1?utm_source=geeksforgeeks&utm_medium=article_practice_tab&utm_campaign=article_practice_tab
	//*********************************/
	int s = 10;
	int n = 16;
	int m = 2;
	cout << minimumDays(s, n, m);
}