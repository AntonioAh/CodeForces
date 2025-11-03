#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void testcase(){
  int n, x;
  cin >> n >> x;

  vector<int> scores(n);
  for (int i = 0; i < n; i++)
    cin >> scores[i];

  sort(scores.begin(), scores.end());
  auto lower = lower_bound(scores.begin(), scores.end(), x);

  int count = scores.end() - lower;
  int fine = lower - scores.begin();

  int currentCount = 0, currMin;
  for (int i = fine-1;  i >= 0; i--){
    currentCount++;
    int s = scores[i] * currentCount;

    if (s >= x){
      count++;
      currentCount = 0;
    }
  }

  cout << count << "\n";
}

int main(){
  ios_base::sync_with_stdio(false);
  int t; cin >> t;

  for (int i = 0; i < t; i++)
    testcase();
}