#include <bits/stdc++.h>
using namespace std;

void solveConfiguration(vector<char> &arr, int i, int j) {
	// there can be 4 cases as below:
	if (arr[i] == 'L' and arr[j] == 'L') {
		//make all dots as L
		for (int k = i + 1; k < j; k++) {
			arr[k] = 'L';
		}
	}
	else if (arr[i] == 'R' and arr[j] == 'R') {
		//make all dots as R
		for (int k = i + 1; k < j; k++) {
			arr[k] = 'R';
		}
	}
	else if (arr[i] == 'L' and arr[j] == 'R') {
		//nothing to do
	}
	else { //(arr[i] == 'R' and arr[j] == 'L')
		// cout << "gsd";
		//solve accordingly, for odd and even.
		int diff = j - i - 1; //logic
		int mid = (j + i) / 2;
		if (diff % 2 == 0) { //even dots
			//i+1 to mid --> 'R'
			//mid+1 to j-1 --> 'L'
			for (int k = i + 1; k <= mid; k++) {
				arr[k] = 'R';
			}
			for (int k = mid + 1; k <= j - 1; k++) {
				arr[k] = 'L';
			}
		}
		else { //odd dots
			//i+1 to mid -1 --> 'R'
			//mid+1 to j-1 --> 'L'
			for (int k = i + 1; k <= mid - 1; k++) {
				arr[k] = 'R';
			}
			for (int k = mid + 1; k <= j - 1; k++) {
				arr[k] = 'L';
			}
		}
	}
}

string pushDonimos(string str) {
	int n = str.size();
	vector<char> arr(n + 2);
	//we put L and R at the two ends to make the segments, watch video

	//fill up the arr
	arr[0] = 'L';
	arr[arr.size() - 1] = 'R';
	for (int i = 1; i < arr.size() - 1; i++) {
		arr[i] = str[i - 1];
	}



	//finding out the segments and solving each segment
	int j = 0;
	int k = 1;
	while (k < arr.size()) {
		while (arr[k] == '.') k++;
		if (k - j > 1)
			solveConfiguration(arr, j, k);

		j = k;
		k++;
	}

	//create string using arr remember to skip the first and last char
	string ans = "";
	for (int i = 1; i < arr.size() - 1; i++) {
		ans += arr[i];
	}
	return ans;
}

int main() {
	//*********************************
	// VIDEO LINK: https://www.youtube.com/watch?v=Fo4ORqOLDCY&list=PL-Jc9J83PIiE-TR27GB7V5TBLQRT5RnSl&index=49
	// QUESTION:
// 1. There are n dominoes in a line, and we place each domino vertically upright.
// 2. In the beginning, we simultaneously push some of the dominoes either to the left or to the right.
// 3. After each second, each domino that is falling to the left pushes the adjacent domino on the left.
// 4. Similarly, the dominoes falling to the right push their adjacent dominoes standing on the right.
// 5. When a vertical domino has dominoes falling on it from both sides, it stays still due to the balance of the forces.
// 6. For the purposes of this question, we will consider that a falling domino expends no additional force to a falling or already fallen domino.
// 7. You are given a string dominoes representing the initial state where:
//     a). dominoes[i] = 'L', if the ith domino has been pushed to the left,
//     b). dominoes[i] = 'R', if the ith domino has been pushed to the right, and
//     c). dominoes[i] = '.', if the ith domino has not been pushed.
// 8. Return a string representing the final state.
	//*********************************
	string dominos =  ".L.R...LR..L..";
	cout << pushDonimos(dominos);
}