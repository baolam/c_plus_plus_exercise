#include <bits/stdc++.h>
#define maxn 100003

using namespace std;

int n, m, q;
int timeDfs = 0;

int num[maxn], low[maxn], tail[maxn];
int p[20][maxn], depth[maxn];

bool joint[maxn];

vector<int> G[maxn];

void buildP()
{
  p[1][0] = 1;

  for (int j = 1; j <= 19; j++)
  {
    for (int i = 1; i <= n; i++)
    {
      p[i][j] = p[p[i][j - 1]][j - 1];
    }
  }
}

int findParent(int u, int par)
{
  /// Tìm tổ tiên chung của u là con trực tiếp của par
  for (int i = 19; i >= 0; i--)
  {
    if (depth[p[u][i]] > depth[par])
      u = p[u][i];
  }
  return u;
}

void dfs(int u, int prev)
{
  int child = 0;
  num[u] = low[u] = ++timeDfs;

  for (int v : G[u])
  {
    if (v == prev)
      continue;

    if (!num[v])
    {
      child++;

      p[v][0] = u;
      depth[v] = depth[u] + 1;

      dfs(v, u);
      low[u] = min(low[u], low[v]);

      if (u == prev)
      {
        if (child > 1)
          joint[u] = true;
      }
      else if (low[v] >= num[u])
        joint[u] = true;
    }
    else
    {
      low[u] = min(low[u], num[v]);
    }
  }

  tail[u] = timeDfs;
}

bool isSubTree(int u, int root)
{
  return num[root] <= num[u] && num[u] <= tail[root];
}

bool query1(int a, int b, int g1, int g2)
{
  /// Coi g2 là cây con trực tiếp của g1
  if (num[g1] > num[g2])
    swap(g1, g2);

  // Nếu g1->g2 không là cạnh cầu
  if (low[g2] != num[g2])
    // Không ảnh hưởng liên thông
    return true;

  if (isSubTree(a, g2) && !isSubTree(b, g2))
    return false;
  if (isSubTree(b, g2) && !isSubTree(a, g2))
    return false;

  return true;
}

bool query2(int a, int b, int c)
{
  /// Không phải đỉnh cầu
  if (!joint[c])
    return true;

  int pa = 0, pb = 0;
  if (isSubTree(a, c))
    pa = findParent(a, c);
  if (isSubTree(b, c))
    pb = findParent(b, c);

  if (!pa && !pb)
    return true;
  if (pa == pb)
    return true;
  if (!pa && low[pb] < num[c])
    return true;
  if (!pb && low[pa] < num[c])
    return true;
  if (pa && pb && low[pa] < num[c] && low[pb] < num[c])
    return true;

  return false;
}

int main()
{
  memset(num, 0, sizeof(num));
  memset(joint, false, sizeof(joint));

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  freopen("TEST.INP", "r", stdin);

  cin >> n >> m;
  for (int i = 1, u, v; i <= m; i++)
  {
    cin >> u >> v;
    G[u].push_back(v);
    G[v].push_back(u);
  }

  dfs(1, 1);
  buildP();

  cin >> q;
  for (int i = 1, type, a, b, c, g1, g2; i <= q; i++)
  {
    bool result;
    cin >> type;

    if (type == 1)
    {
      cin >> a >> b >> g1 >> g2;
      result = query1(a, b, g1, g2);
    }
    else
    {
      cin >> a >> b >> c;
      result = query2(a, b, c);
    }

    if (result)
      cout << "yes" << '\n';
    else
      cout << "no" << '\n';
  }
  return 0;
}