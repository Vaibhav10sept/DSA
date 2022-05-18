#include <bits/stdc++.h>
using namespace std;


class MovingAverage {
public:
	int avgSize;
	double sum;
	deque<int> dq;
	MovingAverage(int size) {
		avgSize = size;
		sum = 0;
	}

	double next(int val) { //this will return avg of size(given)
		sum += val;
		dq.push_back(val);
		if (dq.size() > avgSize) {
			sum -= dq.front();
			dq.pop_front();
		}
		return sum / dq.size();
	}
};

int main()
{
	/*
	VIDEO LINK: https://www.youtube.com/watch?v=nJ-8tw41NwM&list=PL-Jc9J83PIiE1_SifBEWRsD-fzxrvkja9&index=35
	LEETCODE LINK: https://www.pepcoding.com/resources/data-structures-and-algorithms-in-java-levelup/stacks/moving-average-from-data-stream-official/ojquestion
	*/
	MovingAverage obj(3);
	cout << obj.next(1) << endl;
	cout << obj.next(10) << endl;
	cout << obj.next(3) << endl;
	cout << obj.next(5) << endl;
}