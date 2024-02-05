#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll t;
ll l, r;

ll ok(ll x);

int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> t;
    for (ll i = 1; i <= t; i++)
    {
        cin >> l >> r;
        ll k = -1;
        for (ll x = 2; x <= r; x++)
        {
            ll c = ok(x);
            k = max(k, c);
            if (c < k)
                break;
        }
        cout << "Case #" << i << ": " << k << '\n';
    }
    return 0;
}

float log_base(ll a, ll b)
{
    // logb(a)
    return log2(a) / log2(b);
}

ll ok(ll x)
{
    ll _max = (ll) log_base(r, x);
    float t = log_base(l, x);
    float r = t - (int) t;
    ll _min = t;
    if (r != 0)
        _min += 1;
    if (_min > _max)
        return -1;
    return _max;
}
