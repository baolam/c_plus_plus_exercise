#include <bits/stdc++.h>
#define maxn 10000

using namespace std;
typedef long long ll;

ll coins[maxn], n, s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen("VAO.INP", "r", stdin);
    freopen("RA.OUT", "w", stdout);
    cin >> n >> s;
    for (ll i = 1; i <= n; i++)
        cin >> coins[i];
    sort(coins+1, coins+1+n, greater<ll> ());
    ll res = 0, i = 1;
    while (s != 0 && i <= n)
    {
        if (s > coins[i])
            s -= coins[i], res++;
        else i++;
    }
    cout << res;
    return 0;
}
