#include <bits/stdc++.h>
using namespace std;

void displayMatrix(vector<vector<string>> arr) {
	for (int i = 0; i < arr.size(); i++) {
		for (int j = 0; j < arr[i].size(); j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}

vector<vector<string>> groupAnagram(vector<string> arr) {
	map<map<char, int>, vector<string>> bigMap;
	vector<vector<string>> ans;

	for (string str : arr) {
		//create freq map for every str
		map<char, int> freqMap;
		for (int i = 0; i < str.size(); i++) {
			freqMap[str[i]]++;
		}

		//check if big map contain the freq map that we have just created.
		if (bigMap.find(freqMap) != bigMap.end()) { //found
			//found toh usi vector me ye str add kr do
			bigMap[freqMap].push_back(str);
		}
		else { //not found
			//create new vector<string> for this str, freq map add it to the bigmap.
			vector<string> list;
			list.push_back(str);
			bigMap[freqMap] = list;
		}
	}

	//iterating throught bigmap and adding each vector(value) to ans vector
	for (auto it : bigMap)  {
		ans.push_back(it.second);
	}
	return ans;
}

int main() {
	/*
	LEETCODE LINK: https://leetcode.com/problems/group-anagrams/
	VIDEO LINK: https://www.youtube.com/watch?v=NNBQik4phMI
	*/
	vector<string> arr = {"eat", "tea", "tan", "ate", "nat", "bat"};

	vector<vector<string>> ans = groupAnagram(arr);
	displayMatrix(ans);
}