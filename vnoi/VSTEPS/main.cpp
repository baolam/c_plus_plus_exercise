#include <bits/stdc++.h>
#define maxn 100002

using namespace std;
typedef unsigned long long ll;

const ll mod = 14062008;

ll n, k;
ll dp[maxn];
bool hong[maxn];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    memset(dp, 0, sizeof(dp));
    memset(hong, false, sizeof(hong));

    cin >> n >> k;

    ll x;
    for (ll i = 1; i <= k; i++)
        cin >> x, hong[x] = true;
    dp[1] = 1;
    if (! hong[2])
        dp[2] = 1;
    for (ll i = 3; i <= n; i++)
    {
        if (! hong[i]) dp[i] = (dp[i - 1] + dp[i - 2]) % mod;
    }
    cout << dp[n];
    return 0;
}
