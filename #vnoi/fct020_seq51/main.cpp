#include <bits/stdc++.h>
#define MAXN 100003

using namespace std;

int n;
int a[MAXN];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  freopen("TEST.INP", "r", stdin);

  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> a[i];

  int ans = 1;
  for (int l = 1; l <= n; l++)
  {
    // l là vị trí bắt đầu
    for (int r = l; r <= n; r++)
    {
      if (a[r] >= r - l + 1)
        ans = max(ans, r - l + 1);
      else
        break;
    }
  }

  cout << ans;
  return 0;
}