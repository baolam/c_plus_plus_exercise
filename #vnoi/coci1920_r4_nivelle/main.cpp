#include <bits/stdc++.h>

using namespace std;

int n;
int count_char[27];
string S;

int main()
{
  memset(count_char, 0, sizeof(count_char));

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> S;

  int l = 0, r = 0, start = 0;
  int unique_colors = 0;

  for (int end = 0; end < n; end++)
  {
    if (count_char[s[end]] == 0)
    {
      unique_colors++;
    }
    count_char[s[end]]++;

    while (unique_colors > 0)
    {
        }
  }
  return 0;
}