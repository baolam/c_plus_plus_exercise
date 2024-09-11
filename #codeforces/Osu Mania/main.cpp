#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int t;
int n;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  freopen("vao.INP", "r", stdin);

  cin >> t;
  while (t--)
  {
    cin >> n;
    string x;
    for (int i = 1; i <= n; i++)
    {
      cin >> x;
      for (int j = 0; j < x.size(); j++)
      {
        if (x[j] == '#')
        {
          cout << n - j << ' ';
          break;
        }
      }
    }
    cout << '\n';
  }
  return 0;
}