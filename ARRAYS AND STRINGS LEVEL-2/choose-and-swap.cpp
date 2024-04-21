#include <bits/stdc++.h>
using namespace std;

string chooseandswap(string a) {
	// NOTE: my code, not copied from video
	char fir;
	char sec;

	int i = 0;

	bool flag = false;
	vector<bool> visited(26, false);
	while (i < a.size() - 1) {
		char ch = a[i];
		char smallest = ch;
		for (int j = i + 1; j < a.size(); j++) {
			if (a[j] < smallest and visited[a[j] - 'a'] == false) {
				smallest = a[j];
				flag = true;
			}
		}

		visited[ch - 'a'] = true;

		if (flag == true) {
			fir = smallest;
			sec = ch;
			break;
		}
		i++;
	}

	if (flag == false) return a;

	for (int i = 0; i < a.size(); i++) {
		char ch = a[i];
		if (ch == fir) {
			a[i] = sec;
		}
		else if (ch == sec) {
			a[i] = fir;
		}
	}

	return a;
}

int main() {
	/*********************************
	NOTE: my code, not copied from video
	// VIDEO LINK: https://www.youtube.com/watch?v=NhnsINajZRA
	// QUESTION: https://practice.geeksforgeeks.org/problems/choose-and-swap0531/1
	//*********************************/
	string A = "abba";
	cout << chooseandswap(A);
}