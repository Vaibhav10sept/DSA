#include <bits/stdc++.h>
using namespace std;

int findKthLargest(vector<int>& arr, int k) {
 	priority_queue<int, vector<int>, greater<int>> pq; //min heap
 	for (int i = 0; i < arr.size(); i++) {
 		if(pq.size() == k) {
 			if(pq.top() < arr[i]) {
 				pq.pop();
 				pq.push(arr[i]);
 			}
 		}
 		else 
 			pq.push(arr[i]);
 	}

 	return pq.top();   
 }

 int main() {
/*
NOTE: i wrote it.
VIDEO LINK:	
QUESTION: https://leetcode.com/problems/kth-largest-element-in-an-array/description/
*/
 	int k = 1;
 	std::vector<int> arr = {12, 5, 787, 1, 23};
	cout<<findKthLargest(arr, k)<<endl;
 	
 }