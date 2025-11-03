#include <iostream>
#include <vector>
#include <tuple>

using namespace std;


int main(){
  ios_base::sync_with_stdio(false);
  int n; cin >> n;

  vector<int> vect(n+1);
  vect[1] = 1;
  vect[2] = 5;  

  for (int i = 3; i <= n; i++){
    vect[i] = vect[i-1] + 4;
    vect[i] += (i-2) * 4;
  }

  cout << vect[n] << "\n";

  

}