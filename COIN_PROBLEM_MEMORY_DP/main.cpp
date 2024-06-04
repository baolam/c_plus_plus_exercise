#include <bits/stdc++.h>
#define maxn 100002

using namespace std;
typedef long long ll;

ll n, s, INF = maxn;
bool ok[maxn];
ll a[maxn], mem[maxn];

ll solve(ll x)
{
    if (x < 0) return INF;
    if (x == 0) return x;
    if (ok[x]) return mem[x];
    ll bst = INF;
    for (ll i = 1; i <= n; i++)
        bst = min(bst, solve(x - coins[i]) + 1);
    return bst;
}

int main()
{
    memset(ok, false, sizeof(ok));
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen("VAO.INP", "r", stdin);
    freopen("RA.OUT", "w", stdout);
    cin >> n >> s;
    for (ll i = 1; i <= n; i++)
        cin >> a[i];
    cout << solve(s);
    return 0;
}
