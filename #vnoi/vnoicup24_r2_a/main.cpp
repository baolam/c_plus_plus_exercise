#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int t, n;
ll x, tmp;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // freopen("VAO.INP", "r", stdin);
  cin >> t;
  while (t--)
  {
    cin >> n >> x;
    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
      cin >> tmp;
      ans += (int)tmp <= x;
    }
    cout << ans << '\n';
  }
}