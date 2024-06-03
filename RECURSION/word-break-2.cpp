#include <bits/stdc++.h>
using namespace std;

void recHelper(int idx, vector<string> ans, string& str, set<string>& st, vector<string> &res ) {
    if(idx == str.size()) {
        string fin = "";
        for(int i=0;i<ans.size();i++) {
            fin += ans[i];
            if(i == ans.size()-1) {

            }
            else {
                fin += " ";
            }
        }
        res.push_back(fin);
    }
    //BC over

    for(int i=idx; i<str.size(); i++) {
        string sub = str.substr(idx, i-idx+1);
        
        if(st.find(sub) != st.end()) { //found
            // ans += " " + sub;
            ans.push_back(sub);
            recHelper(i+1, ans, str, st, res);
            ans.pop_back();
        }
    }
}
vector<string> wordBreak2(string str, vector<string>& arr) {
    vector<string> res;
    set<string> st(arr.begin(), arr.end());
    vector<string> ans;
    recHelper(0, ans, str, st, res);
    return res;
}

int main()
{
	/*
	NOTE: my code, i wrote it, no video, no reading
	QUESTION: https://leetcode.com/problems/word-break-ii/
	*/
	vector<string> dictionary =  {"god", "is", "now", "no", "where", "here"};
	string str = "godisnowherenowhere";
	vector<string> ans = wordBreak2(str, dictionary);
	for(string str: ans) cout<<str<<endl;


}