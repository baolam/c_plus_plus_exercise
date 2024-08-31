#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MAXN = 1e6 + 5;
int n, m;
int par[MAXN], r[MAXN], maxs[MAXN];

int find_set(int a)
{
  if (a == par[a])
    return a;
  par[a] = find_set(par[a]);
  return par[a];
}

void unite_set(int a, int b)
{
  a = find_set(a);
  b = find_set(b);
  if (a == b)
    return;
  if (r[a] < r[b])
    swap(a, b);
  if (r[a] == r[b])
    r[a]++;
  par[b] = a;
  maxs[a] = max(maxs[a], maxs[b]);
}

int main()
{
  cin.tie(NULL);
  cout.tie(NULL);
  ios_base::sync_with_stdio(false);
  cin >> n >> m;
  for (int i = 1; i <= n + 1; i++)
  {
    par[i] = i;
    r[i] = 1;
    maxs[i] = i;
  }
  char cmd;
  int x;
  while (m--)
  {
    cin >> cmd >> x;
    if (cmd == '-')
      unite_set(x, x + 1);
    else
    {
      int p = find_set(x);
      if (maxs[p] == n + 1)
        cout << -1 << '\n';
      else
        cout << maxs[p] << '\n';
    }
  }
  return 0;
}