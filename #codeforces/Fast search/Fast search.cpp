#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MAXN = 1e5 + 1;
int n, k;
int a[MAXN];

int firstAbove(int x)
{
    int l = 0, r = n + 1;
    while (l + 1 < r)
    {
        int m = (l + r) / 2;
        if (a[m] < x) l = m;
        else r = m;
    }
    return r;
}

int lastLess(int x)
{
    int l = 0, r = n + 1;
    while (l + 1 < r)
    {
        int m = (l + r) / 2;
        if (a[m] <= x) l = m;
        else r = m;
    }
    return l;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a+1, a+1+n);
    cin >> k;
    int l, r;
    while (k)
    {
        cin >> l >> r;
        int m1 = firstAbove(l);
        int m2 = lastLess(r);
        if (m2 < m1)
            cout << 0 << '\n';
        else cout << m2 - m1 + 1 << '\n';
        k--;
    }
    return 0;
}
