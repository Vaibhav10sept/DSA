#include <bits/stdc++.h>
using namespace std;

vector<int> sieveOfEratosthenes(int n) {
	vector<bool> isPrime(n + 1, true);

	for (int i = 2; i * i < isPrime.size(); i++) {
		if (isPrime[i] == true) {
			//making the multiples of i false(not prime)
			for (int j = i + i; j < isPrime.size(); j += i) {
				isPrime[j] = false;
			}
		}
	}

	vector<int> res;
	for (int i = 2; i < isPrime.size(); i++) {
		if (isPrime[i] == true) {
			res.push_back(i);
		}
	}
	return res;
}

void segmentedSieve(int low, int high) {
	//step:1
	vector<int> primes = sieveOfEratosthenes(sqrt(high));
	// for (auto ele : primes) cout << ele << " ";
	// cout << endl;
	//step:2
	vector<bool> isPrime(high - low + 1, true);
	//step:3(logic)
	for (auto prime : primes) {
		int firstMultiple = ((low / prime) * prime);
		if (firstMultiple < low) firstMultiple += prime;
		// cout << "first " << firstMultiple << " " << prime << endl;

		for (int i = max(firstMultiple, prime * prime); i <= high; i += prime) {
			// cout << "i low " << i - low << endl;
			isPrime[i - low] = false;
		}
	}
	// for (int i = 0; i < isPrime.size(); i++) {
	// 	if (isPrime[i]) {
	// 		cout << i + low << endl;
	// 	}
	// }
	//get all the primes using the already filled isPrime vector
	cout << "answer " << endl;
	// cout << "is prime" << endl;
	// for (auto ele : isPrime)cout << ele << " ";
	// cout << endl;
	for (int i = 0; i <= isPrime.size(); i++) {
		if (isPrime[i]) {
			cout << i + low  << endl;
		}
	}
}

int main() {
	//********************************
	//PREREQUISITE: "sieve of eratosthenes"
	// STEPS:
	// 1. find primes till sqrt(high) using before "SieveOfEratosthenes".
	// 2. create a dummy array of size high - low + 1.
	// 3. mark the dummy array's elements as not prime using the multiple of primes array
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