#include <bits/stdc++.h>
using namespace std;

int paintHouse(vector<vector<int>> arr) {
	//Please watch attached video(link) for more understanding.
	int red = arr[0][0];
	int blue = arr[0][1];
	int green = arr[0][2];

	// LOGIC: red, blue, green works as a DP storage
	// red --> red stores ki uss ghar pr red color lgane pr and no consecutive ghar pr same color lgane pr, kitni min cost aegi
	// blue, green stores the same information as in red.

	for (int i = 1; i < arr.size(); i++) {
		int nRed = std::min(blue, green) + arr[i][0];
		int nBlue = std::min(red, green) + arr[i][1];
		int nGreen = std::min(blue, red) + arr[i][2];

		red = nRed;
		blue = nBlue;
		green = nGreen;
	}

	return std::min(red, std::min(blue, green));
}

int main()
{
	//***************************
	// video link: https://www.youtube.com/watch?v=kh48JLieeW8&list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk&index=495
	// NOTE: similar to "maximum-sum-non-adjacent-element"
	//**************************************************
	//input:
// 4
// 1 5 7
// 5 8 4
// 3 2 9
// 1 2 4
	int n;
	cin >> n;
	vector<vector<int>> input(n, vector<int>(3));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> input[i][j];
		}
	}

	cout << "minimum cost of paint: " << paintHouse(input);
}
