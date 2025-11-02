#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);

  string str; cin >> str;
  vector<char> letters;
  for (char c : str){
    if (c == 'A' || c == 'Q')
      letters.push_back(c);
  }

  vector<int> vect(letters.size(), 0);
  int count = 0;
  const int n = letters.size();
  for (int i = 0; i < n; i++){
    if (letters[i] == 'A')
      vect[i] = count;
    else
      count++;
  }

  count = 0;
  int res = 0;
  for (int i = 0; i < n; i++){
    if (letters[i] == 'Q')
      res += count;
    else
      count += vect[i];
  }

  cout << res << "\n";
  

  
  
  
}