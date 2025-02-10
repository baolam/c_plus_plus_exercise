#include <bits/stdc++.h>
#define MAXN 1020

using namespace std;

struct MyQueue
{
  int first, last;

  vector<int> u, v;
  MyQueue() : first(-1), last(0)
  {
    u.resize(4 * MAXN * MAXN);
    v.resize(4 * MAXN * MAXN);
  }

  void push(int uu, int vv, int d, vector<vector<int>> &dd)
  {
    if (uu < -1010 || vv < -1010 || uu > 1010 || vv > 1010)
      return;
    if (dd[uu + MAXN][vv + MAXN] > 0)
      return;
    dd[uu + MAXN][vv + MAXN] = d;
    u[last] = uu;
    v[last] = vv;
    last++;
  }

  void pop(int &uu, int &vv)
  {
    first++;
    uu = u[first];
    vv = v[first];
  }
};

int mx,
    my, tx, ty, first;
const int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
const int dy[8] = {-1, 1, -2, 2, -2, 2, -1, 1};

vector<vector<int>> dd;
MyQueue mQueue;

void init()
{
  mQueue.first = -1;
  mQueue.last = 0;

  if (first == 1)
  {
    mQueue.push(mx, my, 1, dd);
  }
  else
  {
    for (int dir = 0; dir <= 7; dir++)
    {
      mQueue.push(mx + dx[dir], mx + dy[dir], 2, dd);
    }
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  freopen("TEST.INP", "r", stdin);

  cin >> mx >> my >> tx >> ty;
  cin >> first;

  dd.assign(2 * MAXN + 1, vector<int>(2 * MAXN + 1, 0));
  init();

  while (mQueue.first <= mQueue.last)
  {
    int u, v;
    mQueue.pop(u, v);

    int d = dd[u + MAXN][v + MAXN];
    int goodx = tx - (d - 1) / 2;

    if (u == goodx && v == ty)
    {
      cout << "YES" << '\n';
      cout << d - 1;
      return 0;
    }

    for (int dir = 0; dir <= 7; dir++)
    {
      int x = u + dx[dir];
      int y = v + dy[dir];

      if (dd[x + MAXN][y + MAXN] > 0)
        continue;
      if (x == goodx && y == ty)
      {
        cout << "YES" << '\n';
        cout << d;
        return 0;
      }

      mQueue.push(x, y, d + 1, dd);
    }
  }

  cout << "NO";

  return 0;
}