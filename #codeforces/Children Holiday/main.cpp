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
Node a[MAXN];

bool compare(Node x1, Node x2)
{
  if (x1.t == x2.t && x1.z == x2.z)
    return x1.y <= x2.y;
  if (x1.t == x2.t)
    return x1.z < x2.z;
  return x1.t < x2.t;
}

ll time(ll x, ll i)
{
  Node tmp = a[i];
  ll delta = x % tmp.z == = 0 ? -tmp.y : 0;
  ll relax = x / tmp.z;
  relax *= tmp.y;
  return x * tmp.t + relax + delta;
}

void show_sort()
{
  for (int i = 1; i <= n; i++)
    cout << a[i].t << ' ' << a[i].z << ' ' << a[i].y << '\n';
  cout << '\n';
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
  for (int i = 1; i <= n; i++)
    cin >> a[i].t >> a[i].z >> a[i].y;
  sort(a + 1, a + 1 + n, compare);
  show_sort();
  return 0;
}