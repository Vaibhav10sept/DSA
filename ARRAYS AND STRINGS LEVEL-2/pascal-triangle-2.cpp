#include <bits/stdc++.h>
using namespace std;

void pascalTriangle2(int i) {
	//*********FORMULA*************
	// don't memorize formula,calculate it
	// nCr * factor = nCr+1
	// after putting the ncr formula and solving for factor we get,
	// FACTOR = n-r/r+1
	// in terms of i and j
	// FACTOR = i-j/j+1
	// ncr = n!/(n-r)!*r!

	int val = 1;
	for (int j = 0; j <= i; j++) {
		cout << val << " ";
		val = val * (i - j) / (j + 1);
	}
}

int main() {
	//*********************************
	// PREREQUISITE: "print-pascal-triangle"
	// VIDEO LINK: https://www.youtube.com/watch?v=LgLcWJrfLmQ&list=PL-Jc9J83PIiE-TR27GB7V5TBLQRT5RnSl&index=44
	// QUESTION:
	//  1. Given an integer rowIndex, return the rowIndexth (0-indexed) row of the Pascal's triangle.
	// 2. In Pascal's triangle, each number is the sum of the two numbers directly above OR it is also a pattern which can be made from combination maths
	// 3. For More clearance, watch video till explanation of question.
	// eg.
	// row 0 -> 1
	// row 1 -> 1 1
	// row 2 -> 1 2 1
	// row 3 -> 1 3 3 1
	// row 4 -> 1 4 6 4 1
	//*********************************
	int n = 3;
	pascalTriangle2(n);

}