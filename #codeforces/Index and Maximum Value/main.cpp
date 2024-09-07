#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MAXN = 1e5 + 2;

int t;
int n, m;
ll a[MAXN], p[MAXN];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  freopen("a.INP", "r", stdin);
  cin >> t;
  while (t--)
  {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
      cin >> a[i];
    memset(p, 0, sizeof(p));
    string x;
    int l, r;
    for (int i = 1; i <= m; i++)
    {
      cin >> x;
      cin >> l >> r;
      if (x == "+")
        p[l]++, p[r + 1]--;
      else
        p[l]--, p[r + 1]++;
    }
    for (int i = 1; i <= n; i++)
    {
      p[i] += p[i - 1];
      cout << a[i] + p[i] << '\n';
    }
  }
  return 0;
}