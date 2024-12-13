#include <bits/stdc++.h>
#define maxn 200001

using namespace std;
typedef long long ll;

int a[maxn], n;
map<int, int> table;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;
  for (int i = 1; i <= n; i++)
  {
    cin >> a[i];
    a[i] %= 23;
  }
  ll ans = 0;
  for (int i = 1; i <= n; i++)
  {
    if (i > 6)
      table[a[i - 6]]++;
    ans += table[a[i]];
  }
  cout << ans;
  return 0;
}