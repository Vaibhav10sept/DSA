#include<bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElement2(vector<int> arr) {
	int n = arr.size();
	stack<int> st;

	//pehle sare element ko stack me daal do, think
	//this step is different think, watch video
	for (int i = n - 1; i >= 0; i--) {
		//NOTE: if you remove the below while loop then also it will submit, think, try krle submit krke
		while (!st.empty() and st.top() <= arr[i]) st.pop();
		//yha hm ans ko calculate vala step nhi krre(think)
		st.push(arr[i]);
	}

	//ye step vaesa hi hoga jaese normal next greater ele me krte hai, bss upar vala for naya hai, remember this, watch video
	vector<int> ans(n);
	for (int i = n - 1; i >= 0; i--) {
		while (!st.empty() and st.top() <= arr[i]) st.pop();
		if (st.empty()) ans[i] = -1;
		else ans[i] = st.top();
		st.push(arr[i]); `
	}
	return ans;
}

int main() {
	/*
	PREREQUISITE: next greater element to the right
	VIDEO LINK: https://www.youtube.com/watch?v=RkG94TvnUFs&list=PL-Jc9J83PIiE1_SifBEWRsD-fzxrvkja9&index=5
	LEETCODE LINK: https://leetcode.com/problems/next-greater-element-ii/
	*/
	vector<int> nums1 = {1, 2, 1};
	vector<int> ans = nextGreaterElement2(nums1);
	cout << "res" << endl;
	for (auto ele : ans)cout << ele << " ";
}