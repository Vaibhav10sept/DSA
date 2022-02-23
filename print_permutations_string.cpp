#include <bits/stdc++.h>
using namespace std;
void rec(string &str, string &ds, vector<string> &ans, bool visit[]) {

    if (ds.size() >= str.size()) {

        ans.push_back(ds);
        return;
    }
    for (int i = 0; i < str.size(); i++) {
        if (!visit[i]) {
            ds.push_back(str[i]);
            visit[i] = true;
            rec( str, ds, ans, visit);
            ds.pop_back();
            visit[i] = false;
        }

    }
}

void permute(string &str) {
    vector<string> ans;
    string  ds;
    bool visit[str.size()];
    for (auto &i : visit) i = false;

    rec( str, ds, ans, visit);
    for (auto i : ans) {
        for (auto f : i) cout << f << " ";
        cout << endl;
    }
}
int main() {
    string v = "abc";
    permute(v);
}
