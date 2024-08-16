#include <bits/stdc++.h>
#define maxn 10001

using namespace std;
typedef long long ll;

ll n, S;
ll v[maxn], f[maxn];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen("VAO.INP", "r", stdin);
    freopen("RA.OUT", "w", stdout);
    f[0] = 0;
    cin >> n >> S;
    for (ll i = 1; i <= n; i++)
        cin >> v[i];
    for (ll i = 1; i <= S; i++)
        f[i] = -1;
    for (ll i = 1; i <= S; i++)
    {
        for (ll j = 1; j <= n; j++)
        {
            if (v[j] <= i && f[i - v[j]] != -1)
            {
                if (f[i] == -1)
                    f[i] = f[i - v[j]] + 1;
                else f[i] = min(f[i], f[i - v[j]] + 1);
            }
        }
    }
    cout << f[S];
    return 0;
}
