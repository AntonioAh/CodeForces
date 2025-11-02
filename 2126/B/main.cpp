#include <iostream>
#include <vector>

using namespace std;

void testcase(){
  int n, k;
  cin >> n >> k;
  vector<int> weather(n);
  for (int i = 0; i < n; i++)
    cin >> weather[i];

  int count = 0, interCount = 0;
  int i = 0;
  while (i < n){
    if (weather[i]){
      interCount = 0;
    }
    else{
      interCount++;
      if (interCount == k){
        interCount = 0;
        count++;
        i++;
      }
    }

    i++;
  }

    
  cout << count << "\n";
}

int main(){
  ios_base::sync_with_stdio(false);
  int t; cin >> t;
  for (int i = 0; i< t; i++)
    testcase();
}