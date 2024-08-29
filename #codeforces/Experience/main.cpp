#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MAXN = 2e5 + 1;
int n, m;

struct Player
{
  int team;
  int exp;
  int rank;
  Player(int _team)
  {
    team = _team;
    exp = 0;
    rank = 1;
  }
};

Player *players[MAXN];

int get_team(int x)
{
  if (x == players[x]->team)
    return x;
  players[x]->team = get_team(players[x]->team);
  return players[x]->team;
}

void union_team(int a, int b)
{
  a = get_team(a);
  b = get_team(b);
  if (a == b)
    return;
  if (players[a]->rank == players[b]->rank)
    players[a]->rank++;
  if (players[a]->rank > players[b]->rank)
    players[b]->team = a;
  else
    players[a]->team = b;
}

void add_exp(int a, int exp)
{
  return;
}

int main()
{
  cin.tie(NULL);
  cout.tie(NULL);
  ios_base::sync_with_stdio(false);
  freopen("Experience.INP", "r", stdin);
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    players[i] = new Player(i);
  string cmd;
  while (m--)
  {
    cin >> cmd;
    if (cmd == "add")
    {
      int x, e;
      cin >> x >> e;
      add_exp(x, e);
    }
    else if (cmd == "join")
    {
      int a, b;
      cin >> a >> b;
      union_team(a, b);
    }
    else
      continue;
  }
  for (int i = 1; i <= n; i++)
    cout << players[i]->rank << ' ';
  return 0;
}