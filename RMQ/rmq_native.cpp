#include <bits/stdc++.h>
#define maxn 100001

using namespace std;

int n, m;
int a[maxn];

int rmq_query(int l, int r)
{
  int res = a[l];
  for (int i = l + 1; i <= r; i++)
    res = min(res, a[i]);
  return res;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  freopen("TEST.INP", "r", stdin);

  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    cin >> a[i];

  for (int i = 1; i <= m; i++)
  {
    int l, r;
    cin >> l >> r;
    cout << rmq_query(l, r) << '\n';
  }
  return 0;
}