#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXN = 20001;

int t, n, x;
ll sum[MAXN];

int solve(int l, int r)
{
  if (r - l <= 1)
    return 0;
  if ((sum[r] - sum[l]) % 2 != 0)
    return 0;
  if (sum[r] - sum[l] == 0)
    return r - l - 1;
  ll half = (sum[r] - sum[l]) / 2;
  int low = l, high = r;
  while (low + 1 < high)
  {
    int mid = (low + high) / 2;
    if (sum[mid] - sum[l] <= half)
      low = mid;
    else
      high = mid;
  }
  return sum[low] - sum[l] == half ? max(solve(l, low), solve(low, r)) + 1 : 0;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  freopen("VAO.INP", "r", stdin);
  freopen("RA.OUT", "w", stdout);

  cin >> t;
  while (t--)
  {
    cin >> n;
    sum[0] = 0;
    for (int i = 1; i <= n; i++)
      cin >> x, sum[i] = sum[i - 1] + x;
    cout << solve(0, n) << '\n';
  }
  return 0;
}