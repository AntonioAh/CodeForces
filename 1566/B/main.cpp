#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void testcase(){
  string s; cin >> s;
  vector<char> nuova;

  char prec = s[0];
  
  for (int i = 1; i < s.size(); i++){
    if (s[i] == prec)
      continue;
    
      nuova.push_back(prec);
      prec = s[i];
  }
  nuova.push_back(s.back());
  vector<int> v;
  for (char c : nuova){
    if (c == '0')
      v.push_back(1);
    else
      v.push_back(0);
  }

  int sum = 0;
  for (int i = 0; i < v.size(); i++)
    sum += v[i];

  cout << min(sum, 2) << "\n";
}

int main(){
  ios_base::sync_with_stdio(false);
  int t; cin >> t;
  for (int i = 0; i < t; i++)
    testcase();
}