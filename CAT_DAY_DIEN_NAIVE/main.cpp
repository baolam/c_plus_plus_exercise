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
    for (int i = sum / k; i >= 1; i--)
    {
        if (check(i))
        {
            cout << i;
            return 0;
        }
    }
    cout << -1;
    return 0;
}
