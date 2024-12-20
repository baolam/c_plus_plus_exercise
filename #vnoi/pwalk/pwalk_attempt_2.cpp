#include <bits/stdc++.h>
#define maxn 1003

using namespace std;
struct Edge
{
  int v, w;
  Edge(int v = 0, int w = 0) : v(v), w(w) {}
};

int n, q;
int h[maxn], f[maxn];
int up[maxn][10];

vector<Edge> G[maxn];

void dfs(int u)
{
  for (Edge e : G[u])
  {
    int v = e.v, w = e.w;
    if (v == up[u][0])
      continue;

    h[v] = h[u] + 1;
    f[v] = f[u] + w;

    up[v][0] = u;
    for (int j = 1; j < 10; j++)
      up[v][j] = up[up[v][j - 1]][j - 1];

    dfs(v);
  }
}

int lca(int u, int v)
{
  if (h[u] != h[v])
  {
    if (h[u] < h[v])
      swap(u, v);

    int k = h[u] - h[v];
    for (int j = 0; (1 << j) <= k; j++)
    {
      if (k >> j & 1)
        u = up[u][j];
    }
  }

  if (u == v)
    return u;
  int k = __lg(h[u]);
  for (int j = k; j >= 0; j--)
  {
    if (up[u][j] != up[v][j])
      u = up[u][j], v = up[v][j];
  }

  return up[u][0];
}

int dist(int u, int v)
{
  int p = lca(u, v);
  return f[u] + f[v] - 2 * f[p];
}

int main()
{
  memset(h, 0, sizeof(h));
  memset(f, 0, sizeof(f));

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  freopen("VAO.INP", "r", stdin);
  cin >> n >> q;

  for (int i = 1, u, v, w; i < n; i++)
  {
    cin >> u >> v >> w;
    G[u].emplace_back(v, w);
    G[v].emplace_back(u, w);
  }

  dfs(1);

  for (int i = 1, u, v; i <= q; i++)
  {
    cin >> u >> v;
    cout << dist(u, v) << '\n';
  }
  return 0;
}