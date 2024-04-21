#include <bits/stdc++.h>
using namespace std;

int compareVersionNumber(string version1, string version2) {
	//THIS CODE IS WRITTEN AND LOGIC CREATED BY ME
	int i = 0;
	int j = 0;
	while (i < version1.size() and j < version2.size()) {
		string rev1 = "";
		string rev2 = "";
		bool foundAtFirst = true;
		while (i < version1.size() and version1[i] != '.') {
			if (foundAtFirst and version1[i] == '0') {
				i++;
				continue;
			}
			else {
				foundAtFirst = false;
				rev1 += version1[i];
			}
			i++;
		}
		//now i is at '.', so do i++;
		i++;
		cout << "rev1 " << rev1 << endl;


		foundAtFirst = true;
		while (j < version2.size() and version2[j] != '.') {
			if (foundAtFirst and version2[j] == '0') {
				j++;
				continue;
			}
			else {
				foundAtFirst = false;
				rev2 += version2[j];
			}
			j++;
		}
		//now j is at '.', so do j++;
		j++;
		cout << "rev2 " << rev2 << endl;


		//check for rev1 and rev2
		if (stoi(rev1 == "" ? "0" : rev1) > stoi(rev2 == "" ? "0" : rev2)) {
			return 1;
		}
		else if (stoi(rev2 == "" ? "0" : rev2) > stoi(rev1 == "" ? "0" : rev1)) {
			return -1;
		}
		else { //rev1 == rev2
			if (i >= version1.size() and j >= version2.size()) {
				return 0;
			}
		}

	}

	//now either i or j koi to out of bound hua hoga
	while (i < version1.size()) {
		string rev1 = "";
		bool foundAtFirst = true;
		while (i < version1.size() and version1[i] != '.') {
			if (foundAtFirst and version1[i] == '0') {
				i++;
				continue;
			}
			else {
				foundAtFirst = false;
				rev1 += version1[i];
			}
			i++;
		}
		i++;
		if (rev1 != "") return 1; //means version 1 > version 2
	}
	while (j < version2.size()) {
		string rev2 = "";
		bool foundAtFirst = true;
		while (j < version2.size() and version2[j] != '.') {
			if (foundAtFirst and version2[j] == '0') {
				j++;
				continue;
			}
			else {
				foundAtFirst = false;
				rev2 += version2[j];
			}
			j++;
		}
		j++;
		if (rev2 != "") return -1; //means version 2 > version 1
	}

	return 0;
}

int main()
{
	/*
	//THIS CODE IS WRITTEN BY ME
	VIDEO: NO NEED FOR VIDEO WRITTEN AND LOGIC IS BY ME.
	QUESTION: https://leetcode.com/problems/compare-version-numbers/description/
	*/

	// string version1 = "1.0.1";
	// string version2 = "1";

	string version1 = "1.0";
	string version2 = "1.0.0";


	cout << compareVersionNumber(version1, version2);
}