#include <bits/stdc++.h>
using namespace std;

int findPivotSortedRotatedArray(vector<int> arr) {
	//please watch the video(link below) for better understanding.
	int low = 0;
	int high = arr.size() - 1;
	while (low < high) {
		int mid = ( low + high) / 2;
		if (arr[mid] < arr[high]) { //left half me jao
			high = mid;
		}
		else {	//right half me jao
			low = mid + 1;
		}
	}
	return arr[high];
}

int main()
{
	//*****************************
	// NOTE: using binary search approach
	// NOTE: pivot means sbse chota element in an sorted rotated array
	// video link: https://www.youtube.com/watch?v=vF7gk4iaklA&list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk&index=509
	// time complexity: logn
	//*****************************************
	vector<int> arr = {40, 50, 10, 20, 30};
	cout << "PIVOT IS: " << findPivotSortedRotatedArray(arr);
}