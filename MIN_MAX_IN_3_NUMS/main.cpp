#include <bits/stdc++.h>

using namespace std;

int a[3];

int main()
{
  int gtln = INT_MIN;
  for (int i = 0; i <= 2; i++)
    cin >> a[i], gtln = max(gtln, a[i]);
  cout << gtln << '\n';
  return 0;
}