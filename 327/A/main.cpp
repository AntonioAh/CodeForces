#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
  int n; cin >> n;
  vector<int> A(n);
  for (int i = 0; i < n; i++)
    cin >> A[i];

  //dp[i][j] indica quanti i ho nell'intervallo [i, j)
  vector<int> prefixSum(n+1, 0);
  for (int i = 0; i < n; i++){
    prefixSum[i+1] = prefixSum[i] + A[i];
    // cout << prefixSum[i+1] << " ";
  }
  // for (int i = 0; i <= n; i++)
  //   cout << i << " : " << prefixSum[i] << "\n";
  int maxOnes = 0;
  for (int i = 1; i <= n; i++){
    for (int j = i; j <= n; j++){
      int current = prefixSum[i-1] + (prefixSum[n] - prefixSum[j]);
      current += (j-i+1 - (prefixSum[j] - prefixSum[i-1]));


      // cout << i << " " << j << " :" << current << "\n";
      maxOnes = max(current, maxOnes);
    }
  }
  cout << maxOnes << "\n";
}

