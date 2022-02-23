#include<bits/stdc++.h>
using namespace std;

int countWays(string s1, string s2) {
  int m = s1.length();
  int n = s2.length();
  int dp[m + 1][n + 1] = {{0}};
  // for (int i = 0; i <= m; i++) {
  //   for (int j = 0; j <= n; j++) {
  //     cout << dp[i][j] << " ";
  //   }
  //   cout << endl;
  // }
  //initialization
  for (int j = 0; j < n + 1; j++) {
    dp[0][j] = 0;
  }
  for (int i = 0; i < m + 1; i++) {
    dp[i][0] = 1;
  }

  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      if (s1[i - 1] == s2[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
      } else {
        dp[i][j] = dp[i - 1][j];
      }
    }
  }
  return dp[m][n];
}
int main() {
  int ans = countWays("geeksforgeeks", "gks");
  cout << ans << endl;
}