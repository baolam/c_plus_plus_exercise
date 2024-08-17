#include <bits/stdc++.h>
// #define HAS_FILE

#ifdef HAS_FILE
#define FILE_NAME "ROPES"
#define READ FILE_NAME ".INP"
#define WRITE FILE_NAME ".OUT"
#endif

using namespace std;
typedef long long ll;

const int MAXN = 1e4 + 1;
int n, k;
int a[MAXN];

bool good(double x)
{
  int cnt = 0;
  for (int i = 1; i <= n; i++)
    cnt += floor(a[i] / x);
  return cnt >= k;
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
  cin >> n >> k;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  double l = 0;
  double r = 1e8;
  for (int t = 1; t <= 70; t++)
  {
    double m = (l + r) / 2;
    if (good(m))
      l = m;
    else
      r = m;
  }
  cout << setprecision(20) << l;
  return 0;
}