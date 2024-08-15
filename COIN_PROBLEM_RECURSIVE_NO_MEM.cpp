#include <bits/stdc++.h>
#define maxn 102

using namespace std;
typedef long long ll;

ll INF = 1000000;
ll n, s;
ll coins[maxn];

ll solve(ll x)
{
    if (x < 0)
        return INF;
    if (x == 0)
        return 0;
    ll best = INF;
    for (ll i = 1; i <= n; i++)
        best = min(best, solve(x - coins[i]) + 1);
    return best;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen("VAO.INP", "r", stdin);
    freopen("RA.OUT", "w", stdout);
    cin >> n >> s;
    for (ll i = 1; i <= n; i++)
        cin >> coins[i];
    cout << solve(s);
    return 0;
}
