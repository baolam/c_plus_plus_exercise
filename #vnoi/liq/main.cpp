#include <bits/stdc++.h>
#define maxn 1001

using namespace std;

int n;
int a[maxn], dp[maxn];

int main()
{
  memset(dp, 1, sizeof(dp));

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> a[i];

  for (int i = 1; i <= n; i++)
  {
    int _val = 0;
    for (int j = 1; j < i; j++)
    {
      if (a[i] > a[j])
        _val = max(_val, dp[j]);
    }
    dp[i] = _val + 1;
  }

  int ans = *max_element(dp + 1, dp + 1 + n);
  cout << ans;

  return 0;
}