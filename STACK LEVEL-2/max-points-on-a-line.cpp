#include<bits/stdc++.h>
using namespace std;


int maxPointsInaLine(vector<vector<int>> arr) {
    //wv
    int n = arr.size();
    int maxLengthOfLine = 1;
    //NOTE: same slope vale points hi line bnate hai(think, yhi logic use hora pure question me)
    //FORMULA FOR FIND SLOPE WITH 2 POINTS: (y2-y1)/(x2-x1);
    // NOTE: iss formule me denominator kbhi zero nhi hona chahie mtlb agr x1 == x2 hai to hme alg se handle krna hoga

    for (int i = 0; i < n; i++) {
        map<float, int> mp; //slope -> count
        for (int j = i + 1; j < n; j++) {
            vector<int> point1 = arr[i];
            vector<int> point2 = arr[j];
            float slope;
            if (point1[0] - point2[0] == 0) {
                // NOTE: iss formule me denominator kbhi zero nhi hona chahie mtlb agr x1 == x2 hai to hme alg se handle krna hoga
                slope = INT_MIN;
                cout << "her" << endl;
            }
            else {
                slope = float(point2[1] - point1[1]) / float(point2[0] - point1[0]);
            }
            // cout << "slope " << slope << endl;

            mp[slope]++;
            maxLengthOfLine = max(maxLengthOfLine, mp[slope] + 1);
        }
    }
    return maxLengthOfLine;
}





int main() {
    /*
    VIDEO: https://www.youtube.com/watch?v=Bb9lOXUOnFw&t=6s
    LEETCODE: https://leetcode.com/problems/max-points-on-a-line/description/
    */
    vector<vector<int>> points = {{0, 0}, {4, 5}, {7, 8}, {8, 9}, {5, 6}, {3, 4}, {1, 1}};
    cout << maxPointsInaLine(points);
}