#include <bits/stdc++.h>
using namespace std;

int tour(vector<int> petrol, vector<int> distance) {
	//NOTE: nice question, wv, think, smjh aa gya h

	int start = 0;
	int extraPetrol = 0;
	int requiredPetrol = 0;

	for (int i = 0; i < petrol.size(); i++) {
		extraPetrol += (petrol[i] - distance[i]);
		if (extraPetrol < 0) { //we cannot react next petrol pump
			start = i + 1;
			requiredPetrol += extraPetrol;
			extraPetrol = 0;
		}
	}

	if (requiredPetrol + extraPetrol >= 0) return start;
	return -1; //circular tour not possible
}

int main()
{
	/*
	NOTE: nice question, wv, think, smjh aa gya h
	QUESTION: https://practice.geeksforgeeks.org/problems/circular-tour-1587115620/1
	LEETCODE: https://leetcode.com/problems/gas-station/description/
	VIDEO: https://www.youtube.com/watch?v=7WYwqvOSaa8
	 */
	vector<int> petrol = {4, 6, 7, 4};
	vector<int> distance = {6, 5, 3, 5};

	cout << tour(petrol, distance) << endl;
}

