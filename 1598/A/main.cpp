#include <iostream>
#include <vector>

using namespace std;

void testcase(){
  int n; cin >> n;
  

  vector<vector<bool>> safe(2, vector<bool>(n, false));
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < n; j++){
      char car; cin >> car;
      safe[i][j] = car == '0';
    }

  vector<vector<bool>> reached(2, vector<bool>(n, false));
  reached[0][0] = true;
  for (int j = 0; j < n; j++){
    for (int i = 0; i < 2; i++){
      if (reached[i][j] == false)
        continue;

      if (safe[i][j] == false){
        reached[i][j] = false;
        continue;
      }

      if (i == 0)
        reached[1][j] = true;
      else
        reached[0][j] = true;

      if (j+1 < n){
        reached[i][j+1] = true;

        if (i == 0)
          reached[1][j+1] = true;
        else
          reached[0][j+1] = true;
      }  
    }
  }

  cout << (reached[1][n-1] ? "Yes" : "No") << "\n";
  
}

int main(){
  ios_base::sync_with_stdio(false);
  int t; cin >> t;  
  for (int i = 0; i < t; i++)
    testcase();
}