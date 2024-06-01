#include <bits/stdc++.h>
#define maxn 1000002

using namespace std;
typedef long long ll;

ll n, res = 1;
ll a[maxn], c[maxn];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen("VAO.INP", "r", stdin);
    freopen("RA.OUT", "w", stdout);
    cin >> n;
    for (ll i = 1; i <= n; i++)
        cin >> a[i];
    c[1] = 1;
    for (ll i = 2; i <= n; i++)
    {
        if (a[i] < a[c[1]])
            c[1] = i;
        else {
            if (a[i] < a[c[res]])
                res++; c[res] = i;
            else {
                ll l = 1, r = res;
                while (l < r)
                {
                    ll m = l + (r - l) /2;
                    if (a[i] < a[c[m]])
                        r = m - 1;
                    else l = m + 1;
                }
                c[l] = i;
            }
        }
    }
    cout << res;
    return 0;
}
