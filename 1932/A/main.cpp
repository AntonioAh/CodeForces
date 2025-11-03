#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void testcase() {
    int n; cin >> n;
    string s; cin >> s;
    s = " " + s; 

    vector<int> dp(n + 1, -1);
    dp[1] = (s[1] == '@' ? 1 : 0); 

    for (int i = 2; i <= n; i++) {
        if (s[i] == '*') continue; // can't land on thorns
        if (dp[i - 1] != -1) dp[i] = max(dp[i], dp[i - 1]);
        if (i > 2 && dp[i - 2] != -1) dp[i] = max(dp[i], dp[i - 2]);
        if (dp[i] != -1 && s[i] == '@') dp[i]++;
    }

    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans = max(ans, dp[i]);

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) testcase();
}
