#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;
int main(){
  ios_base::sync_with_stdio(false);

  int t; cin >> t;
  const string nome = "vika";
  for (int i = 0; i < t; i++){
    int n, m;
    cin >> n >> m;

    bool trov = false;

    vector<vector<char>> carpet(m, vector<char>(n));
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        cin >> carpet[j][i];   
        
    vector<int> dp(m+1, 0);
    for (int i = 0; i < m; i++){
      dp[i+1] = dp[i];

      auto trovato = find(carpet[i].begin(), carpet[i].end(), nome[dp[i]]);
      if (trovato != carpet[i].end())
        dp[i+1]++;

      if (dp[i+1] == nome.size()){
        trov = true;
        break;
      }
    }

    cout << (trov ? "YES" : "NO") << "\n";
    
  }

}