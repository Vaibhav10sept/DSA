#include <bits/stdc++.h>
using namespace std;


long long countTriplets(long long arr[], int n, long long target)
{
	sort(arr, arr + n);
	int cnt = 0;

	for (int i = 0; i < n - 2; i++) {
		int start = i + 1;
		int end = n - 1;
		while (start < end) {
			int sum = arr[i] + arr[start] + arr[end];
			if (sum >= target) end--; //sum ko kam krna pdega, isliye end--, think, wv
			else { //sum < target
				cnt += end - start;
				start++;
			}
		}
	}
	return cnt;
}

int main() {
	/*********************************
	STRONG PREQ: 3sum-target-sum-unique-triplets
	// VIDEO LINK: https://www.youtube.com/watch?v=9455buJlb_k
	QUESTION: https://practice.geeksforgeeks.org/problems/count-triplets-with-sum-smaller-than-x5549/1
	//*********************************/
	int N = 4;
	int sum = 2;
	long long arr[] = { -2, 0, 1, 3};
	cout << countTriplets(arr, N, sum);

}