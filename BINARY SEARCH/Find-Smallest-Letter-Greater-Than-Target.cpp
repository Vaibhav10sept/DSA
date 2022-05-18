#include<bits/stdc++.h>
using namespace std;

//this is finding ceil(logic, think)
char FindSmallestLetterGreaterThanTarget(vector<char> &arr, char k) {
	/*
	here, we are finding ceil(think)
	*/
	int ans = -1;
	int n = arr.size();
	int start = 0, end = n - 1, mid;
	while (start <= end)
	{
		mid = start + (end - start) / 2;
		if (arr[mid] > k) //isme = nhi lgana, coz agr vo k hai to bhi hame uska ceil hi return krna hai(given in question)
		{
			ans = mid; //bda hai toh is a valid candidate for ceil
			end = mid - 1; //left me jaege, coz we need smallest in greater
		}
		else
			start = mid + 1; //right me jaege
	}
	if (ans == -1)
		return arr[0]; //agr koi ceil nhi mila toh first char return krdo
	return arr[ans]; //else jo ceil mila use return kr do
}

int main() {
	/*
	PREREQUISITE: find Ceil of an element in sorted array
	VIDEO LINK: https://www.youtube.com/watch?v=X45c37QMdX0&list=PL_z_8CaSLPWeYfhtuKHj-9MpYb6XQJ_f2&index=12
	*/
	vector<char> arr =  {'c', 'f', 'j'};
	char k = 'c';
	cout << FindSmallestLetterGreaterThanTarget(arr, k) << endl;
}