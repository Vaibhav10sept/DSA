#include <bits/stdc++.h>
using namespace std;

int findPivotSortedRotatedArray(vector<int> arr) {
	//please watch the video(link below) for better understanding.
	//NOTE: hm array ko do parts me divide krege --> low to mid and mid+1 to high
	int low = 0;
	int high = arr.size() - 1;
	while (low < high) { //not low<=high coz, low==high means 1 size array or 1 size array me pivot vo value hi hogi
		int mid = ( low + high) / 2;
		if (arr[mid] < arr[high]) { //mid se high ki trf value gir rhi h, toh pivot left me hoga, left half me jao
			//NOTE: hm array ko do parts me divide krege --> low to mid and mid+1 to high
			high = mid;
		}
		else { // arr[mid] >= arr[high]
			//NOTE: hm array ko do parts me divide krege --> low to mid and mid+1 to high
			//right half me jao
			low = mid + 1;
		}
	}
	//ab yha pe, low and high dono same h, to arr[high] ya arr[low] kuch bhi return kro
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