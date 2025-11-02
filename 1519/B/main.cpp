#include <iostream>
#include <vector>

using namespace std;

void testcase(){
  int n, m, k;
  cin >> n >> m >> k;

  // vector<vector<vector<bool>>> grid(n+1, vector<vector<bool>>(m+1, vector<bool>(k+1, false)));
  // grid[1][1][0] = true;

  // for (int c = 0; c <= k; c++){
  //   for (int i = 1; i <= n; i++){
  //     for (int j = 1; j <= m ; j++){
      
  //       if (! grid[i][j][c])
  //         continue;

  //       //goes down
  //       if (c + j <= k && i+1 <= n)
  //         grid[i+1][j][c+j] = true;
        
  //       //goes right
  //       if (c + i <= k && j + 1 <= m)
  //         grid[i][j+1][c + i] = true;
  //     }
  //   }
  // }
  vector<vector<int>> grid(n+1, vector<int>(m+1));
  for (int i = 1; i <= n; i++){
    grid[i][1] = i - 1;
    for (int j = 2; j <= m; j++){
      grid[i][j] = grid[i][j-1] + i;
    }
  }
  cout << (grid[n][m] == k ? "YES" : "NO") << "\n";
}

int main(){
  ios_base::sync_with_stdio(false);
  int t; cin >> t;
  for (int i = 0; i < t; i++)
    testcase();
}