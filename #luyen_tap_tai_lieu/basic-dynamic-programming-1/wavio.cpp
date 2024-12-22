#include <bits/stdc++.h>
#define maxn 1001

using namespace std;

int n;
int a[maxn];
int p[maxn], q[maxn];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> a[i];

  for (int i = 1; i <= n; i++)
  {
    p[i] = 1;
    for (int j = 1; j < i; j++)
    {
      if (a[j] < a[i])
        p[i] = max(p[i], p[j] + 1);
    }
  }

  for (int i = n; i >= 1; i--)
  {
    q[i] = 1;
    for (int j = n; j > i; j--)
    {
      if (a[j] < a[i])
        q[i] = max(q[i], q[j] + 1);
    }
  }

  int ans = 0;
  for (int i = 1; i <= n; i++)
  {
    // cout << p[i] << ' ' << q[i] << '\n';
    ans = max(ans, p[i] + q[i] - 1);
  }

  cout << ans;
  return 0;
}