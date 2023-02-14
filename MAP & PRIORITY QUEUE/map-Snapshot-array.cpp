#include <bits/stdc++.h>
using namespace std;

class SnapshotArray {
public:
	int snapShotID;
	//NOTE: ye vector of map, array ki har value ke lie, snapshotID --> value ki mapping rhega(WV, think)
	vector<map<int, int>> mapVec; //vector of map(snapshotID --> value)

	SnapshotArray(int length) {
		snapShotID = 0;
		mapVec.resize(length);
	}

	void set(int index, int val) {
		mapVec[index][snapShotID] = val;
	}

	int snap() {
		snapShotID++;
		return snapShotID - 1;
	}

	int get(int index, int snap_id) {
		//crucial part nhi smjh aya to WV.
		while (snap_id >= 0 and mapVec[index].find(snap_id) == mapVec[index].end()) {
			//jb tk snap_id >= 0 and mapvec ke index me uss particaul snap_id nhi milti tb tk snap_id-- krte rho.
			snap_id--;
		}

		if (snap_id == -1)return 0;
		return mapVec[index][snap_id];
	}
};

int main() {
	/*
	PREREQUISITE:
	VIDEO LINK: https://www.youtube.com/watch?v=DOHvkZ7QpAM&list=PL-Jc9J83PIiEp9DKNiaQyjuDeg3XSoVMR&index=65
	QUESTION LINK: https://leetcode.com/problems/snapshot-array/
	*/
	SnapshotArray obj(3);
	obj.set(0, 5);
	cout << obj.snap() << endl;
	obj.set(0, 6);
	cout << obj.get(0, 0) << endl;
}