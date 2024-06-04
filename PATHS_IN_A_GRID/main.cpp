#include <bits/stdc++.h>
#define maxn 1002

using namespace std;
typedef long long ll;

ll n;
ll a[maxn][maxn], f[maxn][maxn];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    memset(f, 0, sizeof(f));
    cin >> n;
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 1; j <= n; j++)
            cin >> a[i][j];
    }
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 1; j <= n; j++)
            f[i][j] = max(f[i][j - 1], f[i - 1][j]) + a[i][j];
    }
    cout << f[n][n];
    return 0;
}
