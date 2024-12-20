#include <bits/stdc++.h>
#define maxn 1001

using namespace std;

int n, s;
int v[maxn], f[maxn];

int main()
{
  freopen("VI_DU_2.INP", "r", stdin);

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> s;
  for (int i = 1; i <= n; i++)
    cin >> v[i];

  f[0] = 0;
  for (int i = 1; i <= s; i++)
    f[i] = -1;

  for (int i = 1; i <= s; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      if (v[j] <= i && f[i - v[j]] != -1)
      {
        if (f[i] == -1)
          f[i] = f[i - v[j]] + 1;
        else
          f[i] = min(f[i], f[i - v[j]] + 1);
      }
    }
  }

  cout << f[s];
  return 0;
}