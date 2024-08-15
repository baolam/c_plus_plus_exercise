#include <bits/stdc++.h>
#define maxn 100001

using namespace std;
typedef long long ll;

ll n, res = 1;
ll a[maxn], f[maxn];

int main()
{
    memset(f, 0, sizeof(f));
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen("VAO.INP", "r", stdin);
    //freopen("RA.OUT", "w", stdout);
    cin >> n;
    for (ll i = 1; i <= n; i++)
        cin >> a[i];
    f[1] = 1;
    for (ll i = 2; i <= n; i++)
    {
        if (a[i] > a[f[1]])
            f[1] = i;
        else
        {
            if (a[i] < a[f[res]])
            {
                res++;
                f[res] = i;
            }
            else
            {
                ll l = 1, r = res;
                while (l < r)
                {
                    ll m = l + (r - l) / 2;
                    if (a[m] > a[i])
                        l = m + 1;
                    else r = m;
                }
                f[l] = i;
            }
        }
    }
    cout << res;
    return 0;
}
