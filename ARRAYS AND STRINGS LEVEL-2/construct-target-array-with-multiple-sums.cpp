// SKIPPED AS HARD

int main() {
	//*********************************
	// VIDEO LINK: https://www.youtube.com/watch?v=wVBMvVc5Na4&list=PL-Jc9J83PIiE-TR27GB7V5TBLQRT5RnSl&index=52
	// QUESTION:
	//*********************************
	int n = 3;
	int k = 9;
	vector<string> ans;

	printAllHappyStringOfN(n, "", ans);
	if (k > ans.size()) {
		cout << "" << endl;
	}
	else {
		cout << ans[--k] << endl;
	}
}