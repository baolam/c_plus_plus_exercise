#include <bits/stdc++.h>
#define MAXN 102
#define MAXK 10002

using namespace std;

int n, k;
int a[MAXN];
bool f[MAXK];

int main()
{
  memset(f, false, sizeof(f));

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  freopen("TEST.INP", "r", stdin);

  cin >> n >> k;
  for (int i = 1; i <= n; i++)
    cin >> a[i];

  for (int i = 1; i <= k; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      if (i >= a[j] && !f[i - a[j]])
        f[i] = 1;
    }
  }

  if (f[k])
    cout << "First";
  else
    cout << "Second";

  return 0;
}