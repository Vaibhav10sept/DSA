#include<bits/stdc++.h>
using namespace std;

double MedianOfTwoSortedArrays(vector<int> arr1, vector<int> arr2) {
	/*
	watch video highly recommended
	*/
	//we assume that arr1 is smaller, if its not then below if will handle that
	if (arr2.size() < arr1.size()) return MedianOfTwoSortedArrays(arr2, arr1);
	int n1 = arr1.size();
	int n2 = arr2.size();
	int low = 0, high = n1;

	while (low <= high) {
		int cut1 = (low + high) / 2;
		int cut2 = (n1 + n2 + 1) / 2 - cut1;
		//(n1+n2+1) / 2 --> define the size of left half

		int left1 = cut1 == 0 ? INT_MIN : arr1[cut1 - 1];
		int left2 = cut2 == 0 ? INT_MIN : arr2[cut2 - 1];

		int right1 = cut1 == n1 ? INT_MAX : arr1[cut1];
		int right2 = cut2 == n2 ? INT_MAX : arr2[cut2];

		if (left1 <= right2 and left2 <= right1) {
			//means its a valid partition
			if ((n1 + n2) % 2 == 0) {
				//even size arrays
				//(max(left1,left2) + min(right1,right2))/2.0 --> median for even lenght array(think,watch video)
				return (max(left1, left2) + min(right1, right2)) / 2.0;
			}
			else { //odd lenght arrays
				return max(left1, left2);
			}
		}
		else if (left1 > right2) { //left1 ko chota krna hai, toh move left
			high = cut1 - 1;
		}
		else { //left2 > right1
			//right1 ko bada krna hoga, move to right(think, watch video)
			low = cut1 + 1;
		}
	}
	return 0.0;
}

int main() {
	/*
	PREREQUISITE:
	VIDEO LINK: https://www.youtube.com/watch?v=NTop3VTjmxk
	*/
	vector<int> arr1 = {1, 2};
	vector<int> arr2 = {3, 4};
	cout << MedianOfTwoSortedArrays(arr1, arr2);
}