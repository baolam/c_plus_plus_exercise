#include <bits/stdc++.h>
#define HAS_FILE

#ifdef HAS_FILE
#define FILE_NAME "CH"
#define READ FILE_NAME ".INP"
#define WRITE FILE_NAME ".OUT"
#endif

using namespace std;
typedef long long ll;

const int MAXN = 1001;
const int MAXM = 150001;

struct Node
{
  int t = 0;
  int z = 0;
  int y = 0;
};

int m, n;
int f[MAXN];
Node a[MAXN];

ll time(ll x, ll i)
{
  // x là số bóng bay, trợ lí i
  // thời gian bơm x quả bóng bởi trợ lí i
  Node tmp = a[i];
  ll delta = x % tmp.z == 0 ? -tmp.y : 0;
  ll relax = x / tmp.z;
  relax *= tmp.y;
  return x * tmp.t + relax + delta;
}

bool good(ll t)
{
  memset(f, 0, sizeof(f));

  // t là thời gian cần kiểm tra
  ll cnt = 0;
  for (int i = 1; i <= n; i++)
  {
    // Cần tìm kiếm số bóng bay thổi bởi trợ lí dựa vào thời gian t
    // max x : time(x) <= t thuộc về l
    // time(l) <= t, time(r) > t
    int tmp = 0;
    int l = 0, r = m;
    while (l < r - 1)
    {
      ll mid = (l + r) / 2;
      if (time(mid, i) <= t)
        l = mid;
      else
        r = mid;
    }
    cnt += l;
    f[i] = l;
    if (cnt >= m)
      return true;
  }
  return false;
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
  cin >> m >> n;
  ll l = 0, r = 0;
  for (int i = 1; i <= n; i++)
  {
    cin >> a[i].t >> a[i].z >> a[i].y;
    r = max(r, time(m, i));
  }
  // Tính tăng trong thời gian
  // Hàm good(t) có dạng 0 0 0 0 1 1 1 1
  while (l < r - 1)
  {
    ll m = (l + r) / 2;
    if (good(m))
      r = m;
    else
      l = m;
  }
  cout << r << '\n';
  for (int i = 1; i <= n; i++)
    cout << f[i] << ' ';
  return 0;
}