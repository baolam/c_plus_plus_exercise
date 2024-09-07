#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int t, n;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  // freopen("VAO.INP", "r", stdin);
  cin >> t;
  while (t--)
  {
    cin >> n;
    /// 2x + 4y = n
    /// Duyệt gà tìm y
    /// 4y = n - 2x
    /// y = (n - 2x) / 4
    /// x + y = x + (n - 2x) / 4
    /// x + y = (4x + n - 2x) / 4
    /// x + y = (n + 2x) / 4
    /// ans = (n + 2x) / 4
    int x = 0;
    while ((n + 2 * x) % 4 != 0)
      x++;
    cout << (n + 2 * x) / 4 << '\n';
  }
  return 0;
}