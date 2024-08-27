/// Describe problem:
/// Xếp bò vào chuồng, sao cho khoảng cách ngắn nhất giữa hai con bò là lớn nhất có thể
/// min(max) problem

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MAXN = 1e4 + 1;
int n, k;
int a[MAXN];

int left_most(int x)
{
  /// min i: Phần tử đầu tiên lớn hơn x, a[i] > x
  /// a[l] <= x --> belong to l
  /// a[r] > x --> belong to r
  int l = 0, r = n + 1;
  while (l < r - 1)
  {
    int m = (l + r) / 2;
    if (a[m] > x)
      r = m;
    else
      l = m;
  }
  return l;
}

bool good(int distance)
{
  int cows = 1;
  for (int l = 1; l <= n; l++)
  {
    int r = left_most(a[l] + distance);
    if (l == r)
      break;
    cout << l << ' ' << r << ' ' << a[l] + distance << '\n';
    cows++;
    l = r - 1;
  }
  return cows >= k;
}

int main()
{
  cin.tie(NULL);
  cout.tie(NULL);
  ios_base::sync_with_stdio(false);
  freopen("Cows_in_Stalls.INP", "r", stdin);
  cin >> n >> k;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  // cout << good(9) << '\n';
  int l = 0;
  int r = a[n];
  // Property:
  // If good(m) then also good(m + 1), good(m + 2), ...
  // Find maximum distance
  while (l < r - 1)
  {
    int m = (l + r) / 2;
    cout << m << ' ' << good(m) << '\n';
    if (good(m))
      r = m;
    else
      l = m;
  }
  cout << r;
  return 0;
}