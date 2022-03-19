#include <bits/stdc++.h>
using namespace std;

void segmentedSieve(int low, int high) {
	int range = high - low + 1;
	vector<bool> isPrime(range, true);

	for (int i = 2; i * i < isPrime.size(); i++) {
		if (isPrime[i] == true) {
			//making the multiples of i false(not prime)
			int actualNumber = i + low;
			for (int j = actualNumber + actualNumber; j < isPrime.size(); j += actualNumber) {
				cout << "j " << j << endl;
				isPrime[j - actualNumber] = false;
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
	// PREREQUISITE: sieve-of-eratosthenes.
	// COMPLEXITY: n(log(log(n)))
	// VIDEO LINK: https://www.youtube.com/watch?v=htxM60E98Bk&list=PL-Jc9J83PIiE-TR27GB7V5TBLQRT5RnSl&index=20
	// QUESTION:
	// 1. Generate all primes between 'a'  and 'b'(both are included).
	// 2. Print every number in new line.
	// 3. Allowed time Complexity : O(nlog(log n)), where n = b - a.
	// 4. Allowed Space Complexity : O(n), where n = b -a;
	// Note : Please focus on constraints..
	//*********************************
	int low = 22;
	int high = 51;
	segmentedSieve(low, high);
}