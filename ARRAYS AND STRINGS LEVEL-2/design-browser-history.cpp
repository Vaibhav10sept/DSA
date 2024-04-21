#include <bits/stdc++.h>
using namespace std;

class BrowserHistory {
public:
	stack<string> backStack;
	stack<string> forwardStack;
	BrowserHistory(string homepage) {
		backStack.push(homepage);
	}

	void visit(string url) {
		backStack.push(url);

		//clear all the forward history
		forwardStack = stack<string>();
	}

	string back(int steps) {
		if (backStack.empty()) return "";
		while (backStack.size() != 1 and steps > 0) {
			forwardStack.push(backStack.top());
			backStack.pop();
			steps--;
		}

		if (backStack.empty()) return "";
		return backStack.top();
	}

	string forward(int steps) {
		if (forwardStack.empty()) return backStack.top();
		while (forwardStack.size() != 1 and steps > 0) {
			backStack.push(forwardStack.top());
			forwardStack.pop();
			steps--;
		}

		if (backStack.empty()) return "";
		return backStack.top();
	}
};

int main() {
	/*********************************
	 * NOTE: we are using two stacks here.
	// VIDEO LINK: https://www.youtube.com/watch?v=FNcanLK6aZs&t=582s
	// QUESTION: https://leetcode.com/problems/design-browser-history/
	//*********************************/
	BrowserHistory obj("leetcode");
	obj.visit("google");
	obj.visit("facebook");
	obj.visit("youtube");
	cout << obj.back(1) << endl;
	cout << obj.back(1) << endl;
	cout << obj.forward(1) << endl;
	obj.visit("linkedin");
	cout << obj.forward(2) << endl;
	cout << obj.back(2) << endl;
	cout << obj.back(7) << endl;
}