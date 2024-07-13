#include <bits/stdc++.h>
#define maxn 1001

using namespace std;
typedef long long ll;

struct Meeting {
    int a, b, num;
};

/// Mảng d dùng cho truy vết
ll n, f[maxn], d[maxn];
Meeting m[maxn];

bool Compare(Meeting x, Meeting y)
{
    if (x.a == y.a)
        return x.b <= y.b;
    return x.a < y.a;
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
        cin >> m[i].a >> m[i].b;
        m[i].num = i;
    }
    sort(m+1, m+1+n, Compare);
    for (ll i = 1; i <= n; i++)
    {
        f[i] = 1;
        for (ll j = 1; j < i; j++)
        {
            if (m[j].b <= m[i].a && f[i] < f[j] + 1)
            {
                f[i] = f[j] + 1;
                d[i] = j;
            }
        }
    }
    cout << f[n];
    return 0;
}
