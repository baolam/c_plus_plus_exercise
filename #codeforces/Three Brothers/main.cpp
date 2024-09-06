#include <bits/stdc++.h>
using namespace std;

int a, b;
bool x[4];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  memset(x, false, sizeof(x));
  cin >> a >> b;
  x[a] = true;
  x[b] = true;
  for (int i = 1; i <= 3; i++)
  {
    if (!x[i])
    {
      cout << i;
      break;
    }
  }
  return 0;
}