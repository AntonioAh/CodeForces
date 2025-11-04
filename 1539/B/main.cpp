#include <iostream>
#include <string>
#include <vector>



using namespace std;


int main(){
  ios_base::sync_with_stdio(false);
  
  int n, q;
  cin >> n >> q;

  string song;
  cin >> song;
  
  vector<int> prefSum(n+1);
  prefSum[0] = 0;
  for (int i = 0; i < n; i++){
    prefSum[i + 1] = prefSum[i] + (song[i] - 'a' + 1);
  }

  for (int i = 0; i < q; i++){
    int l, r;
    cin >> l >> r;

    cout << prefSum[r] - prefSum[l-1] << "\n";
  }

  
}