#include <bits/stdc++.h>
using namespace std;

vector<int> topKFreqElement(vector<int> arr, int k) {
    unordered_map<int, int> map;
    for (int num : arr) {
        map[num]++;
    }

    vector<int> ans;
    // pair<first, second>: first is frequency,  second is number
    priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; //min heap
    for (auto it = map.begin(); it != map.end(); it++) {
        pq.push(make_pair(it->second, it->first));
        while (pq.size() > k) {
            pq.pop();
        }
    }

    //pq ki values ko ans array me add krdo
    while (!pq.empty()) {
        ans.push_back(pq.top().second);
        pq.pop();
    }
    return ans;
}

int main() {
    //*********************************
    // LEETCODE LINK: https://leetcode.com/problems/top-k-frequent-elements/
    // VIDEO LINK:
    //*********************************
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = 2;
    vector<int> ans = topKFreqElement(nums, k);
    for (auto ele : ans) cout << ele << " ";
}