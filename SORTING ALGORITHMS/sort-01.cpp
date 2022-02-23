#include<bits/stdc++.h>
using namespace std;

void sort01(vector<int> &arr) {
	int i = 0;
	int j = 0;
	while (i < arr.size()) {
		if (arr[i] == 1) {
			i++;
		}
		else { //arr[i] == 0
			swap(arr[i], arr[j]);
			i++;
			j++;
		}
	}
}

int main() {
	//**************************************
	//VIDEO LINK: https://www.youtube.com/watch?v=jFrUwjx4eoA&list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk&index=505
	//followed a similar logic as partition algo(used in quick sort)
	//*******************************************
	vector<int> arr = {0, 1, 0, 0, 0, 0, 1, 1, 1, 0};
	sort01(arr);
	for (auto ele : arr) cout << ele << " ";
}

