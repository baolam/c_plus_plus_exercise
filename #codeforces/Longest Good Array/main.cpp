#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll t;
ll l, r;

void solve()
{
  int delta = 0;
  int start = l;
  int cnt = 0;
  while (start + delta <= r)
  {
    start += delta;
    delta++;
    cnt++;
  }
  cout << cnt << '\n';
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
    solve();
  }
  return 0;
}