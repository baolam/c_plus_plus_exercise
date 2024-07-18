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
    cin >> n >> L >> U;
    for (ll i = 1; i <= n; i++)
        cin >> a[i];
    ll ans = 0, l = 1, r = 1;
    //a[0] = INT_MAX;
    while (l <= r && r <= n)
    {
        if (hm[a[r]] == 0)
            distinct++;
        if (distinct < L)
        {
            hm[a[r]]++;
            r++;
        }
        if (distinct > U)
        {
            if (hm[a[l]] == 1)
                distinct--;
            hm[a[l]]--;
            l++;
        }
        if (L <= distinct && distinct <= U)
        {
            ans++;
            r++;
        }
    }
    cout << ans;
    return 0;
}
