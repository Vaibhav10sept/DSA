#include <bits/stdc++.h>
using namespace std;

int getSize(map<string, vector<string>> tree, string person, map<string, int> &result) {
	//this function is similar to calculating height of a tree(think, watch video)
	//base case
	if (tree.find(person) == tree.end()) { //not found
		result[person] = 0;
		return 1;
	}

	int size = 0;

	for (string emp : tree[person]) {
		//recursive calls
		int childSize = getSize(tree, emp, result);
		size += childSize;
	}

	result[person] = size;
	return size + 1;
}

void findCount(unordered_map<string, string> mp) {
	map<string, vector<string>> tree;
	string ceo = "";

	for (auto it : mp) {
		string manager = it.second;
		string employee = it.first;

		if (manager == employee) {
			ceo = manager;
		}
		else {
			tree[manager].push_back(employee);
		}
	}

	cout << "ans" << endl;

	map<string, int> result;
	getSize(tree, ceo, result);

	for (auto it : result) {
		cout << it.first << " " << it.second << endl;
	}
}

int main() {
	/*
	VIDEO LINK: https://www.youtube.com/watch?v=bit4Jn-ZoyQ&list=PL-Jc9J83PIiEp9DKNiaQyjuDeg3XSoVMR
	QUESTION LINK: https://www.geeksforgeeks.org/find-number-of-employees-under-every-manager/
	*/
	unordered_map<string, string> dataset;
	dataset["A"] = "C";
	dataset["B"] = "C";
	dataset["C"] = "F";
	dataset["D"] = "E";
	dataset["E"] = "F";
	dataset["F"] = "F";

	findCount(dataset);
}