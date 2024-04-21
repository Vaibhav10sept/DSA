#include <bits/stdc++.h>
using namespace std;

int minCharsforPalindrome(string str) {
	//NOTE: iska solution mil gya tha code studio me jaha ka link dia h neeche, vhi code copy kia, pr jyada kuch smjh ni aya
	//we need to meorize few part of this code
	int n = str.size();
	int i = 0;
	int j = n - 1;
	int e2 = n - 1;
	int count = 0;
	while (i < j) {
		if (str[i] == str[j]) {
			i++;
			j--;
		}
		else { //str[i] != str[j]
			count++;
			i = 0;
			e2--;
			j = e2;
		}
	}
	return count;
}

int main()
{
	/*
	VIDEO: https://www.youtube.com/watch?v=zL0O6Q6kEAQ
	QUESTION: https://www.codingninjas.com/codestudio/problems/893000?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0
	//NOTE: iska solution mil gya tha code studio me jaha ka link dia h neeche, vhi code copy kia, pr jyada kuch smjh ni aya
	//we need to meorize few part of this code
	*/
	string str = "abb";
	cout << minCharsforPalindrome(str);
}