#include <bits/stdc++.h>
#define maxn 102

using namespace std;
typedef long long ll;

ll n;
ll a[maxn];

ll solve(ll x)
{
    ll bst = 1;
    for (ll i = 1; i < x; i++)
    {
        if (a[x] > a[i])
            bst = max(bst, solve(i) + 1);
    }
    return bst;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen("VAO.INP", "r", stdin);
    //freopen("RA.OUT", "w", stdout);
    cin >> n;
    for (ll i = 1; i <= n; i++)
        cin >> a[i];
    ll res = 1;
    for (ll i = 1; i <= n; i++)
        res = max(res, solve(i));
    cout << res;
    //cout << solve(n);
    return 0;
}
