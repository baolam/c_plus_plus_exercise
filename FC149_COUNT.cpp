#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ll;

ll n;
ll x[3];

ll identify()
{
  ll res = 0, pos = 0;
  for (int i = 0; i < 3; i++)
  {
      res += n / x[i];
  }
  for (int i = 0; i < 3; i++)
  {
      if (n % x[i] != 0)
      {
          res -= 2 * (n / x[i]);
          break;
      }
  }
  return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    while((cin >> n >> x[0] >> x[1] >> x[2]))
    {
        cout << identify() << '\n';
    }
    return 0;
}
