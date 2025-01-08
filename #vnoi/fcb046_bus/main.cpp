#include <bits/stdc++.h>
#define MAXP 100005

using namespace std;

int n, m, p;
vector<int> station[MAXP];

int f(int startTime)
{
  int ans = 0;
  int arriveStation = 0;
  for (int i = 1; i <= p; i++)
  {
    for (auto passengerTime : station[i])
    {
      if (startTime + arriveStation >= passengerTime)
        ans++;
    }
    arriveStation++;
  }
  return ans;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  freopen("TEST.INP", "r", stdin);

  cin >> n >> m >> p;
  int a, t;
  int maxTime = 0;

  for (int i = 1; i <= n; i++)
  {
    cin >> a >> t;
    station[a].push_back(t);
    maxTime = max(maxTime, t);
  }

  for (int i = 1; i <= p; i++)
    sort(station[i].begin(), station[i].end());

  int l = 0, r = maxTime;

  while (l < r)
  {
    int mid = (l + r) / 2;
    if (f(mid) >= m)
      r = mid;
    else
      l = mid + 1;
  }

  cout << r;
  return 0;
}