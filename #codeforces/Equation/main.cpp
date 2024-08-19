#include <bits/stdc++.h>
// #define HAS_FILE

#ifdef HAS_FILE
#define FILE_NAME "EQUATION"
#define READ FILE_NAME ".INP"
#define WRITE FILE_NAME ".OUT"
#endif

using namespace std;
typedef long long ll;
typedef long double ld;

const int STEP = 100;
ld c;

ld f(ld x)
{
  return x * x + sqrt(x);
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
  cin >> c;
  ld lo = 0, hi = 1e5 + 1;
  for (int i = 1; i <= STEP; i++)
  {
    ld mid = (lo + hi) / 2;
    if (f(mid) <= c)
      lo = mid;
    else
      hi = mid;
  }
  cout << setprecision(16) << lo << '\n';
  return 0;
}