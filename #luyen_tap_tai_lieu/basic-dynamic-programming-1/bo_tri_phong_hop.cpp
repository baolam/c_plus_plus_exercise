#include <bits/stdc++.h>
#define x first
#define y second
#define maxn 1001

using namespace std;
typedef pair<int, int> II;

int n;
int dp[maxn];
II a[maxn];

int main()
{
  memset(dp, 1, sizeof(dp));

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> a[i].x >> a[i].y;

  sort(a + 1, a + 1 + n);
  for (int i = 1; i <= n; i++)
  {
    int _max = 0;
    for (int j = 1; j < i; j++)
    {
      if (a[j].y <= a[i].x)
      {
        _max = max(_max, dp[j] + 1);
      }
    }
    dp[i] = _max + 1;
  }

  cout << dp[n];
  return 0;
}