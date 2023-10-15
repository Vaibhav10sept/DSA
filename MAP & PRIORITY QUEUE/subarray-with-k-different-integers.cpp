#include<bits/stdc++.h>
using namespace std;

void removeInMap(map<int, int> &mp, int ch) {
	if (mp[ch] == 1) mp.erase(ch);
	else mp[ch]--;
}

int solutionForK1(vector<int> arr) {
	int ans = 0;
	map<int, int> mp;
	int i = 0;
	int j = 0;
	while (true) {
		//ye flags hme above while se bahar nikalne me help krege
		bool f1 = false;
		bool f2 = false;

		// acquire
		cout << "I " << i << " " << arr.size() << endl;
		while (i < (int)arr.size()) {
			cout << "her " << i << endl;
			f1 = true;

			mp[arr[i]]++;

			if (mp.size() > 1) {
				removeInMap(mp, arr[i]);

				break;
			}
			i++;
		}

		// release
		while (j < i) {
			f2 = true;
			if (mp.size() == 1) {
				cout << "ans " << i << " " << j << endl;
				ans += i - j;
			}

			removeInMap(mp, arr[j]);
			j++;
			if (mp.size() < 1) break;
		}

		if (f1 == false and f2 == false) break;
	}
	return ans;
}

int CountSubstringswithKDistinctCharacters(vector<int> arr, int k) {
	//wv recommended
	//edge case
	if (k == 1) {
		return solutionForK1(arr);
	}
	int n = arr.size();
	int countOfSubstrings = 0;

	map<int, int> bada;
	map<int, int> chota;
	int iBada = 0;
	int iChota = 0;
	int j = 0;

	//LOGIC: chote map ka size k-1 hona chahie or bade map ka size k hona chahie(think)
	while (true) {
		//ye flags hme above while se bahar nikalne me help krege
		bool f1 = false;
		bool f2 = false;
		bool f3 = false;

		//bada acquire krega for size == k
		while (iBada < n) {
			f1 = true;

			bada[arr[iBada]]++;

			if (bada.size() > k) {
				removeInMap(bada, arr[iBada]);
				break;
			}
			iBada++;
		}

		while (iChota < iBada) {
			f2 = true;
			chota[arr[iChota]]++;

			if (chota.size() == k) { //chote map ka size k-1 hona chahie
				removeInMap(chota, arr[iChota]);
				break;
			}
			iChota++;
		}

		//here, chote ka size k-1 hoga or bade ka size k hoga.
		while (j < iChota) {
			f3 = true;
			if (bada.size() == k and chota.size() == k - 1) {
				countOfSubstrings += iBada - iChota;
			}

			removeInMap(chota, arr[j]);
			removeInMap(bada, arr[j]);
			j++;

			if (chota.size() < k - 1 or bada.size() < k) break;
		}

		if (f1 == false and f2 == false and f3 == false) break;
	}
	return countOfSubstrings;
}
int main() {
	/*
	SAME QUESTION: map count substring with k distinct characters.
	NOTE: this is pepcoding video(below link) code with some modification of my own
	LINK: https://leetcode.com/problems/subarrays-with-k-different-integers/
	VIDEO LINK: https://www.youtube.com/watch?v=CBSeilNvZHs&list=PL-Jc9J83PIiEp9DKNiaQyjuDeg3XSoVMR&index=14
	*/
	vector<int> arr = {1, 2, 1, 3, 4};
	int k = 3;
	cout << "ans " << CountSubstringswithKDistinctCharacters(arr, k);
}