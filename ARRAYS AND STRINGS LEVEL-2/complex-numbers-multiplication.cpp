#include <bits/stdc++.h>
using namespace std;

void complexNumberMultiplication(string n1, string n2) {
	//getting a and b
	int a = stoi(n1.substr(0, n1.find('+')));
	auto found = n1.find('+');
	oufnd++;
	int b = stoi(n1.substr(found));

	//getting c and d
	int c = stoi(n2.substr(0, n2.find('+')));
	found = n2.find('+');
	found++;
	int d = stoi(n2.substr(found));

	// FORMULA(REMEMBER): (a*c - d*b) --> real part
	// (a*d + b*c)i --> imaginary part

	// calculating real part:
	string ans = "";
	int real = a * c - d * b;
	ans += to_string(real);
	ans += "+";
	//calculating imaginary part
	int imaginary = a * d + b * c;
	ans += to_string(imaginary);
	ans += "i";

	cout << ans << endl;
}

int main() {
	//*********************************
	// VIDEO LINK: https://www.youtube.com/watch?v=6rqL05qqIJ0&list=PL-Jc9J83PIiE-TR27GB7V5TBLQRT5RnSl&index=30
	// FORMULA(REMEMBER): (a*c - d*b) --> real part
	// (a*d + b*c)i --> imaginary part

	// QUESTION:
	// 1. A complex number can be represented as a string on the form "Real + Imaginary i" where:
	//     1.1 Real is the real part and is an integer in the range [-100, 100].
	//     1.2 Imaginary is the imaginary part and is an integer in the range [-100, 100].
	//     1.3 i^2 == -1.
	// 2. Given two complex numbers num1 and num2 as strings, return a string of the complex number that represents their multiplications.
	//*********************************
	string	n1 = "1+1i";
	string n2 = "1+1i";
	complexNumberMultiplication(n1, n2);
}