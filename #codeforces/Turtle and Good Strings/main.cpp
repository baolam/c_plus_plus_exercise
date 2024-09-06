#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int t, n;
string s;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> t;
  while (t--)
  {
    cin >> n;
    if (n < 2)
      cout << "NO" << '\n';
    else
    {
      cin >> s;
      if (s[0] == s[n - 1])
        cout << "NO" << '\n';
      else
        cout << "YES" << '\n';
    }
  }
  return 0;
}