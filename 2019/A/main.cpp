#include <iostream>
#include <vector>
#include <algorithm>
#include <array>

using namespace std;

void testcase(){
  int n; cin >> n;
  vector<int> A(n);

  for (int i = 0; i < n; i++)
    cin >> A[i];

  int ans = 0;
  for (int i = 0; i < n; i++){
    int num = A[i];
    
    vector<int> dp(n, 0);
    dp[i] = 1;
    if (i+1 < n)
      dp[i+1] = 1;

    for (int j = i+2; j < n; j++){
      dp[j] = dp[j-1];

      if (A[j] <= num){
        int take = dp[j - 2] + 1;
        dp[j] = max(dp[j], take);
      }
    }

    if (i > 0)
      dp[i-1] = 1;
    for (int j = i-2; j >= 0; j--){
      dp[j] = dp[j+1];

      if(A[j] <= num){
        int take = dp[j+2] + 1;
        dp[j] = max(dp[j], take);
      }
    }

    ans = max(ans, num + dp[n-1] + dp[0] - 1);
  }

  cout << ans << "\n";
}

int main(){
  ios_base::sync_with_stdio(false);
  int t; cin >> t;
  while(t--)
    testcase();
}