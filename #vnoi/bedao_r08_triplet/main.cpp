#include <bits/stdc++.h>
#define maxk 200001

using namespace std;
typedef long long ll;

int n, k;
int cnt[maxk];

int calculate_cases(int ra, int rb, int rc)
{
  if (ra == rb && rb == rc)
    return cnt[ra] * (cnt[ra] - 1) * (cnt[ra] - 2) / 6;
  if (ra == rb)
    return cnt[ra] * (cnt[ra] - 1) / 2 * cnt[rc];
  if (rb == rc)
    return cnt[rb] * (cnt[rb] - 1) / 2 * cnt[ra];
  if (rc == ra)
    return cnt[rc] * (cnt[rc] - 1) / 2 * cnt[rb];
  return cnt[ra] * cnt[rb] * cnt[rc];
}

int main()
{
  memset(cnt, 0, sizeof(cnt));
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> k;
  for (int i = 1; i <= n; i++)
    cnt[i % k]++;
  ll result = 0;
  for (int r_a = 0; r_a < k; r_a++)
  {
    for (int r_b = r_a; r_b < k; r_b++)
    {
      int r_c = (k - (r_a + r_b) % k) % k;
      result += calculate_cases(r_a, r_b, r_c);
    }
  }
  cout << result;
  return 0;
}