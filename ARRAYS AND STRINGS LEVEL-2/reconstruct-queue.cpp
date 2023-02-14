#include <bits/stdc++.h>
using namespace std;

//Compare function for the logic of sort
//Sorts in descending order
static bool compare(vector<int>& a, vector<int> & b)
{
	//0th index is --> height
	//1th index is --> k(no of people ahead)

	if (a[0] == b[0]) //if same height, then sort in inc. order of k
		return a[1] < b[1];

	return a[0] > b[0]; //otherwise, sort in dec. order of height.
}

vector<vector<int>> reconstructQueue(vector<vector<int>>& arr) {
	//WV recommended
	int n = arr.size();

	sort(arr.begin(), arr.end(), compare); //Sorting the array according to comp function.
	vector<vector<int>> res; //To store the final array to be returned

	for (int i = 0; i < n; i++)
	{
		int idx = arr[i][1];
		res.insert(res.begin() + idx, arr[i]); //Inserting the element at desired position.
	}

	return res;
}

int main() {
	/*
	NOTE: daily challenge question
	VIDEO LINK: https://www.youtube.com/watch?v=40H5vRK_H2E
	LEETCODE: https://leetcode.com/problems/queue-reconstruction-by-height/
	*/
	vector<vector<int>> arr = {{7, 0}, {4, 4}, {7, 1}, {5, 0}, {6, 1}, {5, 2}};
	vector<vector<int>> ans = reconstructQueue(arr);
	for (auto vec : ans) {
		for (int ele : vec) cout << ele << " ";
		cout << endl;
	}

}



