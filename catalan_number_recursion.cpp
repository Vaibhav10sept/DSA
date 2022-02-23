// Catalan numbers are a sequence of natural numbers that occurs in
// many interesting counting problems like following.

// Count the number of expressions containing n pairs of parentheses
// which are correctly matched. For n = 3, possible expressions are
// ((())), ()(()), ()()(), (())(), (()()).
// Count the number of possible Binary Search Trees with n keys
// (See this)
// Count the number of full binary trees (A rooted binary tree
// is full if every vertex has either two children or no children) with n + 1 leaves.
// Given a number n, return the number of ways you can draw n
// chords in a circle with 2 x n points such that no 2 chords intersect.#include <bits/stdc++.h>
#include<bits/stdc++.h>
using namespace std;

int Catalan(int n) {
	//bc
	if (n <= 1)return 1;
	int res = 0;
	for (int i = 0; i <= n - 1; i++) {
		res += Catalan(i) * Catalan(n - i - 1);
	}
	return res;
}

int main() {
	for (int i = 0; i < 10; i++) {
		cout << Catalan(i) << " ";
	}
}