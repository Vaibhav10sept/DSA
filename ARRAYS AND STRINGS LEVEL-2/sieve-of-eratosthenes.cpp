#include <bits/stdc++.h>
using namespace std;

void seiveOfEratosthenes(int n) {
	vector<bool> isPrime(n + 1, true);

	for (int i = 2; i * i < isPrime.size(); i++) {
		if (isPrime[i] == true) {
			//making the multiples of i false(not prime)
			for (int j = i + i; j < isPrime.size(); j += i) {
				isPrime[j] = false;
			}
		}
	}

	//printing all the prime no using isPrime array.
	for (int i = 2; i < isPrime.size(); i++) {
		if (isPrime[i] == true) {
			cout << i << endl;
		}
	}
}

int main() {
	//********************************
	// PREREQUISITE: print-all-prime-no-in-a-range.
	// COMPLEXITY: n(log(log(n)))
	// VIDEO LINK: https://www.youtube.com/watch?v=MY0fXk-3BVQ
	// QUESTION:
	// 1. Given an Integer 'n'.
	// 2. Print all primes from 2 to 'n'.
	// 3. Portal is not forced you, but try to submit the problem in less than n.root(n) complexity.
	//*********************************
	int n = 10;
	seiveOfEratosthenes(n);
}