#include<bits/stdc++.h>
using namespace std;

void removeInMap(map<char, int> &mp, char ch) {
	if (mp[ch] == 1) mp.erase(ch);
	else mp[ch]--;
}

int solutionForK1(string str) {
	int ans = 0;
	map<char, int> mp;
	int i = 0;
	int j = 0;
	while (true) {
		//ye flags hme above while se bahar nikalne me help krege
		bool f1 = false;
		bool f2 = false;

		// acquire
		while (i < (int)str.length()) {
			cout << "her " << i << endl;
			f1 = true;

			mp[str[i]]++;

			if (mp.size() > 1) {
				removeInMap(mp, str[i]);

				break;
			}
			i++;
		}

		// release
		while (j < i) {
			f2 = true;
			if (mp.size() == 1) {
				cout << "tes " << j << " " << i << endl;
				ans += i - j;
			}


			removeInMap(mp, str[j]);
			j++;
			if (mp.size() < 1) break;
		}

		if (f1 == false and f2 == false) break;
	}
	cout << "ans " << ans << endl;
	return ans;
}


int CountSubstringswithKDistinctCharacters(string str, int k) {
	//edge case
	if (k == 1) {
		return solutionForK1(str);
	}
	int n = str.size();
	int countOfSubstrings = 0;

	map<char, int> bada;
	map<char, int> chota;
	int iBada = -1;
	int iChota = -1;
	int j = -1;

	//LOGIC: chote map ka size k-1 hona chahie or bade map ka size k hona chahie(think)
	while (true) {
		//ye flags hme above while se bahar nikalne me help krege
		bool f1 = false;
		bool f2 = false;
		bool f3 = false;



		//bada acquire krega for size == k
		while (iBada < n - 1) {
			f1 = true;
			iBada++;
			bada[str[iBada]]++;

			if (bada.size() == k + 1) {
				removeInMap(bada, str[iBada]);
				iBada--;
				break;
			}
		}

		while (iChota < iBada) {
			f2 = true;
			iChota++;
			chota[str[iChota]]++;

			if (chota.size() == k) { //chote map ka size k-1 hona chahie
				removeInMap(chota, str[iChota]);
				iChota--;
				break;
			}
		}

		//here, chote ka size k-1 hoga or bade ka size k hoga.
		while (j < iChota) {
			f3 = true;
			if (bada.size() == k and chota.size() == k - 1) {
				countOfSubstrings += iBada - iChota;
			}

			j++;
			removeInMap(chota, str[j]);
			removeInMap(bada, str[j]);

			if (chota.size() < k - 1 or bada.size() < k) break;
		}

		if (f1 == false and f2 == false and f3 == false) break;
	}
	return countOfSubstrings;
}

int main() {
	/*
	SAME QUESTION: subarray with k different integers
	NOTE: this is pepcoding video(below link) code with some modification of my own
	VIDEO LINK: https://www.youtube.com/watch?v=CBSeilNvZHs&list=PL-Jc9J83PIiEp9DKNiaQyjuDeg3XSoVMR&index=14
	*/
	// string str = "abcabdabbcfa";
	string str = "ab";
	int k = 1;
	cout << "count " << CountSubstringswithKDistinctCharacters(str, k);
}