#include <bits/stdc++.h>
#define MAXN 100001

using namespace std;

int n, timeDfs = 0, scc = 0;
int num[MAXN], low[MAXN];
int sccs[MAXN];

vector<int> G[MAXN];
stack<int> S;

void dfs(int u)
{
  num[u] = low[u] = ++timeDfs;
  S.push(u);

  for (auto v : G[u])
  {
    if (sccs[v] != -1)
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
    int v;
    scc++;
    do
    {
      v = S.top();
      S.pop();
      sccs[v] = scc;
    } while (u != v);
  }
}

int main()
{
  memset(num, 0, sizeof(num));
  memset(sccs, -1, sizeof(sccs));

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

  for (int u = 1; u <= n; u++)
  {
    if (!num[u])
      dfs(u);
  }

  for (int i = 1; i <= n; i++)
    cout << sccs[i] << ' ';

  return 0;
}