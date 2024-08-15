#include <bits/stdc++.h>
#define N 5002

using namespace std;
typedef long long ll;
typedef pair < ll, ll > II;
typedef vector < II > VII;

VII G[N];
ll trace[N];
ll d[N];
ll n, m;

ll dijkstra(ll u);

int main()
{
    cin >> n >> m;
    ll k, u, v, l;
    for (ll i = 1; i <= m; i++)
    {
        cin >> k >> u >> v >> l;
        G[u].push_back({ v, l });
        if (k == 2)
            G[v].push_back({ u, l });
    }

    ll res = dijkstra(1);
    /*
    for (ll i = 1; i <= n; i++)
        cout << trace[i] << ' ';
    */

    return 0;
}

ll dijkstra(ll u)
{
    for (ll i = 1; i <= n; i++) {
        d[i] = LONG_MAX;
        trace[i] = -1;
    }

    priority_queue< II, VII, greater<II> > h;
    d[u] = 0;
    h.push({ u, 0 });

    while (! h.empty())
    {
        II obj = h.top();
        h.pop();

        /// Kiểm tra chi phí
        ll u = obj.first;
        ll cost = obj.second;

        if (cost > d[u])
            continue;

        for (ll j = 0; j < G[u].size(); j++)
        {
            II nobj = G[u][j];
            ll v = nobj.first;
            ll w = nobj.second;

            if (d[v] > d[u] + w)
            {
                d[v] = d[u] + w;
                h.push({ v, d[v] });
                trace[v] = u;
            }
        }
    }

    return d[n];
}
