#include <bits/stdc++.h>
#define maxn 100001

using namespace std;
typedef long long ll;

ll n, k;
ll a[maxn], c[maxn];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    c[0] = 0;
    cin >> n >> k;
    for (ll i = 1; i <= n; i++)
    {
        cin >> a[i];
        c[i] = c[i - 1] + a[i];
    }

    for (ll j = n; j >= 1; j--)
    {
        for (ll i = 1; i <= j; j++)
        {
            ll tb = (c[j] - c[i - 1]) / (j - i + 1);
            if (tb == k)
            {
                cout << i << ' ' << j;
                return 0;
            }
        }
    }
    cout << -1;
    return 0;
}
