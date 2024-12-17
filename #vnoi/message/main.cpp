#include <bits/stdc++.h>
#define maxn 801

using namespace std;

int n, m;
int timeDfs = 0, scc = 0;
int num[maxn], low[maxn];
int sccId[maxn];
int in_degree[maxn];

vector<int> G[maxn];
stack<int> temp_scc;

void dfs(int u)
{
  low[u] = num[u] = ++timeDfs;
  temp_scc.push(u);

  for (int v : G[u])
  {
    if (sccId[v] != -1)
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
      v = temp_scc.top();
      sccId[v] = scc;
      temp_scc.pop();
    } while (v != u);
  }
}

int main()
{
  memset(num, 0, sizeof(num));
  memset(sccId, -1, sizeof(sccId));
  memset(in_degree, 0, sizeof(in_degree));

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

  // Tiến hành áp dụng thuật toán Tarjan --> Đánh dấu thành phần liên thông mạnh
  for (int i = 1; i <= n; i++)
  {
    if (num[i] == 0)
      dfs(i);
  }

  // Tiến hành dựng đồ thị SCC và tính số bậc vào mỗi đỉnh tối giản
  for (int u = 1; u <= n; u++)
  {
    for (int v : G[u])
    {
      if (sccId[u] != sccId[v])
        in_degree[sccId[v]]++;
    }
  }

  int ans = 0;
  for (int i = 1; i <= scc; i++)
  {
    if (in_degree[i] == 0)
      ans++;
  }
  cout << ans;
  return 0;
}