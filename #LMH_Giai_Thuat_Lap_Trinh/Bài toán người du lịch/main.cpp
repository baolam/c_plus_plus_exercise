#include <bits/stdc++.h>
#define HAS_FILE

#ifdef HAS_FILE
#define FILE_NAME "TOURISM"
#define READ FILE_NAME ".INP"
#define WRITE FILE_NAME ".OUT"
#endif

using namespace std;
typedef long long ll;

const int MAXN = 21;
int n, k, bestConfig = INT_MAX;
int x[MAXN], t[MAXN], best[MAXN];
int a[MAXN][MAXN];
bool f[MAXN];

void Try(int i)
{
  for (int j = 2; j <= n; j++)
  {
    if (f[j])
    {
      x[i] = j;
      t[i] = t[i - 1] + a[x[i - 1]][j];
      if (t[i] < bestConfig)
      {
        if (i < n)
        {
          f[j] = false;
          Try(i + 1);
          f[j] = true;
        }
        else
        {
          if (t[n] + a[x[n]][1] < bestConfig)
          {
            bestConfig = t[n] + a[n][1];
            for (int k = 1; k <= n; k++)
              best[k] = x[k];
          }
        }
      }
    }
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
#ifdef HAS_FILE
  freopen(READ, "r", stdin);
  freopen(WRITE, "w", stdout);
#endif
  memset(f, true, sizeof(f));
  memset(t, 0, sizeof(t));
  cin >> n >> k;
  int u, v, w;
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      if (i == j)
        a[i][j] = INT_MAX;
      else
        a[i][j] = 0;
    }
  }
  for (int i = 1; i <= k; i++)
  {
    cin >> u >> v >> w;
    a[u][v] = w;
    a[v][u] = w;
  }
  x[1] = 1;
  Try(2);
  cout << bestConfig << '\n';
  for (int i = 1; i <= n; i++)
    cout << best[i] << "->";
  cout << 1 << '\n';
  return 0;
}