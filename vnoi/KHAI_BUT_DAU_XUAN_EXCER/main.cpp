#include <bits/stdc++.h>
#define maxn 1500001

using namespace std;
typedef long ll;

ll n, L, U;
ll a[maxn];

ll calc_distinct(ll X)
{
    if (X == 0) return 0;
    unordered_map<ll, ll> hm;
    ll ans = 0, distinct = 0;
    for (ll l = 1, r = 1; r <= n; r++)
    {
        if (hm[a[r]] == 0)
            distinct++;
        hm[a[r]]++;
        while (distinct > X && l < r)
        {
            if (hm[a[l]] == 1)
                distinct--;
            hm[a[l]]--; l++;
        }
        ans += r - l + 1;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    //freopen("VAO.INP", "r", stdin);
    cin >> n >> L >> U;
    for (ll i = 1; i <= n; i++)
        cin >> a[i];
    ll s1 = calc_distinct(U);
    ll s2 = calc_distinct(L - 1);
    cout << s1 - s2;
    return 0;
}
