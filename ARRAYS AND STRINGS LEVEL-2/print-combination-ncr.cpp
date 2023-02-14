#include <bits/stdc++.h>
using namespace std;

void printCombinationRec(int currentBox, vector<bool> &visited, int r, int lastBox, vector<int> arr) {
	//BC
	//NOTE: question in the video is modified to match geek for geeks question's solution, think, maense khud se kia ye
	if (currentBox > r) { //means tumne 'r' number of boxes place kr die h, to print krdo arr ko using visited array(think)
		for (int i = 0; i < visited.size(); i++) {
			if (visited[i]) {
				cout << arr[i] << " ";
			}
		}
		cout << endl;
		return;
	}

	for (int i = lastBox + 1; i < visited.size(); i++) {
		if (visited[i] == false) {
			visited[i] = true;
			printCombinationRec(currentBox + 1, visited, r, i, arr);

			//backtrack
			visited[i] = false;
		}
	}
}

void printCombination(int r, int totalBoxes, vector<int> arr) {
	vector<bool> visited(totalBoxes, false);
	printCombinationRec(1, visited, r, -1, arr); // -1 --> is last box placed, -1 coz +1 krne pe 0th index ho jaega.(think, wv)
}

int main() {
	//*********************************
	// STRONG PREREQUISITE: backtracking permutations
	// VIDEO LINK: https://www.youtube.com/watch?v=f6cL-VMIfTY
	// QUESTION LINK: https://www.geeksforgeeks.org/print-all-possible-combinations-of-r-elements-in-a-given-array-of-size-n/
	//*********************************
	// ncr --> n is total boxes
	//         r is r.
	int r = 2; //also called as allowed places/boxes
	vector<int> arr = {1, 2, 3, 4};
	int totalBoxes = arr.size();
	printCombination(r, totalBoxes, arr);
}