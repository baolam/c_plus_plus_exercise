#include <bits/stdc++.h>
#define maxm 1002
#define maxn 1002

using namespace std;
typedef int ll;

ll m, n;
ll h[maxn], l[maxn], r[maxn];
ll a[maxm][maxn];

int main()
{
    memset(h, 0, sizeof(h));
    memset(l, 0, sizeof(l));
    memset(r, 0, sizeof(r));
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen("INP.inp", "r", stdin);
    freopen("OUT.out", "w", stdout);
    cin >> m >> n;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
    int ans = 0;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (a[i][j] == 9)
                h[j]++;
            else h[j] = 0;
        }
        for (int j = 1; j <= n; j++)
        {
            l[j] = j;
            while (h[l[j] - 1] >= h[j]) {
                l[j] = l[l[j] - 1];
            }
        }
        for (int j = n; j >= 1; j--)
        {
            r[j] = j;
            while (h[r[j] + 1] >= h[j]) {
                r[j] = r[r[j] + 1];
            }
        }
        for (int j = 1; j <= n; j++)
            ans = max(ans, h[j] * (r[j] - l[j] + 1));
    }
    cout << ans;
    return 0;
}
