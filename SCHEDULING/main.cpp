#include <bits/stdc++.h>
#define maxn 100002

using namespace std;
typedef long long ll;
typedef pair<ll,ll> II;

ll n;
II a[maxn];

bool compare(II x, II y)
{
    if (x.second == y.second)
        return x.first <= y.first;
    return x.second <= y.second;
}

bool intersect(ll a, ll b, ll c, ll d)
{
    return max(a, c) < min(b, d);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen("VAO.INP", "r", stdin);
    //freopen("RA.OUT", "w", stdout);
    cin >> n;
    for (ll i = 1; i <= n; i++)
        cin >> a[i].first >> a[i].second;
    sort(a + 1, a + 1 + n, compare);
    ll res = 1, st = a[1].first, en = a[1].second;
    for (ll i = 2; i <= n; i++)
    {
        if (! intersect(st, en, a[i].first, a[i].second))
        {
            res++;
            st = a[i].first;
            en = a[i].second;
        }
    }
    cout << res;
    return 0;
}
