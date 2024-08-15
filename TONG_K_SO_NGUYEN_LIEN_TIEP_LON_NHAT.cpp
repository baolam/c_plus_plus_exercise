#include <bits/stdc++.h>
#define maxn 10001

using namespace std;
typedef long long ll;

ll n, k, tmp;
ll s[maxn];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    s[0] = 0;
    cin >> n >> k;
    for (ll i = 1; i <= n; i++)
        cin >> tmp, s[i] = s[i - 1] + tmp;
    ll ans = INT_MIN, be, en;
    for (ll i = k; i <= n; i++)
    {
        if (ans < s[i] - s[i - k - 1])
        {
            be = i - k - 1;
            en = i;
            ans = s[i] - s[i - k - 1];
        }
    }
    cout << ans << ' ' << be << ' ' << en;
    return 0;
}
