#include <bits/stdc++.h>
#define maxn 1001
#define maxs 1001

using namespace std;

int n, s;
int v[maxn];
int f[maxn]; // số đồng xu ít nhất có tổng giá tiền là i

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  freopen("VI_DU_2.INP", "r", stdin);
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

  for (int i = 1; i <= s; i++)
    cout << f[i] << ' ';
  cout << '\n';

  return 0;
}