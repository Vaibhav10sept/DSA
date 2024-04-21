#include <bits/stdc++.h>
using namespace std;

class MyHashMap {
public:
	vector<int>m; //declaring a vector to store elements

	MyHashMap() {
		int size = 1e6 + 1;
		m.resize(size, -1);

	}

	void put(int key, int value) {
		m[key] = value;
	}

	int get(int key) {
		return m[key];
	}

	void remove(int key) {
		m[key] = -1;
	}
};

int main()
{
	/*
	NOTE: you cannot build or execute this code, paste it on leetcode to check
	NOTE: no video required, straight forward code hai
	LEETCODE: https://leetcode.com/problems/design-hashmap/description/
	*/
	vector<int> arr = {1, 2, 3, 4, 5, 6};
	print(arr);
}