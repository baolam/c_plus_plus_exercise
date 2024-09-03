#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXN = 50;

int t, n;
int x;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> t;
  while (t--)
  {
    cin >> n;
    int sum = 0;
    bool flag = true;
    for (int i = 0; i < n; i++)
    {
      cin >> x;
      if (flag)
        sum += x;
      else
        sum -= x;
      flag = !flag;
    }
    cout << sum << '\n';
  }
  return 0;
}