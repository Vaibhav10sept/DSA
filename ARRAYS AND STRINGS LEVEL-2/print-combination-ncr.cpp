#include <bits/stdc++.h>
using namespace std;

void printCombinationRec(int currentBox, vector<bool> &visited, int r, int lastBox, vector<vector<int>> &res) {
	//BC
	//NOTE: question in the video is modified to match geek for geeks question's solution, think, maense khud se kia ye
	if (currentBox > r) { //means tumne 'r' number of boxes place kr die h, to print krdo arr ko using visited array(think)
		vector<int> ans;
		for (int i = 0; i < visited.size(); i++) {
			if (visited[i]) {
				ans.push_back(i + 1);
			}
		}
		res.push_back(ans);
		return;
	}

	for (int i = lastBox + 1; i < visited.size(); i++) {
		if (visited[i] == false) {
			visited[i] = true;
			printCombinationRec(currentBox + 1, visited, r, i, res);

			//backtrack
			visited[i] = false;
		}
	}
}

vector<vector<int>> printCombination(int r, int totalBoxes) {
	vector<bool> visited(totalBoxes, false);
	vector<vector<int>> res;
	printCombinationRec(1, visited, r, -1, res); // -1 --> is last box placed, -1 coz +1 krne pe 0th index ho jaega.(think, wv)
	return res;
}

int main() {
	//*********************************
	// STRONG PREREQUISITE: backtracking permutations
	// VIDEO LINK: https://www.youtube.com/watch?v=f6cL-VMIfTY
	// QUESTION LINK: https://www.geeksforgeeks.org/print-all-possible-combinations-of-r-elements-in-a-given-array-of-size-n/
	// LEETCODE: https://leetcode.com/problems/combinations/description/
	//*********************************
	// ncr --> n is total boxes
	//         r is r.
	int r = 2; //also called as allowed places/boxes
	int n = 4;
	vector<vector<int>> ans = printCombination(r, n);
	for (auto vec : ans) {
		for (int ele : vec) {
			cout << ele << " ";
		}
		cout << endl;
	}
}