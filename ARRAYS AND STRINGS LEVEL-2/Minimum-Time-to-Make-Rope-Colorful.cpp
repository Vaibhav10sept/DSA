#include <bits/stdc++.h>
using namespace std;

int minTimeToMakeRopeColorfull(string color, vector<int> timeNeeded) {
	int ans = 0;
	for (int i = 0; i < color.size() - 1; i++) {

		if (color[i] == color[i + 1]) {
			cout << "tes " << i << endl;
			int sumOfSameColor = timeNeeded[i];
			int maxOfSameColor = timeNeeded[i];
			while (i + 1 < color.size() and color[i] == color[i + 1]) {
				sumOfSameColor += timeNeeded[i + 1];
				maxOfSameColor = max(maxOfSameColor, timeNeeded[i + 1]);
				i++;
			}
			ans += (sumOfSameColor - maxOfSameColor);
		}
	}
	return ans;
}

int main() {
	/*********************************
	 * NOTE: i wrote this code after watching the video
	NOTE: good question think about the sol first, use pen paper
	// LEETCODE: https://leetcode.com/problems/minimum-time-to-make-rope-colorful/description/
	VIDEO: https://www.youtube.com/watch?v=wq6HX-LvIG4
	//*********************************/
	string colors = "abaac";
	vector<int> neededTime = {1, 2, 3, 4, 5};
	cout << minTimeToMakeRopeColorfull(colors, neededTime);
}