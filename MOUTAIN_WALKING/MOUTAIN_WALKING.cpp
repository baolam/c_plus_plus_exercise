#include <bits/stdc++.h>
#define maxn 102

using namespace std;
typedef int ll;
typedef pair<ll, ll> II;

bool visited[maxn][maxn];
ll hx[5] = { -2, 0, 0, 1, -1 };
ll hy[5] = { -2, -1,1, 0, 0 };
ll n;
ll a[maxn][maxn];

bool Loang(ll _min, ll delta)
{
    memset(visited, false, sizeof(visited));
    queue<II> q;
    q.push({1, 1});
    while (! q.empty())
    {
        ll u = q.front().first;
        ll v = q.front().second;
        q.pop();
        if (a[u][v] < _min || a[u][v] > _min + delta)
            continue;
        if (u == n && v == n)
            return true;
        for (ll k = 1; k <= 4; k++)
        {
            ll i = u + hx[k];
            ll j = v + hy[k];
            if (i < 0 || j < 0 || i > n || j > n)
                continue;
            if (a[i][j] >= _min && a[i][j] <= _min + delta && ! visited[i][j])
            {
                visited[i][j] = true;
                q.push({i, j});
            }
        }
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen("VAO.INP", "r", stdin);
    freopen("RA.OUT", "w", stdout);
    cin >> n;
    ll dmin = 111, dmax = 0, res = 111;
    for (ll i = 1; i <= n; i++)
    {
        for(ll j = 1; j <= n; j++)
        {
            cin >> a[i][j];
            dmin = min(dmin, a[i][j]);
            dmax = max(dmax, a[i][j]);
        }
    }
    for (ll _min = dmin; _min <= dmax; _min++)
    {
        ll l = 0, r = dmax - dmin;
        while (l < r)
        {
            ll m = l + (r - l) / 2;
            if (Loang(_min, m))
            {
                r = m - 1;
                res = min(res, m);
            }
            else l = m + 1;
        }
    }
    cout << res;
    return 0;
}
