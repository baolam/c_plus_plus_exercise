#include <bits/stdc++.h>
#define maxn 100006

using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;
int n;
ll dp[maxn][3];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;

  for (int k = 0; k <= 2; k++)
    dp[1][k] = 1;

  for (int i = 2; i <= n; i++)
  {
    dp[i][0] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2]) % MOD;
    dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % MOD;
    dp[i][2] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2]) % MOD;
  }

  ll ans = (dp[n][0] + dp[n][1] + dp[n][2]) % MOD;
  cout << ans;

  return 0;
}