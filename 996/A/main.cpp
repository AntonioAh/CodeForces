#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;
int main(){
  ios_base::sync_with_stdio(false);

  int n; cin >> n;
  const vector<int> possible = {1, 5, 10, 20, 100};

  int res = 0;
  for (int i = 4; i >= 0; i--){
    res += (n / possible[i]);
    n %= possible[i];

  }
     
  cout << res << "\n";
}