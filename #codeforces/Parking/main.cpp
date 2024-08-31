#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MAXN = 3e5 + 2;
int n;
bool flag[MAXN];
int a[MAXN], p[MAXN], r[MAXN], maxs[MAXN];
int res[MAXN];

int find_set(int x)
{
  if (x == p[x])
    return x;
  p[x] = find_set(p[x]);
  return p[x];
}

void unite_set(int x, int y)
{
  x = find_set(x);
  y = find_set(y);
  if (x == y)
    return;
  if (r[x] < r[y])
    swap(x, y);
  if (r[x] == r[y])
    r[x]++;
  p[y] = x;
  maxs[x] = max(maxs[x], maxs[y]);
}

bool isSameSet(int x, int y)
{
  x = find_set(x);
  y = find_set(y);
  return x == y;
}

int main()
{
  cin.tie(NULL);
  cout.tie(NULL);
  ios_base::sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i <= n; i++)
  {
    cin >> a[i];
    p[i] = i;
    r[i] = 0;
    maxs[i] = i;
    flag[i] = false;
  }
  /// Đầu ra res[i] là vị trí đổ xe của người i
  for (int i = 1; i <= n; i++)
  {
    if (!flag[a[i]])
    {
      res[i] = a[i];
      flag[a[i]] = true;
    }
    else
    {
      int pos = find_set(p[i]);
      res[i] = maxs[pos];
      if (res[i] == n + 1)
        res[i] = 1;
      unite_set(p[i], res[i]);
    }
  }
  for (int i = 1; i <= n; i++)
    cout << res[i] << ' ';
  return 0;
}