#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;

int n, x;
ll sumle = 0, sumchan = 0;
ll sole = 0, sochan = 0;

void solve()
{
}

int main()
{
  cin.tie(NULL);
  cout.tie(NULL);
  ios_base::sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i <= n; i++)
  {
    cin >> x;
    if (x % 2 == 0)
      sochan++, sumchan = (sumchan + x) % MOD;
    else
      sole++, sumle = (sumle + x) % MOD;
  }
  if (sochan == 0 || sole == 0)
    cout << 0;
  else
  {
    ll out = ((sole * sumchan) % MOD + (sochan * sumle) % MOD) % MOD;
    cout << out;
  }
  return 0;
}