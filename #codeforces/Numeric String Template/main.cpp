#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MAXN = 2e5 + 1;
int n, m, t;
string s;
int a[MAXN];

bool check()
{
  unordered_map<char, int> ma;
  unordered_map<int, char> st;
  for (int i = 0; i < s.size(); i++)
  {
    if (ma.find(s[i]) != ma.end() && ma[s[i]] != a[i])
      return false;
    if (st.find(a[i]) != st.end() && st[a[i]] != s[i])
      return false;
    ma[s[i]] = a[i];
    st[a[i]] = s[i];
  }
  return true;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  // freopen("Numeric String Template.INP", "r", stdin);
  cin >> t;
  while (t--)
  {
    cin >> n;
    for (int i = 0; i < n; i++)
      cin >> a[i];
    cin >> m;
    while (m--)
    {
      cin >> s;
      if (s.size() != n || !check())
        cout << "NO" << '\n';
      else
        cout << "YES" << '\n';
    }
  }
  return 0;
}