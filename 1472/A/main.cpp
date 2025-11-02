#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool testcase(){
  int n; cin >> n;
  vector<int> vect(n);
  for (int i = 0; i < n; i++)
    cin >> vect[i];

  sort(vect.begin(), vect.end());
  int numOnes = lower_bound(vect.begin(), vect.end(), 2) - vect.begin();
  int numTwo = n - numOnes;

  int remainingTwos = numTwo % 2;
  int remainingOnes = numOnes - 2 * remainingTwos;

  if (remainingOnes < 0)
    return false;

  return remainingOnes % 2 == 0;
  
}

int main(){
  ios_base::sync_with_stdio(false);
  int t; cin >> t;
  for (int i = 0; i < t; i++){
    bool res = testcase();
    cout << (res ? "YES" : "NO") << "\n";
  }
}
