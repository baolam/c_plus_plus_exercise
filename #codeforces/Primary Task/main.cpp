#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int t;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  // freopen("VAO.INP", "r", stdin);
  cin >> t;
  string x;
  while (t--)
  {
    bool flag = true;
    cin >> x;
    if (x.size() <= 2)
      flag = false;
    else
    {
      if (x[0] != '1' || x[1] != '0' || x[2] == '0')
        flag = false;
      else
      {
        int tmp = 0;
        for (int i = 2; i < x.size(); i++)
        {
          tmp = tmp * 10 + (x[i] - '0');
          if (tmp >= 2)
            break;
        }
        if (tmp < 2)
          flag = false;
      }
    }
    if (flag)
      cout << "YES" << '\n';
    else
      cout << "NO" << '\n';
  }
  return 0;
}