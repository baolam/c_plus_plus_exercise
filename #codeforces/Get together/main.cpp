#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int MAXN = 1e5 + 1;
ll n;
ld x[MAXN], v[MAXN];

bool isPossible(ld t)
{
  ld ls = x[1] - t * v[1];
  ld rs = x[1] + t * v[1];
  for (int i = 2; i <= n; i++)
  {
    ld lt = x[i] - t * v[i];
    ld rt = x[i] + t * v[i];
    ls = max(ls, lt);
    rs = min(rs, rt);
  }
  return ls <= rs;
}

int main()
{
  cin.tie(NULL);
  cout.tie(NULL);
  ios_base::sync_with_stdio(false);
  // freopen("Get.together.INP", "r", stdin);
  cin >> n;
  for (ll i = 1; i <= n; i++)
    cin >> x[i] >> v[i];
  ld lm = 0.;
  ld rm = 2 * 1e9;
  for (int __ = 1; __ <= 100; __++)
  {
    ld m = (lm + rm) / 2;
    if (isPossible(m))
      rm = m;
    else
      lm = m;
  }
  cout << setprecision(15) << rm;
  return 0;
}