#include <bits/stdc++.h>
#define maxn 2000001

using namespace std;
typedef int ll;

unordered_map<ll, ll> hm;
ll n, L, U, distinct = 0;
ll a[maxn];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen("VAO.INP", "r", stdin);
    cin >> n >> L >> U;
    for (ll i = 1; i <= n; i++)
        cin >> a[i];
    ll ans = 0;
    for (ll l = 1, r = 1; r <= n; r++)
    {
        if (hm[a[r]] == 0)
            distinct++;
        hm[a[r]]++;
        if (L <= distinct && distinct <= U)
            ans++;
        while (distinct >= L)
        {
            if (hm[a[l]] == 1)
                distinct--;
            hm[a[l]]--;
            l++; ans++;
        }
    }
    cout << ans;
    return 0;
}
