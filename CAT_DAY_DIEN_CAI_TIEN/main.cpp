#include <bits/stdc++.h>
#define maxn 100002

using namespace std;
typedef long long ll;

ll n, k, sum = 0;
ll a[maxn];

bool check(ll x)
{
    ll cnt = 0;
    for (int i = 1; i <= n; i++) {
        cnt += a[i] % x;
        if (cnt >= k)
            return true;
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i], sum += a[i];
    // Nhận xét
    // Hàm có dạng check(x)
    // false false false true true ....
    // Dùng tính chất tìm kiếm nhị phân trên dạng hàm như vậy
    ll l = 1, r = sum / k;
    ll res = 0;
    while (l <= r)
    {
        ll m = (l + r) / 2;
        if (check(m))
        {
            res = m;
            l = m + 1;
        }
        else r = m - 1;
    }
    cout << -1;
    return 0;
}
