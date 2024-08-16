#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int w, h, n;

bool f(ll x)
{
    ll tmpw = x / w;
    ll tmph = x / h;
    return tmpw * tmph >= n;
}

ll searchR()
{
    ll r = 1;
    while (!f(r))
        r *= 2;
    return r;
}

ll bSearch()
{
    ll l = 1;
    ll r = searchR();
    while (l < r - 1)
    {
        ll m = (l + r) / 2;
        if (!f(m))
            l = m;
        else
            r = m;
    }
    return r;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> w >> h >> n;
    cout << bSearch() << '\n';
    return 0;
}
