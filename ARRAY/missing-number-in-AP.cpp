#include <bits/stdc++.h>
using namespace std;

int inSequence(int a, int b, int c) {
	// a--> start of AP
	// b--> number that we need to find
	// c--> common difference
	// NOTE: use pen paper, dont memorize anything, wv

	int x = b - a;
	if (c == 0) {
		if (x == 0) return 1; //a==b
		else return 0;
	}

	if (x / c < 0) {
		return 0;
	}
	else {
		if (x % c == 0) return 1;
		else return 0;
	}
}

int main()
{
	/*
	NOTE: easy question, dont memorize derive it, wv if required
	QUESTION: https://practice.geeksforgeeks.org/problems/arithmetic-number2815/1
	VIDEO: https://www.youtube.com/watch?v=pJdRJqcq-8M
	*/
	int a = 1; //start of AP
	int b = 2; //number that we need to find
	int c = 3; //common difference
	cout << inSequence(a, b, c);
}