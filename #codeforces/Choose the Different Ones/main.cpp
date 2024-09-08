#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MAXN = 2e5 + 1;
int t;
int n, m, k;
int a[MAXN], b[MAXN];

bool check()
{
  if (n < k / 2 || m < k / 2)
    return false;
  int l = 1, r = 1;
  int tl = 0, tr = 0;
  /// l là chỉ số phần tử tượng trưng cho mảng a, tl là số phần tử chọn ở mảng a
  // r là chỉ số phần tử tượng trưng cho mảng b, tr là số phần tử chọn ở mảng b
  // Mục tiêu l đi tới k/2
  // r đi tới k/2
  int st = 1;
  while (l <= n || r <= m)
  {
    cout << "<><><><><><><><><><><><>" << '\n';
    cout << l << ' ' << a[l] << '\n';
    cout << r << ' ' << b[r] << '\n';
    cout << st << ' ' << tl << ' ' << tr << '\n';
    cout << "<><><><><><><><><><><><>" << '\n';
    if (st > k)
      return false;
    if (tl > k / 2 || tr > k / 2)
      return false;
    if (a[l] != st && b[r] != st)
      return false;
    if (a[l] == st && b[r] == st)
    {
      if (tl < tr)
        tl++;
      else
        tr++;
      while (l <= n && a[l] == st)
        l++;
      while (r <= m && b[r] == st)
        r++;
      st++;
    }
    else if (a[l] == st)
    {
      tl++;
      while (l <= n && a[l] == st)
        l++;
      st++;
    }
    else
    {
      tr++;
      while (r <= m && b[r] == st)
        r++;
      st++;
    }
  }
  return true;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  freopen("inp.INP", "r", stdin);
  cin >> t;
  while (t--)
  {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
      cin >> a[i];
    for (int i = 1; i <= m; i++)
      cin >> b[i];
    sort(a + 1, a + 1 + n);
    sort(b + 1, b + 1 + m);
    cout << "----------------------------------------" << '\n';
    if (check())
      cout << "YES" << '\n';
    else
      cout << "NO" << '\n';
    cout << "----------------------------------------" << '\n';
  }
  return 0;
}