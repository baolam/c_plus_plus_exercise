#include <bits/stdc++.h>
#define maxn 801

using namespace std;
typedef long long ll;

int n, m;
bool visited[maxn];
vector<int> V[maxn];

void dfs(int x)
{
  visited[x] = false;

  stack<int> temp;
  temp.push(x);

  while (!temp.empty())
  {
    int u = temp.top();
    temp.pop();
    for (int i = 0; i < V[u].size(); i++)
    {
      int v = V[u][i];
      if (visited[v])
      {
        visited[v] = false;
        temp.push(v);
      }
    }
  }
}

int solve_at(int x)
{
  memset(visited, true, sizeof(visited));

  int ans = 1;
  dfs(x);

  for (int i = 1; i <= n; i++)
  {
    if (visited[i])
    {
      dfs(i);
      ans++;
    }
  }

  return ans;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  // freopen("TEST.INP", "r", stdin);
  cin >> n >> m;
  int u, v;
  for (int i = 1; i <= m; i++)
  {
    cin >> u >> v;
    V[u].push_back(v);
  }

  int ans = INT_MAX;
  for (int i = 1; i <= n; i++)
    ans = min(ans, solve_at(i));
  cout << ans;
  return 0;
}