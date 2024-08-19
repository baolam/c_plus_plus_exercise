#include <bits/stdc++.h>
#define int long long
// #define HAS_FILE

#ifdef HAS_FILE
#define FILE_NAME "CH"
#define READ FILE_NAME ".INP"
#define WRITE FILE_NAME ".OUT"
#endif

using namespace std;

const int MAXM = 15001;
const int MAXN = 1001;

struct Node
{
  int t = 0;
  int z = 0;
  int y = 0;
};

int m,
    n;
int best[MAXN];
Node a[MAXN];

bool isPossibleBalloons(int balloons, int i, int time)
{
  // Phần thủ tục tính số thời gian thổi balloons quả bóng
  int t = a[i].t;
  int z = a[i].z;
  int y = a[i].y;
  int batchTime = t * z + y;
  int batches = balloons / z;
  bool ok = (balloons % z == 0) ? 1 : 0;

  int curTime = 0;
  if (ok)
  {
    batches--;
    curTime = batchTime * batches + z * t;
  }
  else
    curTime = batchTime * batches + (balloons % z) * t;

  // Phần kiểm tra điều kiện
  return curTime <= time;
}

bool isPossible(int time)
{
  int total = 0;
  for (int i = 1; i <= n; i++)
  {
    int lo = 0, ro = 1e9;
    while (lo < ro - 1)
    {
      int balloons = (lo + ro) / 2;
      // 1 1 1 1 0 0 0
      if (isPossibleBalloons(balloons, i, time))
        lo = balloons;
      else
        ro = balloons;
    }
    // lo : số quả bóng tối đa thổi bởi trợ lý i trong thời gian time
    total += lo;
  }
  return total >= m;
}

int maxCountBalloons(int i, int time)
{
  int t = a[i].t;
  int z = a[i].z;
  int y = a[i].y;
  int batchTime = t * z + y;
  int batchCount = time / batchTime;
  int remTime = time % batchTime;
  int total = batchCount * z;
  if (remTime)
  {
    if (remTime / t >= z)
      total += z;
    else
      total += remTime / t;
  }
  return total;
}

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
#ifdef HAS_FILE
  freopen(READ, "r", stdin);
  freopen(WRITE, "w", stdout);
#endif
  cin >> m >> n;
  for (int i = 1; i <= n; i++)
    cin >> a[i].t >> a[i].z >> a[i].y;
  int timeL = -1, timeR = 1e9;
  while (timeL < timeR - 1)
  {
    int timeM = (timeL + timeR) / 2;
    if (isPossible(timeM))
      timeR = timeM;
    else
      timeL = timeM;
  }
  cout << timeR << '\n';
  int total = 0;
  for (int i = 1; i <= n; i++)
    best[i] = maxCountBalloons(i, timeR);
  for (int i = 1; i <= n; i++)
  {
    if (total + best[i] <= m)
    {
      cout << best[i] << ' ';
      total += best[i];
    }
    else
    {
      if (total == m)
        cout << 0 << ' ';
      else
      {
        cout << m - total << ' ';
        total = m;
      }
    }
  }
  return 0;
}