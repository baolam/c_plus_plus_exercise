#include <bits/stdc++.h>
// #define HAS_FILE

#ifdef HAS_FILE
#define FILE_NAME "EASYTASK"
#define READ FILE_NAME ".INP"
#define WRITE FILE_NAME ".OUT"
#endif

using namespace std;
typedef long long ll;

int n, x, y;

bool good(int t)
{
  int t1 = t / x;
  int t2 = t / y;
  // Do phải sao chép 1 bản đầu tiên rùi mới in tiếp (- min (x, y))
  return t1 + t2 - min(x, y) >= n;
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
  int l = min(x, y);
  int r = max(n * x, n * y);
  // Properties of good(m) function
  // 0 0 0 0 0 0 1 1 1 1 1
  // l for 0, r for 1
  while (l < r - 1)
  {
    int m = (l + r) / 2;
    if (good(m))
      r = m;
    else
      l = m;
  }
  cout << r;
  return 0;
}