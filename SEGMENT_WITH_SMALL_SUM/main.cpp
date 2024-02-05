#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll n, m;
    cin >> n >> m;

    ll a[n];
    for (ll i = 0; i < n; i++) cin >> a[i];

    ll l = 0, r;
    ll sum = 0;
    ll ans = 0;

    // Duyệt r, tìm l thỏa segment có chiều dài = ...
    // chiều dài lớn nhất tách ra thành chiều dài, lớn nhất
    for (r = 0; r < n; r++)
    {
        sum += a[r];
        while (sum > m)
        {
            sum -= a[l]; ++l;
        }
        ans = max(ans, r - l + 1);
    }

    cout << ans;
    return 0;
}
