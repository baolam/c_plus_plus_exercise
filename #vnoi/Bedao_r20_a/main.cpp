#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int t;
ll n;

int solve()
{
  cin >> n;
  if (n % 16 != 0)
    return 0;
  n /= 16;
  ll tmp = sqrtl(n), ans = 0;
  if (tmp * tmp != n)
    return 0;
  for (int i = 1; i * i <= tmp; i++)
  {
    if (tmp % i == 0)
    {
      ans++;
      if (i != tmp / i)
        ans++;
    }
  }
  return ans;
}

int main()
{
  cin.tie(NULL);
  cout.tie(NULL);
  ios_base::sync_with_stdio(false);
  cin >> t;
  while (t--)
  {
    cout << solve() << '\n';
  }
  return 0;
}