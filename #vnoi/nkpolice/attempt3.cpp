#include <bits/stdc++.h>
#define MAXN 100002
#define MAXLOG 19

using namespace std;

int n, m, q;
int timeDfs = 0;

int num[MAXN], low[MAXN], tail[MAXN];
int p[MAXN][MAXLOG + 1], depth[MAXN];
bool joint[MAXN];

vector<int> G[MAXN];

void buildP()
{
  p[1][0] = 1;

  for (int j = 1; j <= MAXLOG; j++)
  {
    for (int i = 1; i <= n; i++)
      p[i][j] = p[p[i][j - 1]][j - 1];
  }
}

int findParent(int u, int par)
{
  for (int j = MAXLOG; j >= 0; j--)
  {
    if (depth[p[u][j]] > depth[par])
      u = p[u][j];
  }
  return u;
}

void dfs(int u, int prev)
{
  int child = 0;

  low[u] = num[u] = ++timeDfs;

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
      low[u] = min(low[u], num[v]);
  }

  tail[u] = timeDfs;
}

bool isSubTree(int u, int root)
{
  return num[root] <= num[u] && num[u] <= tail[root];
}

bool query1(int a, int b, int g1, int g2)
{
  // Giả sử g2 là con trực tiếp g1, nếu g1 là con g2 --> swap
  if (num[g1] > num[g2])
    swap(g1, g2);

  // Là cạnh cầu, không phải xoá ko ảnh hưởng
  if (low[g2] != num[g2])
    return true;

  // Do cạnh cầu xoá sẽ làm tăng thêm 1 thành phần liên thông
  // Kiểm tra sự tồn tại a, b đối với g2
  if (isSubTree(a, g2) && !isSubTree(b, g2))
    return false;
  if (isSubTree(b, g2) && !isSubTree(a, g2))
    return false;

  return true;
}

bool query2(int a, int b, int c)
{
  /// Nếu không là đỉnh khớp thì việc loại bỏ không làm ảnh hưởng thành phần liên thông
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