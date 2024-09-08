#include <bits/stdc++.h>

using namespace std;

int t;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> t;
  int x;
  while (t--)
  {
    cin >> x;
    cout << x / 10 + x % 10 << '\n';
  }
  return 0;
}