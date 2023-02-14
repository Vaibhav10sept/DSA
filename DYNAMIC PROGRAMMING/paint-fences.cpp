#include <bits/stdc++.h>
using namespace std;

int paintFences(int n, int k) {
	//Please watch attached video(link) for better understanding.
	int lastTwoSameColor = k;
	int lastTwoDiffColor = k * (k - 1);
	int total = lastTwoDiffColor + lastTwoSameColor;

	for (int i = 3; i <= n; i++) {
		lastTwoSameColor = lastTwoDiffColor;
		lastTwoDiffColor = total * (k - 1);
		total = lastTwoDiffColor + lastTwoSameColor;
	}
	return total;
}

int main()
{
	/***************************
	video link: https://www.youtube.com/watch?v=ju8vrEAsa3Q&list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk&index=508
	Given a fence with n posts and k colors, find out the number
	of ways of painting the fence such that at most 2 adjacent posts have the same color.
	**************************************************/
	int n = 5; //no of fences
	int k = 3; //no of colors
	cout << "No of ways fences can be colored such that no two consecutive fence had the same color: " << paintFences(n, k);
}
