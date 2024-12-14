#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ll;

ll l, r, a, k;

ll result(ll m)
{
  ll _min = (l % m == 0) ? l : (l / m + 1) * m;
  ll _max = (r / m) * m;
  ll res = (_max - _min) / m + 1;
  if (_min > _max)
    return 0;
  return res;
}

int main()
{
  cin.tie(NULL);
  cout.tie(NULL);
  ios_base::sync_with_stdio(false);
  cin >> l >> r >> a >> k;
  cout << result(k / gcd(a, k)) << '\n';
  return 0;
}