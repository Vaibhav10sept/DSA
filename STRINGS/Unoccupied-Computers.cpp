#include <bits/stdc++.h>
using namespace std;

int unoccupiedComputers(string str, int n) {
	//NOTE: I wrote it myself, no video, no reading
	set<char> notAllocated;
	set<char> set;

	int countOfCustomer = 0;
	for (int i = 0; i < str.size(); i++) {
		char ch = str[i];
		if (set.size() == n) {
			if (set.find(ch) == set.end()
			        and notAllocated.find(ch) == notAllocated.end()) { //not found in set
				cout << "ch " << ch << " " << i << endl;
				// cout << "rping" << endl;
				// for (auto it : set) cout << it << endl;
				countOfCustomer++;
				notAllocated.insert(ch);
				// set.insert(ch);
			}
			else { //found
				set.erase(ch);
			}
		}
		else {
			if (set.find(ch) != set.end()) { //found
				set.erase(ch);
				// cout << "erase " << ch << endl;
			}
			else {
				if (notAllocated.find(ch) != notAllocated.end()) notAllocated.erase(ch);
				else set.insert(ch);
			}
		}
	}
	return countOfCustomer;
}

int main() {
	/************************************
	//NOTE: I wrote it myself, no video, no reading
	 * QUESTION: https://practice.geeksforgeeks.org/problems/unoccupied-computers-1646661078/1?utm_source=geeksforgeeks&utm_medium=ml_article_practice_tab&utm_campaign=article_practice_tab
	// VIDEO LINK:
	//************************************/
	string str = "CFIJEADGCFHGEDBBIHJA";
	int n = 3;
	cout << "ans " << unoccupiedComputers(str, n);

}


