#include <bits/stdc++.h>
#define maxn 100002

using namespace std;
typedef int ll;

ll n;
ll cs[maxn];
ll f1[maxn], f2[maxn], a[maxn];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen("VAO.INP", "r", stdin);
    //freopen("RA.OUT", "w", stdout);
    cin >> n;
    for (ll i = 1; i <= n; i++)
        cin >> a[i];
    // Dãy con tăng
    cs[1] = 1; f1[1] = 1;
    ll k = 1;
    for (ll i = 2; i <= n; i++)
    {
        if (a[i] < a[cs[1]])
        {
            cs[1] = i;
            f1[i] = 1;
        }
        else
        {
            if (a[i] > a[cs[k]])
            {
                k++;
                cs[k] = i;
                f1[i] = k;
            }
            else
            {
                ll l = 1, r = k;
                while (l < r)
                {
                    ll m = l + (r - l) / 2;
                    if (a[i] > a[cs[m]])
                        l = m + 1;
                    else r = m;
                }
                cs[l] = i; f1[i] = l;
            }
        }
    }
    cs[1] = n; f2[1] = 1;
    k = 1;
    for (ll i = n - 1; i >= 1; i--)
    {
        if (a[i] < a[cs[1]])
        {
            cs[1] = i;
            f2[i] = 1;
        }
        else
        {
            if (a[i] > a[cs[k]])
            {
                k++;
                cs[k] = i;
                f2[i] = k;
            }
            else
            {
                ll l = 1, r = k;
                while (l < r)
                {
                    ll m = l + (r - l) / 2;
                    if (a[i] > a[cs[m]])
                        l = m + 1;
                    else r = m;
                }
                cs[l] = i; f2[i] = l;
            }
        }
    }
    ll res = 0;
    for (ll i = 1; i <= n; i++)
        res = max(res, max(f1[i], f2[i]));
    cout << 2 * res + 1;
    return 0;
}
