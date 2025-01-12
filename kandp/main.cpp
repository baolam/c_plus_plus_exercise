#include <bits/stdc++.h>
#define MAXN 1000

using namespace std;

struct Infor
{
  int x, y;
  int step;
  int distance;
  Infor(int _x, int _y, int _step, int _distance)
  {
    x = _x;
    y = _y;
    step = _step;
    distance = _distance;
  }

  bool operator<(const Infor &other) const
  {
    return distance < other.distance;
  }

  bool operator>(const Infor &other) const
  {
    return distance > other.distance;
  }
};

int pMx[9] = {-1, -2, -2, -1, 1, 2, 2, 1};
int pMy[9] = {-2, -1, 1, 2, 2, 1, -1, -2};

int Mx, My, Tx, Ty;
int prior;

bool validStep(int x, int y)
{
  return -MAXN <= x && x <= MAXN && -MAXN <= y && y <= MAXN;
}

int estimate(int cMx, int cMy, int cTx, int cTy)
{
  return abs(cTx - cMx) + abs(cTy - cMy);
}

int dijkstra_step(int tX, int tY)
{
  priority_queue<Infor, vector<Infor>, greater<Infor>> pq;
  pq.push({Mx, My, 0, estimate(Mx, My, tX, tY)});

  while (!pq.empty())
  {
    Infor cur = pq.top();
    pq.pop();

    if (cur.x == tX && cur.y == tY)
    {
      return cur.step;
    }

    for (int i = 0; i <= 7; i++)
    {
      int nX = cur.x + pMx[i];
      int nY = cur.y + pMy[i];
      if (!validStep(nX, nY))
        continue;
      int _estimate = estimate(nX, nY, tX, tY);
      if (_estimate > cur.distance)
        continue;
      pq.push({nX, nY, cur.step + 1, cur.distance + _estimate});
    }
  }

  return -1;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  freopen("TEST.INP", "r", stdin);

  cin >> Mx >> My >> Tx >> Ty;
  cin >> prior;

  int ans = 0;
  if (prior)
    Tx--;
  for (int step = 1; Tx - step >= -MAXN; step++)
  {
    int minSteps = dijkstra_step(Tx - step + 1, Ty);
    if (prior && minSteps > step)
      break;
    if (minSteps != -1 && minSteps == step)
    {
      ans = step;
      break;
    }
  }

  if (ans == 0)
    cout << "NO";
  else
  {
    cout << "YES" << '\n';
    cout << ans;
  }

  return 0;
}