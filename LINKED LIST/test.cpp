#include <bits/stdc++.h>
using namespace std;

string twoDecimal(string str) {
	size_t found = str.find('.');
	// if (found != string::npos)
	// cout << "First occurrence is " << found << endl;

	string ans = str.erase(found + 3);
	// cout << "ans " << ans << endl;
	return ans;
}

string discountapply(int discount, string val) {
	if (discount == 100) {
		return twoDecimal("0.0000");
	}
	float intval = (float)stoi(val);
	intval = intval * ( (float)discount / 100);
	cout << "in " << (float)discount / 100 << endl;
	float value = (int)(intval * 100 + .5);
	value = (float)value / 100;


	return twoDecimal(to_string(value));

}

string test(string str, int discount) {
	string dummy = str;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '$') {
			if (i > 0 and !isdigit(str[i - 1])) {
				string curr = "";
				int currSize = 0;
				i++;
				while (isdigit(str[i]) and i < str.size()) {
					curr += str[i];
					currSize++;
					i++;
				}
				if (str[i] == '$') continue;
				cout << "curr " << curr << " " << i  << " " << currSize << endl;
				string final = discountapply(discount, curr);
				str.replace(i - currSize, currSize , final);
				i = i - currSize;

			}
		}
	}
	return str;
}


int main()
{
	string sentence = "there are $1 $2 and 5$ candies in the shop";
	// string sentence = "1 2 $3 4 $5 $6 7 8$ $9 $10$";
	int discount = 100;
	cout << "answer: " << test(sentence, discount);
}