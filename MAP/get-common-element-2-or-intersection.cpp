#include<bits/stdc++.h>
using namespace std;

void getCommonElement2(vector<int> arr1, vector<int> arr2) {
	map<int, int> mp;
	for (auto ele : arr1) {
		mp[ele]++;
	}
	// for (auto ele : mp) cout << ele.first << ele.second << endl;

	for (auto ele : arr2) {
		if (mp[ele] > 0) {
			mp[ele]--;
			cout << ele << " ";
		}

	}
}

int main() {
	//video link: https://www.youtube.com/watch?v=hBX47E5WDIA&list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk&index=461
	//NOTE: THIS IS INTERSECTION OF TWO ARRAY
	vector<int> arr1 = {1, 1, 2, 2, 1, 2, 5, 3};
	vector<int> arr2 = {1, 2, 1, 1, 2, 5, 4, 6};
	getCommonElement2(arr1, arr2);
}