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
		//(n1+n2+1) / 2 --> define the size of left half, +1 coz, odd and even sum(n1+n2) ko handle kr lega easily
		//if even(n1+n2) like 10, to 10+1/2 is 5 or agr +1 ni kroge for example 10/2 is 5, means +1 kro ya na kro ans 5 hi aega in case of even length
		//if odd(n1+n2) like 11, to 11+1/2 is 6 -> so left me 6 hoge and right me 5 that will make left larger then right is case of odd lenght, to neeche code me dekho odd length ke liye median kese nikal rhe smjh aa jaega
		cout << "cut1 " << cut1 << " cut2 " << cut2 << endl;
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
	PREREQUISITE: kth element of two sorted arrays
	VIDEO LINK: https://www.youtube.com/watch?v=NTop3VTjmxk
	*/
	// vector<int> arr1 = {1, 2};
	// vector<int> arr2 = {3, 4};

	vector<int> arr1 = {1, 3};
	vector<int> arr2 = {2};
	cout << "result " << MedianOfTwoSortedArrays(arr1, arr2);
}