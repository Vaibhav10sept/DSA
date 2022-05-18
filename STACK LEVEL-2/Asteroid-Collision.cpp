#include<bits/stdc++.h>
using namespace std;

vector<int> asteroidsCollision(vector<int> arr) {
	//for logic watch video
	stack<int> st;
	for (auto ele : arr) {
		if (ele > 0) {
			st.push(ele);
		}
		else { //ele is negative
			//NOTE: ele is negative inside this else
			while (!st.empty() and st.top() > 0 and st.top() < abs(ele)) st.pop();
			//now, ab hme decede krna hai ki ele(which is negtive) ko stack me add kre ya nhi
			if (!st.empty() and st.top() == abs(ele)) {
				//ex: 8 --> top
				//   -8 --> ele
				//in this case we don't push ele(-8) in stack, else we push ele(-8)
				st.pop();
			}
			else if (!st.empty() and st.top() > abs(ele)) {
				//stack ke top me jo hai vo ele se bda hai to ele ko pop krdega, islie ele ko push na kro
			}
			else {
				st.push(ele);
			}
		}
	}

	//add ele from stack to ans array in the same order
	vector<int> ans(st.size());
	int i = ans.size() - 1;
	while (i >= 0) {
		ans[i--] = st.top();
		st.pop();
	}
	return ans;
}

int main() {
	/*
	PREREQUISITE:
	VIDEO LINK: https://www.youtube.com/watch?v=Y82zCeJft-Q&list=PL-Jc9J83PIiE1_SifBEWRsD-fzxrvkja9&index=17
	LEETCODE LINK:
	*/
	vector<int> arr = {5, 10, -5};
	vector<int> ans = asteroidsCollision(arr);
	for (int ele : ans)cout << ele << " ";
}