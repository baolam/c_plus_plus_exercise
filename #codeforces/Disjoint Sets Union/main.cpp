#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MAXN = 1e5 + 1;
int n, q;
int p[MAXN], r[MAXN];

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
  }
  else
  {
    p[a] = b;
  }
}

bool isSameSet(int a, int b)
{
  a = _get(a);
  b = _get(b);
  return a == b;
}

int main()
{
  cin.tie(NULL);
  cout.tie(NULL);
  ios_base::sync_with_stdio(false);
  cin >> n >> q;
  for (int i = 1; i <= n; i++)
  {
    p[i] = i; // Represent of element
    r[i] = 1; // Rank of element
  }
  string req;
  int a, b;
  while (q--)
  {
    cin >> req >> a >> b;
    if (req == "union")
      _union(a, b);
    else
    {
      if (isSameSet(a, b))
        cout << "YES" << '\n';
      else
        cout << "NO" << '\n';
    }
  }
  return 0;
}