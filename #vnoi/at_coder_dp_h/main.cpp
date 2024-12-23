#include <bits/stdc++.h>
#define maxn 1001

using namespace std;

const int MOD = 1e9 + 7;

int h, w;
char a[maxn][maxn];
int dp[maxn][maxn];

int main()
{
  memset(dp, 0, sizeof(dp));
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  freopen("TEST.INP", "r", stdin);
  cin >> h >> w;
  for (int i = 1; i <= h; i++)
  {
    for (int j = 1; j <= w; j++)
      cin >> a[i][j];
  }

  for (int i = 1; i <= h; i++)
  {
    if (a[i][1] == '.')
      dp[i][1] = 1;
    else
      break;
  }
  for (int j = 1; j <= w; j++)
  {
    if (a[1][j] == '.')
      dp[1][j] = 1;
    else
      break;
  }

  for (int i = 2; i <= h; i++)
  {
    for (int j = 2; j <= w; j++)
    {
      if (a[i][j] != '#')
        dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
    }
  }

  cout << dp[h][w];

  return 0;
}