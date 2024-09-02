// Miêu tả vấn đề
//
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int t;
int l, r;
int L, R;

void solve()
{
  if (L > r || R < l)
    cout << 0 << '\n';
  else
    cout << min(r, R) - max(l, L) + 1 << '\n';
  return;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> t;
  while (t--)
  {
    cin >> l >> r;
    cin >> L >> R;
    solve();
  }
  return 0;
}