#include <bits/stdc++.h>
#define N 100002

using namespace std;
typedef long long ll;
typedef vector < ll > V;

ll n, m;
ll d[N];
bool checked[N];
V G[N];

ll dfs(ll s);

int main()
{
    cin >> n >> m;
    for (ll i = 1; i <= n; i++)
    {
        checked[i] = false;
        d[i] = 0;
    }

    ll x, y;
    for (ll i = 1; i <= m; i++)
    {
        cin >> x >> y;
        G[x].push_back(y);
    }

    for (ll i = 1; i <= n; i++)
    {
        if (checked[i] == false)
        {
            checked[i] = true;
            d[i] = dfs(i);
        }
    }

    cout << *max_element(d+1, d+1+n);
    return 0;
}

ll dfs(ll s)
{
    for (ll j = 0; j < G[s].size(); j++)
    {
        ll v = G[s][j];
        if (! checked[v])
        {
            checked[v] = true;
            d[v] = dfs(v);
        }
        d[s] = max(d[s], d[v] + 1);
    }
    return d[s];
}
