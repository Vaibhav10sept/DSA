#include <bits/stdc++.h>
using namespace std;

int minimumDominoRotationForEqualRow(vector<int> tops, vector<int> bottoms) {
	int num1 = tops[0];
	int num2 = bottoms[0];
	int count1 = 0, count2 = 0, count3 = 0, count4 = 0;
	// count1 : no of swapping(rotations) required to make the tops as num1
	// count2 : no of swapping(rotations) required to make the bottoms as num1
	// count3 : no of swapping(rotations) required to make the tops as num2
	// count4 : no of swapping(rotations) required to make the bottoms as num2

	for (int i = 0; i < tops.size(); i++) {
		//for num1
		//count1
		if (count1 != INT_MAX) {
			if (tops[i] == num1) {

			}
			else if (bottoms[i] == num1) {
				count1++;
			}
			else {
				count1 = INT_MAX;
			}
		}
		//count2
		if (count2 != INT_MAX) {
			if (bottoms[i] == num1) {

			}
			else if (tops[i] == num1) {
				count2++;
			}
			else {
				count2 = INT_MAX;
			}
		}

		//for num2
		//count3
		if (count3 != INT_MAX) {
			if (tops[i] == num2) {

			}
			else if (bottoms[i] == num2) {
				count3++;
			}
			else {
				count3 = INT_MAX;
			}
		}
		//count4
		if (count4 != INT_MAX) {
			if (bottoms[i] == num2) {

			}
			else if (tops[i] == num2) {
				count4++;
			}
			else {
				count4 = INT_MAX;
			}
		}
	}//if ends
	int ans = min(min(count1, count2), min(count3, count4));
	if (ans != INT_MAX) {
		return ans;
	}
	else {
		return -1;
	}

}

int main() {
	//*********************************
	// VIDEO LINK: https://www.youtube.com/watch?v=mnYHDE9Kk9s&list=PL-Jc9J83PIiE-TR27GB7V5TBLQRT5RnSl&index=37
	// QUESTION:
	// 1. In a row of dominoes, tops[i] and bottoms[i] represent the top and bottom halves of the ith domino.
	// 2. A domino(Dice Structured) is a tile with two numbers from 1 to 6 - one on each half of the tile.
	// 3. We may rotate the ith domino, so that tops[i] and bottoms[i] swap values.
	// 4. Return the minimum number of rotations so that all the values in tops are the same, or all the values in bottoms are the same.
	// 5. If it cannot be done, return -1.
	//*********************************
	vector<int> tops = {2, 1, 2, 4, 2, 2};
	vector<int> bottoms = {5, 2, 6, 2, 3, 2};
	cout << minimumDominoRotationForEqualRow(tops, bottoms);
}