#include <bits/stdc++.h>
using namespace std;

void printAllPrimeInARange(int low, int high) {
	for (int i = low; i <= high; i++) {
		bool isPrime = true;

		for (int j = 2; j * j <= i; j++) {
			if (i % j == 0) {
				isPrime = false;
				break;
			}
		}

		if (isPrime) {
			cout << i << endl;
		}
	}
}

int main() {
	int low = 2;
	int high = 10;
	printAllPrimeInARange(low, high);
}