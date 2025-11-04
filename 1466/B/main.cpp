#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void testcase(){
  int n; cin >> n;

  vector<int> nums(n);
  for (int i = 0; i < n; i++)
    cin >> nums[i];

  int maxElem = *max_element(nums.begin(), nums.end());
  vector<int> counting(maxElem+2, 0);
  for (int i = 0; i < n; i++)
    counting[nums[i]] += 1;

  int res = 0;
  for (int i = 1; i <= maxElem; i++){
    if (counting[i] > 1){
      res++;
      counting[i] -= 1;
      counting[i+1] += 1;
    }
    else if (counting[i] == 1){
      res++;
    }
  }

  res += (counting[maxElem+1] > 0);

  cout << res << "\n";

}

int main(){
  ios_base::sync_with_stdio(false);
  int t; cin >> t;
  for (int i = 0; i < t; i++)
    testcase();
}