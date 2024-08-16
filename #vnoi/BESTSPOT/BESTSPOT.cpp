#include <bits/stdc++.h>
#define N 502

using namespace std;
typedef long long ll;
typedef pair < ll, ll > II;
typedef vector < II > VII;

VII G[N];
bool visited[N];
ll d[N];
ll p, n, c;
ll F[N];

ll dijkstra(ll u);

int main()
{
    cin >> p >> n >> c;
    for (ll i = 1; i <= n; i++)
        cin >> F[i];
    ll a, b, f;
    for (ll i = 1; i <= c; i++)
    {
        cin >> a >> b >> f;
        G[a].push_back({ b, f });
        G[b].push_back({ a, f });
    }

    ll m = LONG_MAX, index = -1;
    for (ll i = 1; i <= p; i++)
    {
        ll k = dijkstra(i);
        if (m > k)
        {
            m = k;
            index = i;
        }
    }

    cout << index;
    return 0;
}

ll dijkstra(ll u)
{
    for (ll i = 1; i <= p; i++) {
        visited[i] = false;
        d[i] = LONG_MAX;
    }

    priority_queue< II, VII, greater<II> > h;
    d[u] = 0;

    h.push({ u, d[u] });
    while(! h.empty())
    {
        II res = h.top();
        h.pop();

        ll _u = res.first;
        if (res.second > d[_u])
            continue;
        //if (visited[u])
            //continue;
        //visited[u] = true;

        for (ll j = 0; j < G[_u].size(); j++)
        {
            II _edges = G[_u][j];
            ll v = _edges.first;
            ll w = _edges.second;

            if (d[v] > d[_u] + w)
            {
                d[v] = d[_u] + w;
                h.push({ v, d[v] });
            }
        }
    }

    ll r = 0;
    for (ll i = 1; i <= n; i++)
        r += d[ F[i] ];
    return r;
}
