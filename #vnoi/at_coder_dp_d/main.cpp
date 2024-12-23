#include <bits/stdc++.h>
#define maxn 101
#define maxw 1000001

using namespace std;
typedef long long ll;

int n, weight;
int v[maxn], w[maxn];
ll dp[maxn][maxw];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  freopen("TEST.INP", "r", stdin);

  cin >> n >> weight;
  for (int i = 1; i <= n; i++)
  {
    cin >> w[i] >> v[i];
  }

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= weight; j++)
    {
      if (w[i] <= j)
        dp[i][j] = max(dp[i - 1][j - w[i]] + v[i], dp[i - 1][j]);
      else
        dp[i][j] = dp[i - 1][j];
    }
  }

  cout << dp[n][weight];
  return 0;
}