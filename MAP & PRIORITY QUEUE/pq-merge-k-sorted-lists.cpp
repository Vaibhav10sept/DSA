#include <bits/stdc++.h>
using namespace std;

void displayMatrix(vector<vector<int>> arr) {
	for (int i = 0; i < arr.size(); i++) {
		for (int j = 0; j < arr[i].size(); j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}

class Util {
public:
	int li; // list index
	int di; // data index
	int val;

	Util(int li, int di, int val) : li(li), di(di), val(val)
	{
	}
};
// we are doing operator overloading through this, bcoz we are implement priority queue for "Util" class
bool operator<(const Util& p1, const Util& p2)
{
	return p1.val > p2.val; //min heap
}

vector<int> mergeKSortedLists(vector<vector<int>> arr) {
	priority_queue<Util> pq;  //min heap
	vector<int> ans;
	for (int i = 0; i < arr.size(); i++) {
		pq.push(Util(i, 0, arr[i][0]));
	}

	while (!pq.empty()) {
		Util temp = pq.top();
		pq.pop();
		ans.push_back(temp.val);

		if (temp.di < arr[temp.li].size() - 1) {
			temp.di++;
			temp.val = arr[temp.li][temp.di];
			pq.push(temp);
		}

	}

	return ans;

}

int main() {
	// https://www.youtube.com/watch?v=E5WSILx1q0Q&list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk&index=473
	// INPUT:
	// 4
	// 5
	// 10 20 30 40 50
	// 7
	// 5 7 9 11 19 55 57
	// 3
	// 1 2 3
	// 2
	// 32 39
	int n;
	cin >> n;
	// cout << n;
	int i = 0;
	vector<vector<int>> ques(n);
	while (i < n) {
		int m;
		cin >> m;
		// cout << m;
		vector<int> temp;
		for (int j = 0; j < m; j++) {
			int temp2;
			cin >> temp2;
			temp.push_back(temp2);
		}
		ques[i] = temp;
		i++;
	}

	vector<int> ans = mergeKSortedLists(ques);
	for (auto ele : ans) cout << ele << " ";

}