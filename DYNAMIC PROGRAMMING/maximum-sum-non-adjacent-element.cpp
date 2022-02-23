#include <bits/stdc++.h>
using namespace std;


int maximumSumNonAdjacentElement(vector<int> arr) {
	//Please watch attached video(link) for more understanding.
	int exclude = 0;
	int include = arr[0];

	for (int i = 1; i < arr.size(); i++) {
		int temp = include;
		include = exclude + arr[i];
		exclude = std::max(temp, exclude);
	}

	return std::max(include, exclude);
}

int main()
{
	//***************************
	// video link: https://www.youtube.com/watch?v=VT4bZV24QNo&list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk&index=494
	//**************************************************
	vector<int> arr = {5, 10, 10, 100, 5, 6};
	cout << "max sum is: " << maximumSumNonAdjacentElement(arr);
}