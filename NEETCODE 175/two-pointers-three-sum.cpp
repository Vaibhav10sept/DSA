#include <bits/stdc++.h>
using namespace std;

void displayMatrix(vector<vector<int>> arr) {
	for (int i = 0; i < arr.size(); i++) {
		for (int j = 0; j < arr[i].size(); j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}

vector<vector<int>> threeSum(vector<int> arr) {
	vector<vector<int> > res;

	std::sort(arr.begin(), arr.end());

	for (int i = 0; i < arr.size(); i++) {

		int target = -arr[i];
		int front = i + 1;
		int back = arr.size() - 1;

		while (front < back) { //this is two sum

			int sum = arr[front] + arr[back];

			// Finding answer which start from number arr[i]
			if (sum < target)
				front++;

			else if (sum > target)
				back--;

			else { //we found the answer
				vector<int> triplet = {arr[i], arr[front], arr[back]};
				res.push_back(triplet);

				//here we are removing the duplicate triplets
				// Processing duplicates of number 2
				// Rolling the front pointer to the next different number forwards
				while (front < back && arr[front] == triplet[1]) front++;

				// Processing duplicates of number 3
				// Rolling the back pointer to the next different number backwards
				while (front < back && arr[back] == triplet[2]) back--;
			}

		}

		// Processing duplicates of number 1
		while (i + 1 < arr.size() && arr[i + 1] == arr[i])
			i++;

	}

	return res;
}

int main() {
	/*
	*********************************
	VIDEO LINK:
	*********************************
	*/
	vector<int> arr = { -1, 0, 1, 2, -1, -4};
	vector<vector<int>> ans = threeSum(arr);
	displayMatrix(ans);
}