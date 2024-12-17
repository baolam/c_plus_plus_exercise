#include <bits/stdc++.h>
#define maxn 10001

using namespace std;

int n, m;
int numBridges = 0, numJoints = 0, timeDfs = 0;

int num[maxn], low[maxn];
bool joint[maxn];
vector<int> G[maxn];

void dfs(int u, int prev)
{
  int branches = 0;
  num[u] = low[u] = ++timeDfs;
  for (int v : G[u])
  {
    if (v == prev)
      continue;
    if (num[v] == 0)
    {
      dfs(v, u);
      low[u] = min(low[u], low[v]);
      branches++;

      if (low[v] == num[v])
        numBridges++;
      if (u == prev)
      {
        if (branches > 1)
          joint[u] = true;
      }
      else if (low[v] >= num[u])
        joint[u] = true;
    }
    else
      low[u] = min(low[u], num[v]);
  }
}

int main()
{
  memset(num, 0, sizeof(num));
  memset(joint, false, sizeof(joint));

  freopen("TEST.INP", "r", stdin);
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m;
  for (int i = 1; i <= m; i++)
  {
    int u, v;
    cin >> u >> v;
    G[u].push_back(v);
    G[v].push_back(u);
  }

  for (int i = 1; i <= n; i++)
  {
    if (num[i] == 0)
      dfs(i, i);
  }

  for (int i = 1; i <= n; i++)
    numJoints += joint[i];

  cout << numJoints << ' ' << numBridges;
  return 0;
}