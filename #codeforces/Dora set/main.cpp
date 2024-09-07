#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int t;
int l, r;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  // freopen("VAO.INP", "r", stdin);
  cin >> t;
  while (t--)
  {
    cin >> l >> r;
    int ans = 0;
    while (l % 2 == 0)
      l++;
    while (l + 2 <= r)
    {
      ans++;
      l += 4;
    }
    cout << ans << '\n';
  }
  return 0;
}