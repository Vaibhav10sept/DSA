#include <bits/stdc++.h>
using namespace std;

int maxCandlesAllocatedToKChildren(vector<int> arr, int k) {
	//binary search is used here(WV recommended, good pattern of question)
	int sum = 0;
	for (int ele : arr) sum += ele;
	int left = 0;
	int right = sum / k; //max itni sub pile ho skti h(think)
	right++; //no idea
	int maxCandies  = 0;
	while (left < right) {
		int mid = (left + right) / 2; //mid --> mid size ki pile bnani h
		//kya mid size ki pile bnane pr hmare pass itni subpile bnegi ki "k" children ko di ja ske.
		//agr haan to right me jao or size of subpile(mid) ko inc kro jisse max candies mile children ko
		//agr naa to left me jao or size of subpile(mid) ko dec kyoki mid size ki inti subpile nhi bn rhi ki sare children ko mile to size(mid) km krne se syad mil jae.
		if (mid == 0) return 0; //edge case.
		int count = 0;
		for (int ele : arr) {
			count += ele / mid; //ele --> size of pile
			//mid --> size of subpile
			//ele/mid --> count of subpiles
		}

		//binary search vala schenario ki kidr jae
		if (count >= k) {
			//means "k" se jyada subpiles bn rhi h to right me jate h or mid ko inc krte h, kyoki hme mid(size of subpile) ko maximize krna h
			//move right
			maxCandies = max(maxCandies, mid);
			left = mid + 1;

		}
		else {//count < k, means subpiles nhi h itni ki "k" children ko mil ske, to left me jate h or mid(size of subpile) ko dec. krte h, jisse count inc hoga or "k" children ko subpiles mil paegi
			//move left
			right = mid; //why not, mid-1;

		}
	}
	return maxCandies;
}

int main() {
	//*********************************
	// NOTE: we used binary search approach here.
	// LEETCODE LINK: https://leetcode.com/problems/maximum-candies-allocated-to-k-children/
	// VIDEO LINK: https://www.youtube.com/watch?v=vSzibYJC1J0
	//*********************************
	vector<int> candies = {4, 7, 5};
	int k = 16; //1
	cout << maxCandlesAllocatedToKChildren(candies, k);
}