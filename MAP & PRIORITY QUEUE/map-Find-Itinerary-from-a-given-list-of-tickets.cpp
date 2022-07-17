#include <bits/stdc++.h>
using namespace std;

void findRoute(map<string, string> mp) {
	//find konsi city source hai.
	map<string, bool> potentialSource;
	for (auto it : mp) {
		string src = it.first;
		string dest = it.second;

		potentialSource[dest] = false;
		if (potentialSource.find(src) == potentialSource.end()) { //not found
			potentialSource[src] = true;
		}
	}

	//potential source map se source dhundho
	string src = "";
	for (auto it : potentialSource) {
		if (it.second == true) {
			src = it.first;
		}
	}

	//src ko first mante hue using mp print krte jao
	while (mp.find(src) != mp.end()) {
		cout << src << "->";
		src = mp[src];
	}
	cout << src << ".";
}

int main() {
	/*
	VIDEO LINK: https://www.youtube.com/watch?v=4mi2rO4D_Xk&list=PL-Jc9J83PIiEp9DKNiaQyjuDeg3XSoVMR&index=3
	QUESTION LINK: https://www.geeksforgeeks.org/find-itinerary-from-a-given-list-of-tickets/
	*/
	map<string, string> dataSet;
	dataSet["Chennai"] = "Banglore";
	dataSet["Bombay"] = "Delhi";
	dataSet["Goa"] = "Chennai";
	dataSet["Delhi"] = "Goa";

	findRoute(dataSet);
}