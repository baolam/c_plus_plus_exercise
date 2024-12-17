#include <bits/stdc++.h>
#define maxn 10001

using namespace std;

int n, m;
int timeDfs = 0, scc = 0;
bool deleted[maxn];
int low[maxn], num[maxn];

vector<int> G[maxn];
stack<int> S;

void dfs(int u)
{
  low[u] = num[u] = ++timeDfs;
  S.push(u);

  for (int v : G[u])
  {
    if (deleted[v])
      continue;
    if (num[v] == 0)
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
    int v;
    do
    {
      v = S.top();
      deleted[v] = true;
      S.pop();
    } while (u != v);
  }
}

int main()
{
  memset(num, 0, sizeof(num));
  memset(deleted, false, sizeof(deleted));

  // freopen("TEST.INP", "r", stdin);

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m;
  for (int i = 1; i <= m; i++)
  {
    int u, v;
    cin >> u >> v;
    G[u].push_back(v);
  }

  for (int i = 1; i <= n; i++)
    if (num[i] == 0)
      dfs(i);

  cout << scc;
  return 0;
}