#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n, x;
int cnt = 0, sum = 0;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  freopen("CANDIES.INP", "r", stdin);
  freopen("CANDIES.OUT", "w", stdout);
  cin >> n;
  for (int i = 1; i <= n; i++)
  {
    cin >> x;
    if (x > 0 && x % 3 == 0)
    {
      cnt++;
      sum += (x - 3) / 3;
    }
  }
  cout << cnt << '\n';
  cout << sum << '\n';
  return 0;
}