#include <bits/stdc++.h>
using namespace std;

int minJumps(int x) {
	int jumpSize = 1;
	int currPoint = 0;
	int noOfJumps = 0;

	//this is where we are moving ahead of "x"
	while (currPoint < x) {
		currPoint += jumpSize;
		jumpSize++;
		noOfJumps++;
	}
	int differenceInDistance = currPoint - x;
	if (differenceInDistance % 2 == 0) { // even hai-> current no of jumps is the answer
		return noOfJumps;
	}
	else { // odd hai-> take one extra jump and then calculate new difference in distance
		currPoint += jumpSize;
		jumpSize++;
		noOfJumps++;

		int newDifferenceInDistance = currPoint - x;
		if (newDifferenceInDistance % 2 == 0) { // even hai-> current no of jumps is the answer
			return noOfJumps;
		}

		else { // odd hai-> take one extra jump and then calculate new difference in distance
			currPoint += jumpSize;
			jumpSize++;
			noOfJumps++;
			int newNewDifferenceInDistance = currPoint - x;

			//now, we are sure that "newNewDifferenceInDistance" is going to be even(watch video logic)
			//even hai toh current no of jumps is your answer.
			return noOfJumps;
		}
	}
}

int main() {
	//*********************************
	// VIDEO LINK: https://www.youtube.com/watch?v=fsips_0hwEA&list=PL-Jc9J83PIiE-TR27GB7V5TBLQRT5RnSl&index=15
	// QUESTION:
	// 1. Given an integers X.
	// 2. The task is to find the minimum number of jumps to reach a point X in the number line starting from zero.
	// 3. The first jump made can be of length one unit and each successive jump will be exactly one unit longer than the previous jump in length.
	// 4. It is allowed to go either left or right in each jump.
	//*********************************

	int x = 8;
	cout << "min no of jumps: " << minJumps(x);
}