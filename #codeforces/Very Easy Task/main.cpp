#include <bits/stdc++.h>
// #define HAS_FILE

#ifdef HAS_FILE
#define FILE_NAME "EASYTASK"
#define READ FILE_NAME ".INP"
#define WRITE FILE_NAME ".OUT"
#endif

using namespace std;
typedef long long ll;

ll n, x, y;

bool good(ll t)
{
  if (t < min(x, y))
    return false;
  // Do phải sao chép 1 bản đầu tiên rùi mới in tiếp (- min (x, y))
  t -= min(x, y);
  ll n1 = t / x;
  ll n2 = t / y;
  return n1 + n2 >= n - 1;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
#ifdef HAS_FILE
  freopen(READ, "r", stdin);
  freopen(WRITE, "w", stdout);
#endif
  cin >> n >> x >> y;
  ll l = 0;
  ll r = max(x, y) * n;
  // Properties of good(m) function
  // 0 0 0 0 0 0 1 1 1 1 1
  // l for 0, r for 1
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