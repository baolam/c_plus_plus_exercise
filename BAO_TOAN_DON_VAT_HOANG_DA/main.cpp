#include <bits/stdc++.h>
#define maxn 201

using namespace std;
typedef int ll;

ll n, a, b, gtln;
ll t[maxn], edge[maxn][maxn];

bool bfs(ll val)
{
    queue<ll> q;

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
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

    return 0;
}
