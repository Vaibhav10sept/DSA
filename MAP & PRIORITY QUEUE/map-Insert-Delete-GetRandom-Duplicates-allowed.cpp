#include <bits/stdc++.h>
using namespace std;

class RandomizedCollection {
public:
	map<int, set<int>> mp; //value, indexes in array(as dubplicates are there vo for one value(key) there can be more then one indexes)
	//and set<int> --> contains the index of values in arr.
	vector<int> arr;
	RandomizedSet() {

	}

	bool insert(int val) {
		bool flag;
		if (mp.find(val) != mp.end()) { //found
			//if already present return false
			flag = false;
		}
		else { //not found, return true;
			flag = true;
		}

		mp[val].insert(arr.size());
		arr.push_back(val);
		return flag;
	}

	bool remove(int val) {
		if (mp.find(val) == mp.end()) { //not found
			return false;
		}
		//present, so remove from set in map.
		int removeIdx = -1;
		for (auto it : mp[val]) { //iterating through set
			removeIdx = it;
			break;
		}
		mp[val].erase(removeIdx);

		//edge case
		if (mp[val].size() == 0) mp.erase(val);

		//remove from arr
		if (removeIdx == arr.size() - 1) { //last me h
			arr.pop_back();
			return true;
		}
		//last idx me nhi h to swap kroge last ele se fir last se remove kro
		//or jo last me tha uska idx change hue to use bhi map me update kro
		swap(arr[arr.size() - 1], arr[removeIdx]);
		//removing last index value
		arr.pop_back();
		//updating the set in map with the index change
		mp[arr[removeIdx]].erase(arr.size());
		mp[arr[removeIdx]].insert(removeIdx);
		return true;
	}

	int getRandom() {
		int randIndex = rand() % arr.size();
		return arr[randIndex];
	}
};


int main() {
	/*
	PREREQUISITE: Insert Delete GetRandom O(1)
	VIDEO LINK: https://www.youtube.com/watch?v=a-UYY_DvCBY&list=PL-Jc9J83PIiEp9DKNiaQyjuDeg3XSoVMR&index=58
	QUESTION LINK: https://leetcode.com/problems/insert-delete-getrandom-o1-duplicates-allowed/
	*/

	RandomizedCollection obj;
	cout << obj.insert(1) << endl;
	cout << obj.remove(1) << endl;
	cout << obj.insert(1) << endl;
}