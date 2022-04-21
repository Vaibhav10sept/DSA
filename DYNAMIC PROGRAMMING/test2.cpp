#include <bits/stdc++.h>
using namespace std;

int test(vector<int> arr) {
	//create map
	unordered_map<int, int> mp;
	for (auto ele : arr) {
		mp[ele]++;
	}

	for (auto ele : mp) {
		cout << ele.first << "-> " << ele.second << endl;
	}
	cout << endl;

	int ans = 0;
	for (auto it : mp) {
		// if (it.second % 3 == 0) {
		// 	ans += it.second / 3;
		// 	it.second %= 3;
		// 	// cout << "3- " << it.first << " " << ans << endl;

		// }
		// else if (it.second % 2 == 0) {
		// 	ans += it.second / 2;
		// 	it.second %= 2;
		// 	// cout << "2- " << it.first << " " << ans << endl;

		// }

		while (it.second >= 3 ) {
			if (((it.second % 3) % 2 != 0) and (it.second % 3 != 0) ) {

				cout << "Brea " << " " << it.first << " " << it.second << endl;
				break;
			}
			ans += it.second / 3;
			it.second %= 3;
			// if (it.second % 2 == 0) break;
		}
		while (it.second >= 2) {
			ans += it.second / 2;
			it.second %= 2;
			// cout << "2- " << it.first << " " << ans << endl;
		}
		cout << "it.second " << it.second << endl;

		if (it.second != 0) {
			return -1;
		}
		// cout << "3 and 2- " << it.first << " cnt " << it.second << endl;
		// int tempAns = 0;
		// int temp = it.second;


		// tempAns += temp / 3;
		// temp %= 3;


		// // cout << tempAns << endl;

		// tempAns += temp / 2;
		// temp %= 2;
		// // cout << tempAns << endl;
		// if (temp == 0) {
		// 	ans += tempAns;

		// }
		// else {
		// 	return -1;
		// }


	}
	return ans;
}

int main()
{
	//***************************
	// video link: https://www.youtube.com/watch?v=l_nR5X9VmaI&list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk&index=479
	//**************************************************
	// vector<int> tasks = {2, 2, 3, 3, 2, 4, 4, 4, 4, 4};
	// vector<int> tasks = {2, 3, 3};
	// vector<int> tasks = {69, 65, 62, 64, 70, 68, 69, 67, 60, 65, 69, 62, 65, 65, 61, 66, 68, 61, 65, 63, 60, 66, 68, 66, 67, 65, 63, 65, 70, 69, 70, 62, 68, 70, 60, 68, 65, 61, 64, 65, 63, 62, 62, 62, 67, 62, 62, 61, 66, 69};
	vector<int> tasks = {66, 66, 63, 61, 63, 63, 64, 66, 66, 65, 66, 65, 61, 67, 68, 66, 62, 67, 61, 64, 66, 60, 69, 66, 65, 68, 63, 60, 67, 62, 68, 60, 66, 64, 60, 60, 60, 62, 66, 64, 63, 65, 60, 69, 63, 68, 68, 69, 68, 61};
	cout << "ans " << test(tasks);
}
