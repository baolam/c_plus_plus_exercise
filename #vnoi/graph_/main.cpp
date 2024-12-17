#include <bits/stdc++.h>
#define maxn 10001

using namespace std;

int n, m;
int timeDfs = 0, numBridges = 0, numJoints = 0;

bool joint[maxn];

vector<int> V[maxn];
int nums[maxn], tail[maxn], low[maxn];

void dfs(int u, int prev)
{
  int branches = 0;

  nums[u] = low[u] = ++timeDfs;
  for (int i = 0; i < V[u].size(); i++)
  {
    int v = V[u][i];
    if (v == prev)
      continue;
    if (nums[v] == 0)
    {
      dfs(v, u);
      low[u] = min(low[u], low[v]);

      // Tiến hành xử lí bài toán riêng (xác định số cầu, khớp)
      branches++;

      if (low[v] == nums[v])
        numBridges++;
      if (u == prev)
      {
        if (branches > 1)
          joint[u] = true;
      }
      else if (low[v] >= nums[u])
        joint[u] = true;
    }
    else
    {
      low[u] = min(low[u], nums[v]);
    }
  }

  tail[u] = timeDfs;
}

int main()
{
  memset(nums, 0, sizeof(nums));
  memset(joint, false, sizeof(joint));

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

  for (int i = 1; i <= n; i++)
  {
    if (nums[i] == 0)
    {
      dfs(i, i);
    }
  }

  for (int i = 1; i <= n; i++)
    numJoints += joint[i];

  cout << numJoints << ' ' << numBridges;
  return 0;
}