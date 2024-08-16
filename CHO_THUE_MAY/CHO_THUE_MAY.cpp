#include <bits/stdc++.h>
#define maxn 10001

using namespace std;
typedef long long ll;

struct Value {
    ll a, b, c, num;
};

ll n, f[maxn];
Value x[maxn];

bool Compare(Value y, Value z)
{
    if (y.a == z.a)
        return y.b <= z.b;
    return y.a < z.a;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen("VAO.INP", "r", stdin);
    freopen("RA.OUT", "w", stdout);
    cin >> n;
    for (ll i = 1; i <= n; i++)
    {
        cin >> x[i].a >> x[i].b >> x[i].c;
        x[i].num = i;
    }
    sort(x+1, x+1+n, Compare);
    for (ll i = 1; i <= n; i++)
    {
        f[i] = m[i].c;
        for (ll j = 1; j < i; j++)
        {
            if (m[j].b <= m[i].a && f[i] < f[j] + m[i].c)
            {
                f[i] = f[j] + m[i].c;
            }
        }
    }
    cout << f[n];
    return 0;
}
