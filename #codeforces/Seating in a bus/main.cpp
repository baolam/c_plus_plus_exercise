#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 2;
bool a[MAXN];

bool check(int n)
{
  int x;
  for (int i = 2; i <= n; i++)
  {
    cin >> x;
    a[x] = true;
    if (a[x - 1] || a[x + 1])
      continue;
    return false;
  }

  return true;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  freopen("VAO.INP", "r", stdin);
  int t, n, x;
  cin >> t;
  while (t--)
  {
    cin >> n;
    for (int i = 0; i <= n + 1; i++)
      a[i] = false;
    cin >> x;
    a[x] = true;
    if (check(n))
      cout << "YES" << '\n';
    else
      cout << "NO" << '\n';
  }
  return 0;
}