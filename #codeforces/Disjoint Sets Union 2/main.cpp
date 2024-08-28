#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MAXN = 3e5 + 1;
int n, m;
int p[MAXN], r[MAXN], mins[MAXN], maxs[MAXN], sums[MAXN];

int _get(int a)
{
  if (a == p[a])
    return a;
  p[a] = _get(p[a]);
  return p[a];
}

void _union(int a, int b)
{
  a = _get(a);
  b = _get(b);
  if (r[a] == r[b])
    r[a]++;
  if (r[a] > r[b])
  {
    p[b] = a;
    mins[a] = min(mins[a], mins[b]);
    maxs[a] = max(maxs[a], maxs[b]);
    sums[a] += sums[b];
  }
  else
  {
    p[a] = b;
    mins[b] = min(mins[a], mins[b]);
    maxs[b] = max(maxs[a], maxs[b]);
    sums[b] += sums[a];
  }
}

void get(int a)
{
  a = _get(a);
  cout << mins[a] << ' ' << maxs[a] << ' ' << sums[a] << '\n';
}

int main()
{
  cin.tie(NULL);
  cout.tie(NULL);
  ios_base::sync_with_stdio(false);
  freopen("Disjoint_Sets_Union2.INP", "r", stdin);
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
  {
    p[i] = i;
    r[i] = 1;
    mins[i] = i;
    maxs[i] = i;
    sums[i] = 1;
  }
  string req;
  int x, y;
  while (m--)
  {
    cin >> req;
    if (req == "union")
    {
      cin >> x >> y;
      _union(x, y);
    }
    else
    {
      cin >> x;
      get(x);
    }
  }
  return 0;
}