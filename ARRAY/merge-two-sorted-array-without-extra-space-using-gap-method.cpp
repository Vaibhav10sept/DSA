#include <bits/stdc++.h>
using namespace std;

void print(vector<int> arr) {
	for (auto ele : arr) cout << ele << " ";
	cout << endl;
}

void mergeSortedArray(vector<int> &arr1, vector<int> &arr2) {
	//WV recommended
	//gap method is also used in shell sort
	//gap method - this is more of a theoritical approach for solving this question, refer to vidoe recommended
	int n = arr1.size();
	int m = arr2.size();
	int len = n + m;

	int gap = (len / 2) + (len % 2); //this way we get ceil value, don't use ceil func it is not working, IDK why
	int i = 0;
	int j = i + gap;

	while (gap > 0)
	{
		i = 0;
		j = i + gap;
		while (j < len)
		{
			//we need to figure out that i, j lie in which arr(think, WV)
			if (i < n and j < n) { //both in arr1

				if (arr1[i] > arr2[j]) {
					swap(arr1[i], arr2[j]);
				}
				i++; j++;
			}

			else if (i >= n and j >= n)
			{	//both in arr2
				if (arr2[i - n] > arr2[j - n])
				{
					swap(arr2[i - n], arr2[j - n]);

				}
				i++; j++;
			}

			else
			{	//i in arr1 and j in arr2
				if (arr1[i] > arr2[j - n])
				{
					swap(arr1[i], arr2[j - n]);
				}
				i++; j++;

			}
			cout << "ga " << gap << endl;
		}
		if (gap == 1) break;
		gap = (gap / 2) + (gap % 2);
	}
}

int main()
{
	/*
	NOTE: code not working
	NOTE: this solved using gap method, two other solutions are also there
	VIDEO LINK: https://www.youtube.com/watch?v=n7uwj04E0I4&list=PLgUwDviBIf0oF6QL8m22w1hIDC1vJ_BHz&index=39
	QUESTION LINK:
	*/
	vector<int> arr1 = { 1, 5, 9, 10, 15, 20 };
	vector<int> arr2 = { 2, 3, 8, 13 };
	print(arr1);
	print(arr2);
	cout << "after sorting" << endl;
	mergeSortedArray(arr1, arr2);
	print(arr1);
	print(arr2);
}