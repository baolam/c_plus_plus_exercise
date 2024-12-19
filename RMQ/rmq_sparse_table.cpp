#include <bits/stdc++.h>
#define maxn 100001
#define maxlog 17

using namespace std;

int n, m;
int st[maxlog][maxn];

void preprocess()
{
  for (int j = 1; j <= maxlog; j++)
  {
    for (int i = 1; i + (1 << j) - 1 <= n; i++)
    {
      st[j][i] = min(st[j - 1][i], st[j - 1][i + (1 << (j - 1))]);
    }
  }
}

int queryMin(int l, int r)
{
  int k = __lg(r - l + 1);
  return min(st[k][l], st[k][r - (1 << k) + 1]);
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> st[0][i];
  preprocess();
  cin >> m;
  for (int _ = 1; _ <= m; _++)
  {
    int l, r;
    cin >> l >> r;
    cout << queryMin(l, r) << '\n';
  }
  return 0;
}