#include <bits/stdc++.h>
using namespace std;

void print(vector<int> arr) {
	for (auto ele : arr) cout << ele << " ";
	cout << endl;
}

bool isPrime(int val) {
	for (int div = 2; div * div <= val; div++) {
		if (val % div == 0) {
			return false;
		}
	}
	return true;
}

void removePrimFromArray(vector<int> &arr) {
	for (int i = arr.size() - 1; i >= 0; i--) {
		if (isPrime(arr[i])) {
			arr.erase(arr.begin() + i);
		}
	}
}

int main()
{
	//******************************************
	// VIDEO LINK: https://www.youtube.com/watch?v=jj90JZ_wLoo&list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk&index=546
	//******************************************
	vector<int> arr = {7, 18, 3, 14, 19, 31, 72};
	removePrimFromArray(arr);
	print(arr);
}