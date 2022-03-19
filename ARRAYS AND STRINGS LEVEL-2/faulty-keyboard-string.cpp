#include <bits/stdc++.h>
using namespace std;

bool faultyKeyboard(string name, string typed) {
	//edge case
	if (name.size() > typed.size()) return false;

	int i = 0;
	int j = 0;
	while (i < name.size() and j < typed.size()) {
		if (name[i] == typed[j]) {
			i++;
			j++;
		}
		else if (name[i - 1] == typed[j]) {
			j++;
		}
		else { // name[i-1] != typed[j]
			return false;
		}
	}

	//ab ham check krege ki while ka breakout "i" se hua ya "j" se
	// if "i" se while loop toota
	while (j < typed.size()) {
		if (typed[j] != name[i - 1]) return false;
		j++;
	}

	//if "j" se while loop toota means "i" bacha hua hai, return false(think)
	if (i < name.size()) return false;

	return true;
}

int main() {
	//*********************************
	// NOTE: two pointer approach is used here
	// https://www.youtube.com/watch?v=738Dy3D-q-E&list=PL-Jc9J83PIiE-TR27GB7V5TBLQRT5RnSl
	// QUESTION:
	// 1. Your friend is typing his name into a faulty keyboard.
	// 2. Sometimes, when typing a character 'c', the key might get long pressed, and the character will be typed 1 or more times.
	// 3. You examine the typed characters of the keyboard. Return 'True' if it is possible that it was your friends name, with some characters (possibly none) being long pressed.
	//*********************************

	string name = "shree";
	string typed = "sshhreeee";
	if (faultyKeyboard(name, typed)) {
		cout << "Yes, it is faulty keyboard" << endl;
	}
	else cout << "No" << endl;
}