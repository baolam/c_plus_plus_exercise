#include <bits/stdc++.h>
#define MAXN 100001

using namespace std;

int n, timeDfs = 0;
vector<int> G[MAXN];

int code[MAXN], numCycles[MAXN], scc = 0; // Dùng để đánh dấu các SCC
int candy[MAXN];
int low[MAXN], num[MAXN];

stack<int> S;

void dfs(int u)
{
  low[u] = num[u] = ++timeDfs;
  S.push(u);

  for (auto v : G[u])
  {
    if (code[v] != -1)
      continue;

    if (!num[v])
    {
      dfs(v);

      low[u] = min(low[u], low[v]);
    }
    else
      low[u] = min(low[u], num[v]);
  }

  if (low[u] == num[u])
  {
    scc++;

    int v, _nodeSize = 0;

    do
    {
      v = S.top();
      S.pop();

      code[v] = scc;
      _nodeSize++;
    } while (u != v);

    numCycles[scc] = _nodeSize;
  }
}

void dfs_path(int u)
{
}

int main()
{
  memset(num, 0, sizeof(num));
  memset(code, -1, sizeof(code));
  memset(candy, 0, sizeof(candy));

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  freopen("tarjan.inp", "r", stdin);

  cin >> n;

  int v;
  for (int u = 1; u <= n; u++)
  {
    cin >> v;
    G[u].push_back(v);
  }

  for (int i = 1; i <= n; i++)
  {
    if (!num[i])
      dfs(i);
  }

  for (int i = 1; i <= n; i++)
    candy[i] = numCycles[code[i]];
  for (int i = 1; i <= n; i++)
  {
    if (candy[i] == 0)
    {
    }
  }

  return 0;
}