#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MAXN = 1e5 + 1;
int n, k;
int a[MAXN];

int bSearch(int x)
{
    int l = 1, r = n;
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (a[m] == x)
            return m;
        if (a[m] < x) l = m + 1;
        else r = m - 1;
    }
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int x;
    while (k)
    {
        cin >> x;
        int idx = bSearch(x);
        if (idx == -1)
            cout << "NO" << '\n';
        else cout << "YES" << '\n';
        k--;
    }
    return 0;
}
