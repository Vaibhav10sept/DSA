
#include <bits/stdc++.h>
using namespace std;

vector<int> distinctElementsInEveryWindowOfSizeK(vector<int> arr, int k) {
	//sliding window concept is used here.
	map<int, int> mp; //element, frequency
	int i = 0;
	int j = 0;
	vector<int> ans;

	while (j < arr.size()) {
		mp[arr[j]]++;

		if (j - i + 1 == k) { //window size hit.
			ans.push_back(mp.size());

			//increment i;
			if (mp.find(arr[i]) != mp.end()) { //arr[i] found
				mp[arr[i]]--;
				if (mp[arr[i]] == 0) mp.erase(arr[i]);
				i++;
			}
			else {
				i++;
			}
		}
		j++;
	}
	return ans;
}

int main() {
	/*
	PREREQUISITE: sliding window concept, refer to sliding window folder(aditya verma)
	VIDEO LINK: https://www.youtube.com/watch?v=x8O9XocEioI&list=PL-Jc9J83PIiEp9DKNiaQyjuDeg3XSoVMR&index=5
	QUESTION LINK:
	*/
	// vector<int> arr = {1, 2, 3, 4, 5, 10, 6, 7, 8, 9};
	// int k = 5;

	vector<int> arr = {1, 2, 1, 3, 4, 2, 3};
	int k = 4;
	vector<int> ans = distinctElementsInEveryWindowOfSizeK(arr, k);
	cout << "ans" << endl;
	for (auto ele : ans)cout << ele << " ";
}