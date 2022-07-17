#include <bits/stdc++.h>
using namespace std;

int longestSubarraywithEqual0s1sand2s(vector<int> arr) {
	//WV recommended
	int maxLen = 0;
	map<string, int> mp; //string(key), index
	int countZeros = 0;
	int countOnes = 0;
	int countTwos = 0;
	int delta10 = countOnes - countZeros;
	int delta21 = countTwos - countOnes;
	string key = delta21 + "#" + delta10;

	mp[key] = -1; //-1 is the index, works as a base case(think)
	for (int i = 0; i < arr.size(); i++) {
		if (arr[i] == 0) {
			countZeros++;
		}
		else if (arr[i] == 1) {
			countOnes++;
		}
		else  { //arr[i]==2
			countTwos++;
		}

		delta10 = countOnes - countZeros;
		delta21 = countTwos - countOnes;
		key = delta21 + "#" + delta10;

		if (mp.find(key) != mp.end()) { //found
			//means, we found the subarray which has same no of 0,1 and 2
			int idx = mp[key];
			maxLen = max(maxLen, i - idx);
		}
		else { //not found
			mp[key] = i;
		}
	}
	return maxLen;
}

int main() {
	/*
	PREREQUISITE:
	VIDEO LINK: https://www.youtube.com/watch?v=MRoWBJvJeLQ&list=PL-Jc9J83PIiEp9DKNiaQyjuDeg3XSoVMR&index=34
	QUESTION:
	*/
	vector<int> arr = {0, 1 , 0 , 2 , 0 , 1, 0};
	cout << "ans " << longestSubarraywithEqual0s1sand2s(arr);
}