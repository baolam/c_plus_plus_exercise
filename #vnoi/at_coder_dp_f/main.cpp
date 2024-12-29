#include <bits/stdc++.h>
#define MAXN 3001

using namespace std;

string s, t;
int dp[MAXN][MAXN];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  freopen("TEST.INP", "r", stdin);

  cin >> s >> t;
  int n = s.size(), m = t.size();

  dp[0][0] = 0;
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= m; j++)
    {
      if (s[i - 1] == t[j - 1])
        dp[i][j] = dp[i - 1][j - 1] + 1;
      else
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    }
  }

  // cout << dp[n][m];

  // for (int i = 1; i <= n; i++)
  // {
  //   for (int j = 1; j <= m; j++)
  //     cout << dp[i][j] << ' ';
  //   cout << '\n';
  // }

  string ans = "";
  while (n > 0 && m > 0)
  {
    if (s[n - 1] == t[m - 1])
    {
      ans += s[n - 1];
      n--;
      m--;
    }
    else if (dp[n - 1][m] > dp[n][m - 1])
    {
      n--;
    }
    else
    {
      m--;
    }
  }

  reverse(ans.begin(), ans.end());
  cout << ans;
  return 0;
}