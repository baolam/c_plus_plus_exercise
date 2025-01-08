#include <bits/stdc++.h>

using namespace std;

string _template = "virus";
string s;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> s;
  int ans = 0;

  for (int i = 0; i < s.size(); i++)
  {
    if (s[i] == 'v' && i + _template.size() - 1 < s.size())
    {
      bool flag = true;
      for (int k = i; k < i + _template.size(); k++)
      {
        if (s[k] != _template[k - i])
        {
          flag = false;
          break;
        }
      }
      if (flag)
        ans++;
    }
  }

  cout << ans;
  return 0;
}