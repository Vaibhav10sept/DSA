#include <bits/stdc++.h>
using namespace std;

string fractionToDecimal(int num, int den) {
	//WV recommended
	bool isNegative = false;
	int newNum = num;
	int newDen = den;
	if (num < 0 or den < 0) {
		isNegative = true;
		newNum = abs(num);
		newDen = abs(den);
	}
	if (num < 0 and den < 0) {
		//coz, dono - hai to ek doosre ko cancel kr dege
		isNegative = false;
	}

	string ans = "";
	long long quotent = newNum / newDen;
	long long rem = newNum % newDen;
	ans += to_string(abs(quotent));

	if (rem == 0) {
		if (isNegative and ans != "0") {
			ans.insert(0, "-");
		}
		return ans;
	}

	else { //rem != 0
		ans += "."; // decimal lga dia
		map<long long, long long> mp; //rem,position(index)
		// cout << "test " << ans << endl;
		while (rem != 0) {
			if (mp.find(rem) != mp.end()) { //found
				//means remainder repeat hua h, recurring decimal exist(WV). so add "(" at position(from map) and ")" at the end
				long long len = mp[rem];
				ans.insert(len, "(");
				ans += ")";
				break;
			}
			else { //not found
				mp[rem] = ans.size();
				rem *= 10; //decimal lga hai toh zero add krte h, jaese actual divide krte time krte h(WV)
				quotent = rem / newDen;
				rem = rem % newDen;
				ans += to_string(abs(quotent));
			}
		}
	}
	if (isNegative) {
		cout << "test " << ans << endl;
		ans.insert(0, "-");
	}
	return ans;
}

int main() {
	/*
	PREREQUISITE:
	VIDEO LINK: https://www.youtube.com/watch?v=2cRS9dNa780&list=PL-Jc9J83PIiEp9DKNiaQyjuDeg3XSoVMR&index=37
	QUESTION: https://leetcode.com/problems/fraction-to-recurring-decimal/
	*/

	int numerator = -22;
	int denominator = -2;
	cout << "ans " << fractionToDecimal(numerator, denominator);
}