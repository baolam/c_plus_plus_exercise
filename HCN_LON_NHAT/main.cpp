#include <bits/stdc++.h>
#define maxn 102

using namespace std;
typedef long long ll;

ll m, n;
ll a[maxn][maxn];

ll tong(int d1, int c1, int d2, int c2)
{
    return a[d2][c2] - a[d1 - 1][c2] - a[d2][c1 - 1] + a[d1 - 1][c1 - 1];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen("HCN.INP", "r", stdin);
    freopen("HCN.OUT", "w", stdout);

    cin >> m >> n;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];

    for (int j = 2; i <= n; i++)
        a[1][j] = a[1][j - 1] + a[1][j];
    for (int i = 2; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
            a[i][j] += a[i][j - 1];
        for (int j = 1; j <= n; j++)
            a[i][j] += a[i - 1][j];
    }

    ll ans = INT_MIN, _r1, _c1, _r2, _c2;
    for (int d1 = 1; d1 <= m; d1++)
    {
        for (int c1 = 1; c1 <= n; c1++)
        {
            for (int d2 = d1; d2 <= m; d2++)
            {
                for (int c2 = c1; c2 <= n; c2++)
                {
                    ll t = tong(d1, c1, d2, c2);
                    if (ans < t)
                    {
                        ans = t;
                        _r1 = d1;
                        _c1 = c1;
                        _r2 = d2;
                        _c2 = c2;
                    }
                }
            }
        }
    }

    cout << ans << ' ' << _r1 << ' ' << _c1 << ' ' << _r2 << ' ' << _c2 << '\n';
    return 0;
}
