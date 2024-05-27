#include <bits/stdc++.h>
#define maxn 201

using namespace std;
typedef int ll;

ll n, a, b, gtln;
ll t[maxn], edge[maxn][maxn], trace[maxn];

bool bfs(ll val)
{
    memset(trace, 0, sizeof(trace));
    queue<ll> q;
    q.push(a);
    while (! q.empty())
    {
        ll u = q.front();
        if (u == b)
            return true;
        for (ll v = 1; v <= n; v++)
        {
            if (edge[u][v] && trace[v] == 0 && (abs(t[v] - t[u]) <= val))
            {
                q.push(v);
                trace[v] = u;
            }
        }
        q.pop();
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen("VAO.INP", NULL, stdin);
    freopen("RA.OUT", NULL, stdout);
    cin >> n >> a >> b;
    for (ll i = 1; i <= n; i++)
        cin >> t[i], gtln = max(gtln, t[i]);
    ll u, v;
    for (ll i = 1; i <= n; i++)
    {
        cin >> u >> v;
        edge[u][v] = 1;
        edge[v][u] = 1;
    }
    ll l = 0, r = gtln, res = -1;
    while (l <= r)
    {
        ll m = l + (r - l) / 2;
        if (bfs(m))
        {
            res = m;
            r = m - 1;
        }
        else l = m + 1;
    }
    cout << res;
    return 0;
}
