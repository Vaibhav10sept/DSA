#include <bits/stdc++.h>
using namespace std;

void smallestSubarrayWithHighestFrequencyeElement(vector<int> arr) {
	//WV recommended
	map<int, int> freqMap;	//value, freq
	map<int, int> startingPoint; //value, first seen in arr

	int highestFreq = 0;
	int startIdx = 0;
	int endIdx = 0;
	int len = endIdx - startIdx + 1;

	for (int i = 0; i < arr.size(); i++) {
		if (freqMap.find(arr[i]) != freqMap.end()) { // found
			freqMap[arr[i]]++;
		}
		else { //not found
			freqMap[arr[i]]++;
			startingPoint[arr[i]] = i;
		}

		if (freqMap[arr[i]] > highestFreq) {
			startIdx = startingPoint[arr[i]];
			endIdx = i;
			len = endIdx - startIdx + 1;
			highestFreq = freqMap[arr[i]];
		}
		else if (freqMap[arr[i]] == highestFreq) {
			int newLength = i - startingPoint[arr[i]] + 1;
			if (newLength < len) {
				startIdx = startingPoint[arr[i]];
				endIdx = i;
				len = endIdx - startIdx + 1;
			}
		}
	}

	for (int i = startIdx; i <= endIdx ; i++) cout << arr[i] << " ";
}

int main() {
	/*
	NOTE: Smallest subarray with all occurrences of a most frequent element
	VIDEO LINK: https://www.youtube.com/watch?v=KMDQ1jDZ5i8&list=PL-Jc9J83PIiEp9DKNiaQyjuDeg3XSoVMR&index=41
	QUESTION LINK: https://www.geeksforgeeks.org/smallest-subarray-with-all-occurrences-of-a-most-frequent-element/#:~:text=Examples%3A,two%20times%2C%201%20and%202.
	*/
	vector<int> arr = {4, 1, 1, 2, 2, 1, 3, 3};
	smallestSubarrayWithHighestFrequencyeElement(arr);
}