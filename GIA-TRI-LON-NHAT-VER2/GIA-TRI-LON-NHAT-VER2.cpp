#include <bits/stdc++.h>
#define N 50001

using namespace std;
typedef long long ll;

ll n, m;
ll a[N], f[4 * N];

void build(ll id, ll l, ll r);
void update(ll id, ll l, ll r, ll u, ll v, ll val);
ll _get(ll id, ll l, ll r, ll u, ll v);

int main()
{
    cin >> n >> m;
    for (ll i = 1; i <= n; i++)
        a[i] = 0;

    ll type, x, y, k;
    for (ll i = 1; i <= m; i++)
    {
        cin >> type >> x >> y;
        if (type == 0)
        {
            cin >> k;
            update(1, 1, n, x, y, k);
        }
        else cout << _get(1, 1, n, x, y) << '\n';
    }

    return 0;
}

void build(ll id, ll l, ll r)
{
    if (l == r)
    {
        f[id] = a[l];
        return;
    }

    ll m = (l + r) / 2;
    build(2 * id, l, m);
    build(2 * id + 1, m + 1, r);

    f[id] = max(f[2 * id], f[2 * id + 1]);
}

void update(ll id, ll l, ll r, ll u, ll v, ll val)
{
    if (r < u || v < l)
        return;
    if (l == r)
    {
        //cout << "Update " << l << endl;
        f[id] += val;
        return;
    }

    ll m = (l + r) / 2;
    update(2 * id, l, m, u, v, val);
    update(2 * id + 1, m + 1, r, u, v, val);

    f[id] = max(f[2 * id], f[2 * id + 1]);
}

ll _get(ll id, ll l, ll r, ll u, ll v)
{
    if (r < u || v < l)
        return LONG_MIN;
    if (u <= l && r <= v)
        return f[id];
    ll m = (l + r) / 2;
    return max(
        _get(2 * id, l, m, u, v),
        _get(2 * id + 1, m + 1, r, u, v)
    );
}
