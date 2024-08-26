/// Vấn đề:
/// Cho một mảng gồm n số nguyên dương.
/// Cần tách mảng đó thành k đoạn sao cho tổng lớn nhất trong các đoạn là nhỏ nhất có thể

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MAXN = 1e5 + 1;
int n, k;
int a[MAXN];
ll sum = 0;

bool good(ll _sum)
{
  /// Ý tưởng thuật toán
  /// Mở rộng trường tìm kiếm của k
  /// Nếu k < kmin thì bất khả
  ll tmp = 0, kmin = 1;
  for (ll i = 1; i <= n; i++)
  {
    if (a[i] > _sum)
      return false;
    if (tmp + a[i] <= _sum)
      tmp += a[i];
    else
    {
      tmp = a[i];
      kmin++;
    }
  }
  return kmin <= k;
}

int main()
{
  cin.tie(NULL);
  cout.tie(NULL);
  ios_base::sync_with_stdio(false);
  // freopen("Spliting_an_Array.INP", "r", stdin);
  cin >> n >> k;
  for (int i = 1; i <= n; i++)
    cin >> a[i], sum += a[i];
  ll l = 0, r = sum + 1;
  while (l < r - 1)
  {
    ll m = (l + r) / 2;
    if (good(m))
      r = m;
    else
      l = m;
  }
  cout << r;
  return 0;
}