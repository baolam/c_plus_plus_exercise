#include <bits/stdc++.h>
#define MAXN 3000

using namespace std;

int n;
long double p[MAXN];
long double dp[MAXN][MAXN];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  freopen("TEST.INP", "r", stdin);

  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> p[i], dp[i][0] = 1;

  dp[0][0] = 1;

  int leastHeads = n / 2 + 1;
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= leastHeads; j++)
    {
      dp[i][j] = dp[i - 1][j - 1] * p[i] + dp[i - 1][j] * (1 - p[i]);
    }
  }

  cout << setprecision(10) << dp[n][leastHeads];
}