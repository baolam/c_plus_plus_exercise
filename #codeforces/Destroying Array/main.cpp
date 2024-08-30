#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MAXN = 1e5 + 1;
bool flag[MAXN];
int a[MAXN], p[MAXN], parent[MAXN], r[MAXN], sum[MAXN], res[MAXN];
int n, ans = 0;

void initalize_set()
{
  for (int i = 1; i <= n; i++)
  {
    parent[i] = i;
    r[i] = 1;
    sum[i] = a[i];
    flag[i] = false;
  }
  res[n] = 0;
}

int get_set(int x)
{
  if (x == parent[x])
    return x;
  parent[x] = get_set(parent[x]);
  return parent[x];
}

void unite_set(int x, int y)
{
  x = get_set(x);
  y = get_set(y);
  if (x == y)
    return;
  if (r[x] < r[y])
    swap(x, y);
  parent[y] = x;
  sum[x] += sum[y];
  if (r[x] == r[y])
    r[x]++;
}

int main()
{
  cin.tie(NULL);
  cout.tie(NULL);
  ios_base::sync_with_stdio(false);

  // freopen("Destroying_Array.INP", "r", stdin);
  cin >> n;

  for (int i = 1; i <= n; i++)
    cin >> a[i];
  for (int i = 1; i <= n; i++)
    cin >> p[i];

  initalize_set();

  for (int i = n; i >= 1; i--)
  {
    flag[p[i]] = true;

    if (p[i] > 1 && flag[p[i] - 1])
      unite_set(p[i], p[i] - 1);
    if (p[i] < n && flag[p[i] + 1])
      unite_set(p[i], p[i] + 1);

    ans = max(ans, sum[get_set(p[i])]);
    res[i - 1] = ans;
  }
  for (int i = 1; i <= n; i++)
    cout << res[i] << ' ';
  return 0;
}