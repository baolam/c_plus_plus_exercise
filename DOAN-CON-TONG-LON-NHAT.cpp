/****
#include <bits/stdc++.h>
#define N 50001

using namespace std;
typedef long long ll;

ll n;
ll a[N], b[N], f[4 * N];

void update(ll id, ll l, ll r);

int main()
{
    b[0] = 0;
    cin >> n;
    for (ll i = 1; i <= n; i++)
    {
        cin >> a[i];
        b[i] = b[i - 1] + a[i];
    }

    update(1, 1, n);

    return 0;
}

void update(ll id, ll l, ll r)
{
    if (l == r)
    {
        f[id] = b[l];
        return;
    }

    ll m = (l + r) / 2;
    update(2 * id, 1, m);
    update(2 * id + 1, m + 1, r);

    f[id] = max(f[2 * id], f[2 * id + 1]);
}

ll _get(ll x, ll y)
{

}
****/

#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

