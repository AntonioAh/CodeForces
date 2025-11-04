#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void testcase(){
  int n; cin >> n;
  vector<int> A(n);

  for (int i = 0; i < n; i++)
    cin >> A[i];

  int maxElem = *max_element(A.begin(), A.end());

  vector<long long> counting(maxElem + 1, 0);
  for (int i = 0; i < n; i++)
    counting[A[i]]++;

  vector<long long> dp(maxElem + 1, 0);
  dp[0] = 0;
  dp[1] = counting[1];

  for (int i = 2; i < dp.size(); i++){

    if (dp[i-2] != -1)
      dp[i]= max(dp[i-1], dp[i-2] + i * counting[i]);
  }

  // for (int i = 0; i < dp.size(); i++)
  //   cout << i << " " << counting[i] << " " << dp[i] << " " << "\n";

  cout << dp.back() << "\n";


}

int main(){
  ios_base::sync_with_stdio(false);
  // for (int i = 0; i < t; i++)
    testcase();
}