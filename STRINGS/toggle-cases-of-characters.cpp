#include <bits/stdc++.h>
using namespace std;

void toggleCasesOfCharacter(string &str) {
	cout << "A " << (int)'A' << endl;
	cout << "Z " << (int)'Z' << endl;
	cout << "a " << (int)'a' << endl;
	cout << "z " << (int)'z' << endl;

	for (char &ch : str) {
		if ((int)ch <= 90 and (int)ch >= 65) { // capital hai
			ch += 32;
		}
		else { // small hai
			ch -= 32;
		}
	}
}

int main()
{
	//******************************************
// A 65
// Z 90
// a 97
// z 122
	// VIDEO LINK: 	https://www.youtube.com/watch?v=VQnWqpHpKnE&list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk&index=547
	//******************************************
	string str = "pepCODinG";
	toggleCasesOfCharacter(str);
	cout << "result: " << str << endl;
}