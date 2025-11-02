#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void testcase(){
  int n; cin >> n;
  int mini = 0, maxi = 0;
  vector<int> a(n);

  int primo, ultimo;
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }

  

  int minPos = min_element(a.begin(), a.end()) - a.begin() + 1; // 1-based index
  int maxPos = max_element(a.begin(), a.end()) - a.begin() + 1; // 1-based index

  // Case 1: remove only from left
  int leftOnly = max(minPos, maxPos);

  // Case 2: remove only from right
  int rightOnly = n - min(minPos, maxPos) + 1;

  // Case 3: remove from both sides
  int bothSides = min(minPos, maxPos) + (n - max(minPos, maxPos) + 1);

  cout << min({leftOnly, rightOnly, bothSides}) << '\n';
}

int main(){
  ios_base::sync_with_stdio(false);
  int t; cin >> t;
  for (int i = 0; i < t; i++)
    testcase();
}