#include <bits/stdc++.h>
#define maxn 2001

using namespace std;

int n, m;
bool visited[maxn];
vector<int> V[maxn];

void dfs(int x)
{
  visited[x] = true;
  stack<int> S;
  S.push(x);
  while (!S.empty())
  {
    int y = S.top();
    S.pop();
    for (int i = 0; i < V[y].size(); i++)
    {
      int z = V[y][i];
      if (!visited[z])
      {
        S.push(z);
        visited[z] = true;
      }
    }
  }
}

int main()
{
  memset(visited, false, sizeof(visited));
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  freopen("TEST.INP", "r", stdin);
  cin >> n >> m;
  int u, v;
  for (int i = 1; i <= m; i++)
  {
    cin >> u >> v;
    V[u].push_back(v);
    V[v].push_back(u);
  }
  int tplt = 0;
  for (int i = 1; i <= n; i++)
  {
    if (!visited[i])
    {
      dfs(i);
      tplt++;
    }
  }
  cout << m - n + tplt;
  return 0;
}