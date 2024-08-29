#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5e4 + 1;
int n, m, k;
int p[MAXN], r[MAXN];
int d[MAXN];

int get_set(int x)
{
  if (x == p[x])
    return x;
  p[x] = get_set(p[x]);
  return p[x];
}

void union_set(int a, int b)
{
  d[a]++;
  d[b]++;
  a = get_set(a);
  b = get_set(b);
  if (a == b)
    return;
  if (r[a] == r[b])
    r[a]++;
  if (r[a] > r[b])
    p[b] = a;
  else
    p[a] = b;
}

void decay_set(int a, int b)
{
  d[a]--;
  d[b]--;
  if (d[a] == 0)
    p[a] = a;
  if (d[b] == 0)
    p[b] = a;
}

bool isSameComponent(int a, int b)
{
  if (d[a] == 0 || d[b] == 0)
    return false;
  a = get_set(a);
  b = get_set(b);
  return a == b;
}

void test()
{
  for (int i = 1; i <= n; i++)
    cout << d[i] << ' ';
  cout << '\n';
}

int main()
{
  cin.tie(NULL);
  cout.tie(NULL);
  ios_base::sync_with_stdio(false);
  freopen("Cutting_a_Graph.INP", "r", stdin);
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++)
  {
    p[i] = i;
    r[i] = 1;
    d[i] = 0;
  }
  int u, v;
  while (m--)
  {
    cin >> u >> v;
    union_set(u, v);
  }
  string cmd;
  while (k--)
  {
    cin >> cmd >> u >> v;
    if (cmd == "cut")
      decay_set(u, v);
    else
    {
      if (isSameComponent(u, v))
        cout << "YES" << '\n';
      else
        cout << "NO" << '\n';
    }
  }
  return 0;
}