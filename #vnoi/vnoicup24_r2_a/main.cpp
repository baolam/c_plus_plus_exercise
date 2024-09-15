#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MAXN = 5e3 + 1;

int t, n;
ll x;

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
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
      cin >> a[i];
    sort(a.begin(), a.end());
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
      int pos = -1;
      for (int j = 0; j < a.size(); j++)
      {
        // x * i >= ak
        // pos là vị trí đầu tiên thỏa điều kiện
        if (x >= a[j] / i + (a[j] % i != 0))
        {
          pos = j;
          break;
        }
      }
      if (pos == -1)
        break;
      ans++;
      a.erase(a.begin() + pos);
    }
    cout << ans << '\n';
  }
}