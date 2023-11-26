#include<bits/stdc++.h>
using namespace std;

int rec(int state, int health, int armour, vector<vector<int>>& memo) {
	if (health <= 0 or armour <= 0) {
		return 0;
	}
	//BC ends
	if (memo[health][armour] != -1) return memo[health][armour];

	//all recursive calls
	// If you step into air, your health increases by 3 and your armor increases by 2
	// If you step into water, your health decreases by 5 and your armor decreases by 10
	// If you step into fire, your health decreases by 20 and your armor increases by 5

	if (state == 0) { //air
		int water = rec(1, health - 5, armour - 10, memo);
		int fire = rec(2, health - 20, armour + 5, memo);
		return memo[health][armour] = 1 + max(water, fire);
	}
	else if (state == 1) { //water
		int air = rec(0, health + 3, armour + 2, memo);
		int fire = rec(2, health - 20, armour + 5, memo);
		return memo[health][armour] = 1 + max(air, fire);

	}
	else { //fire
		int air = rec(0, health + 3, armour + 2, memo);
		int water = rec(1, health - 5, armour - 10, memo);
		return memo[health][armour] = 1 + max(air, water);
	}
}

int dieHard(int health, int armour) {
	///0 -> air
	///1 -> water
	///2 -> fire
	vector<vector<int>> memo(1001, vector<int>(1001, -1));
	int air = rec(0, health + 3, armour + 2, memo);
	int water = rec(1, health - 5, armour - 10, memo);
	int fire = rec(2, health - 20, armour + 5, memo);

	return max({air, water, fire});
}

int main() {
	//**************************************
	// NOTE: good qeustion nice logic
	// NOTE: this is memoized solution
	//VIDEO LINK:
	// QUESTION LINK: https://www.spoj.com/problems/DIEHARD/
	//*******************************************
	int health = 20;
	int armour = 8;
	// int health = 2;
	// int armour = 10;
	cout << dieHard(health, armour);
}

