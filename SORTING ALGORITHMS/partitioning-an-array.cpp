#include<bits/stdc++.h>
using namespace std;

vector<int> partition(vector<int> &arr) {
	// 0 to j-1 -> <= pivot
	// j to i-1 -> > pivot
	// i to end -> unknown or yet to be traversed
	int i = 0;
	int j = 0;
	int pivot = arr[arr.size() - 1];
	while (i < arr.size()) {
		if (arr[i] > pivot) {
			i++;
		}
		else { //arr[i] < pivot
			swap(arr[i], arr[j]);
			i++;
			j++;
		}
	}


}

int main() {
	//**************************************
	// video link: https://www.youtube.com/watch?v=if40LxQ8_Xo&list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk&index=501
	// IMPORTANT: this partitioning algorithm work only if we select last index as
	// pivot element.
	// NOTE: here we are selecting arr[0] as pivot element
	// VARIOUS OTHER QUESTIONS BASED ON PARTITIONING:
	// 1. seperate array odd and even
	// 2. seperate array of 0 and 1
	// 3. seperate array of 0 and non zero
	//*******************************************
	vector<int> arr = {3, 5};
	partition(arr);
	for (auto ele : arr) cout << ele << " ";
}