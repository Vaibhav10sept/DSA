
#include <bits/stdc++.h>
using namespace std;
// this code will print distinct permutations
// means it will handle the duplicacy in array
void rec(vector<int> &nums, vector<int> &ds, vector<vector<int>> &ans, bool visit[]) {

    if (ds.size() >= nums.size()) {

        ans.push_back(ds);
        return;
    }
    for (int i = 0; i < nums.size(); i++) {
        // If index is already visited
        if (visit[i])
            continue;
        // If the numebr is dupicate
        if (i > 0 and nums[i] == nums[i - 1]
                and !visit[i - 1])
            continue;

        ds.push_back(nums[i]);
        visit[i] = true;
        rec( nums, ds, ans, visit);
        // backtracking...
        ds.pop_back();
        visit[i] = false;


    }
}

void permute(vector<int>& nums) {
    vector<vector<int>> ans;
    vector<int> ds;
    bool visit[nums.size()];
    for (auto &i : visit) i = false;

    rec( nums, ds, ans, visit);
    for (auto i : ans) {
        for (auto f : i) cout << f << " ";
        cout << endl;
    }
}
int main() {
    vector<int> v = {1, 2, 2};
    permute(v);
}
