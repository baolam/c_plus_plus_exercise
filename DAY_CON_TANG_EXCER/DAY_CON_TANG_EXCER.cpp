#include <bits/stdc++.h>
#define maxn 1002

using namespace std;
typedef long long ll;

ll n;
ll a[maxn];
///
ll cs[maxn];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen("VAO.INP", "r", stdin);
    //freopen("RA.OUT", "w", stdout);
    cin >> n;
    for (ll i = 1; i <= n; i++)
        cin >> a[i];
    cs[1] = 1;
    ll k = 1;
    for (ll i = 2; i <= n; i++)
    {
        if (a[i] < a[cs[1]])
            cs[1] = i;
        else
        {
            if (a[i] > a[cs[k]])
            {
                k++;
                cs[k] = i;
            }
            else {
                ll l = 1, r = k;
                while (l < r)
                {
                    ll m = l + (r - l) / 2;
                    if (a[i] > a[cs[m]])
                        l = m + 1;
                    else r = m;
                }
                cs[l] = i;
            }
        }
    }
    cout << k << '\n';
    for (ll i = 1; i <= k; i++)
        cout << a[cs[i]] << ' ';
    return 0;
}
