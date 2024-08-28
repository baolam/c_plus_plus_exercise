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
  /// max j : a[j] <= x
  int j = 1;
  while (a[j] <= x)
    j++;
  return j - 1;
}

bool check(int distance)
{
  int cows = 1;
  for (int i = 1; i <= n; i++)
  {
    int j = i + 1;
    while (j <= n && a[j] < a[i] + distance)
      j++;
    if (j == n + 1)
      break;
    cows++;
    i = j - 1;
  }
  return cows >= k;
}

int main()
{
  cin.tie(NULL);
  cout.tie(NULL);
  ios_base::sync_with_stdio(false);
  // freopen("Cows_in_Stalls.INP", "r", stdin);
  cin >> n >> k;
  // a[0] = INT_MIN;
  // a[n + 1] = INT_MAX;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  // Property:
  // If good(m) then also good(m + 1), good(m + 2), ...
  // Find maximum distance
  int l = 0;
  int r = a[n];
  while (l < r - 1)
  {
    int m = (l + r) / 2;
    if (check(m))
      l = m;
    else
      r = m;
  }
  cout << l;
  return 0;
}