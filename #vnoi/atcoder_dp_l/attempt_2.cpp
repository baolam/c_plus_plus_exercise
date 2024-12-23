#include <bits/stdc++.h>
#define maxn 3001

using namespace std;
typedef long long ll;

int n;
ll a[maxn];
ll dp[maxn][maxn];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  freopen("TEST.INP", "r", stdin);
  cin >> n;
  for (int i = 1; i <= n; i++)
  {
    cin >> a[i];
    dp[i][i] = a[i];
  }

  for (int i = n; i >= 1; i--)
  {
    for (int j = i + 1; j <= n; j++)
      dp[i][j] = max(a[i] - dp[i + 1][j], a[j] - dp[i][j - 1]);
  }

  cout << dp[1][n];
  return 0;
}