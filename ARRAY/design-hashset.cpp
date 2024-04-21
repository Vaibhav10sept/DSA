#include <bits/stdc++.h>
using namespace std;

class MyHashSet {
public:
	vector<bool> ans;
	MyHashSet() {
		ans.resize(1e6 + 1, false); //see the constraint in question
	}

	void add(int key) {
		ans[key] = true;
	}

	void remove(int key) {
		ans[key] = false;
	}

	bool contains(int key) {
		return ans[key];
	}
};

int main()
{
	/*
	NOTE: you cannot build or execute this code, paste it on leetcode to check
	NOTE: no video required, straight forward code hai
	LEETCODE: https://leetcode.com/problems/design-hashset/description/
	*/
	vector<int> arr = {1, 2, 3, 4, 5, 6};
	print(arr);
}