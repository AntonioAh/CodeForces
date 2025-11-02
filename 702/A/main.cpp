#include <iostream>
#include <vector>

using namespace std;
int main(){
  ios_base::sync_with_stdio(false);
  int n; cin >> n;
  vector<int> vect(n);

  int maxi = 1, currentCount = 1;
  int prev; cin >> prev;

  for (int i = 1; i < n; i++){
    int num; cin >> num;
    if (num > prev)
      currentCount++;
    else
      currentCount = 1;

    prev = num;
    maxi = max(maxi, currentCount);
  }

  cout << maxi << "\n";
}