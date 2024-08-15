#include <bits/stdc++.h>
#define maxn 10000000

using namespace std;
typedef long long ll;

ll n, m, gtnn = INT_MAX, sum = 0;
ll a[maxn];

bool xep_duoc(ll k)
{
    ll s = 0, cnt = 1;
    for (ll i = 1; i <= n; i++)
    {
        if (s + a[i] <= k)
            s += a[i];
        else {
            if (a[i] > k)
                return false;
            cnt++;
            if (cnt > m)
                return false;
            s = a[i];
        }
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i], gtnn = min(gtnn, a[i]), sum += a[i];
    ll l = gtnn - 1, r = sum + 1;
    ll ans = 0;
    while (l < r)
    {
        ll m = l + (r - l) / 2;
        if (xep_duoc(m))
        {
            ans = m;
            r = m - 1;
        }
        else l = m + 1;
    }
    cout << ans;
    return 0;
}
