#include<bits/stdc++.h>
using namespace std;

void sort012(vector<int> &arr) {
	int i = 0;
	int j = 0;
	int mid = arr.size() - 1;
	while (i <= mid) {
		if (arr[i] == 1) {
			i++;
		}
		else if (arr[i] == 0) {
			swap(arr[i], arr[j]);
			i++;
			j++;
		}
		else { //arr[i]==2
			swap(arr[i], arr[mid]);
			mid--;
		}
	}
}

int main() {
	//**************************************
	//VIDEO LINK: https://www.youtube.com/watch?v=MbV26HWqxrs&list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk&index=506
	//followed a similar logic as partition algo(used in quick sort)
	//*******************************************
	vector<int> arr = {0, 1, 0, 2, 2, 0, 2, 1, 2};
	sort012(arr);
	for (auto ele : arr) cout << ele << " ";
}

