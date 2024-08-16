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
ll sum = 0;
int a[MAXN];

bool f(double x)
{
  int cnt = 0;
  for (int i = 1; i <= n; i++)
    cnt += (int)(a[i] / x);
  return cnt >= k;
}

double bSearch()
{
  double l = 0;
  double r = sum / k;
  while (r - l > 1e-6)
  {
    double x = (l + r) / 2;
    if (f(x))
      l = x;
    else
      r = x;
  }
  return r;
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
  {
    cin >> a[i];
    sum += a[i];
  }
  cout << bSearch() << '\n';
  return 0;
}