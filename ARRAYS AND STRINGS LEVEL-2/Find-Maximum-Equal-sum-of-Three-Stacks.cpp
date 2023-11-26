#include <bits/stdc++.h>
using namespace std;

int maxEqualSum(int n1, int n2, int n3, vector<int> &a1, vector<int> &a2, vector<int> &a3) {
	// * NOTE: I wrote it myself
	int i = 0;
	int j = 0;
	int k = 0;
	int s1 = 0;
	int s2 = 0;
	int s3 = 0;

	for (auto ele : a1) {
		s1 += ele;
	}
	for (auto ele : a2) {
		s2 += ele;
	}
	for (auto ele : a3) {
		s3 += ele;
	}
	if (s1 == s2 and s2 == s3) return s1;
	while (i < n1 and j < n2 and k < n3) {
		//which ever is highest reduce it
		if (s1 >= s2 and s1 >= s3) {
			s1 -= a1[i];
			i++;
		}
		else if (s2 >= s1 and s2 >= s3) {
			s2 -= a2[j];
			j++;
		}
		else if (s3 >= s1 and s3 >= s2) {
			s3 -= a3[k];
			k++;
		}



		if (s1 == s2 and s2 == s3) return s1;
// 		else if (s1 == 0 or s2 == 0 or s3 == 0 )return 0;
	}
	return 0;
}

int main() {
	/*********************************
	 * NOTE: I wrote it myself
	// VIDEO LINK: https://www.youtube.com/watch?v=hfA7y4XEAkw
	// QUESTION: https://practice.geeksforgeeks.org/problems/find-maximum-equal-sum-of-three-stacks/1?utm_source=geeksforgeeks&utm_medium=article_practice_tab&utm_campaign=article_practice_tab
	//*********************************/
	// int N1 = 3;
	// int N2 = 4;
	// int N3 = 2;
	// vector<int> S1 = {4, 2, 3};
	// vector<int> S2 = {1, 1, 2, 3};
	// vector<int> S3 = {1, 4};

	int N1 = 2;
	int N2 = 3;
	int N3 = 1;
	vector<int> S1 = {3, 4};
	vector<int> S2 = {1, 1, 5};
	vector<int> S3 = {7};  //7
	cout << maxEqualSum(N1, N2, N3, S1, S2, S3);
}