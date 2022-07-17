#include <bits/stdc++.h>
using namespace std;

class Util {
public:
	int height;
	int xCoordinate;
	Util(int height, int xCoordinate) {
		this->height = height;
		this->xCoordinate = xCoordinate;
	}
};

struct comparator
{
	inline bool operator() (const Util& obj1, const Util& obj2)
	{
		if (obj1.xCoordinate == obj2.xCoordinate) { //if xcoordinate is same then sort in inc order of height
			return obj1.height < obj2.height;
		}
		//sort in increasing order of x coordinates
		return obj1.xCoordinate < obj2.xCoordinate;
	}
};


vector<vector<int>> getSkyline(vector<vector<int>>& arr) {
	//WV, leetcode hard
	vector<Util> list;
	vector<vector<int>> ans;

	for (int i = 0; i < arr.size(); i++) {
		int startingPoint = arr[i][0];
		int endingPoint = arr[i][1];
		int height = arr[i][2];

		//segregate staring and ending points
		//NOTE: -ve height --> means that it is the starting point for that building
		//NOTE: +ve height --> means that it is the ending point for that building
		list.push_back(Util(-1 * height, startingPoint));
		list.push_back(Util(height, endingPoint));
	}

	sort(list.begin(), list.end(), comparator());
	set<int> pq; //max heap(default in cpp,java me opposite h)

	int currHeight = 0;
	pq.insert(0); //means 0 height push hue h pq me

	for (int i = 0; i < list.size(); i++) {
		int xCoordinate = list[i].xCoordinate;
		int height = list[i].height;
		// cout << "height " << height << endl;

		if (height < 0) {
			//NOTE: -ve height --> means that it is the starting point for that building
			//add in pq(but make the height positive)
			// cout << "height " << height << endl;
			pq.insert(-1 * height);
			cout << "insert " << endl;
			for (auto itr = pq.begin(); itr != pq.end(); itr++) {
				cout << *itr << " ";
			}
			cout << endl;
		}

		else {
			//NOTE: +ve height --> means that it is the ending point for that building
			//So, we need to find that height in pq and then remove it
			pq.erase(height);
			cout << "erase " << height << endl;
			for (auto itr = pq.begin(); itr != pq.end(); itr++) {
				cout << *itr << " ";
			}
			cout << endl;
		}

		if (currHeight != *--pq.end()) { //means height change hue h, pq ke end me max height hogi
			ans.push_back({xCoordinate, *--pq.end()});
			currHeight = *--pq.end();
		}
	}
	return ans;
}

int main() {
	/*
	NOTE: not submitting on leetcode, need to check
	PREREQUISITE:
	VIDEO LINK: https://www.youtube.com/watch?v=EPD3Or5xtNg&list=PL-Jc9J83PIiEp9DKNiaQyjuDeg3XSoVMR&index=54
	QUESTION LINK: https://leetcode.com/problems/encode-and-decode-tinyurl/
	*/
	// vector<vector<int>> buildings = {{2, 9, 10}, {3, 7, 15}, {5, 12, 12}, {15, 20, 10}, {19, 24, 8}};
	vector<vector<int>> buildings = {{0, 2, 3}, {2, 5, 3}};
	vector<vector<int>> ans = getSkyline(buildings);
	cout << "result" << endl;
	for (vector<int> vec : ans) {
		for (int ele : vec) cout << ele << " ";
		cout << endl;
	}
}