#include <bits/stdc++.h>
#define maxn 801

using namespace std;
typedef long long ll;

int n, m;
int deg_in[maxn];

int main()
{
  memset(deg_in, 0, sizeof(deg_in));
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  freopen("TEST.INP", "r", stdin);
  cin >> n >> m;
  int u, v;
  for (int i = 1; i <= m; i++)
  {
    cin >> u >> v;
    deg_in[v]++;
  }

  int ans = 0;
  for (int i = 1; i <= n; i++)
  {
    if (deg_in[i] == 0)
      ans++;
  }
  cout << ans;
  return 0;
}