#include <bits/stdc++.h>
using namespace std;


int maximumSumNonAdjacentElement(vector<int> arr) {
	//Please watch attached video(link) for more understanding.
	int exclude = 0;
	int include = arr[0];
	// exclude and include works as a DP storage for this question
	// exclude --> means for a particular index not ending at arr[i](exclude), non adjacent subsets till arr[i] ka max sum kitna hoga vo store kroge.
	// include --> means for a particular index must end at arr[i](include), non adjacent subsets till arr[i] ka max sum kitna hoga vo store kroge.
	// exclude/include --> me max sum store hota h
	for (int i = 1; i < arr.size(); i++) {
		int tempInclude = include;
		include = exclude + arr[i];
		exclude = std::max(tempInclude, exclude);
	}

	return std::max(include, exclude);
}

int main()
{
	/***********************************************
	SIMILAR PROB: house robber
	SIMILAR PROB: ninja training
	NOTE: house robber is the use case of this question.
	video link: https://www.youtube.com/watch?v=VT4bZV24QNo&list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk&index=494
	SIMILAR: there is also a similar quest for recursion ie. max sum subset of non adjacent element
	recusion vale question me hm sare non adjacent subsets print krte h + max sum bhi nikalte h, or isme hm max sum print krte h non adjacent subset ka
	****************************************************/
	vector<int> arr = {5, 10, 10, 100, 5, 6};
	cout << "max sum is: " << maximumSumNonAdjacentElement(arr);
}