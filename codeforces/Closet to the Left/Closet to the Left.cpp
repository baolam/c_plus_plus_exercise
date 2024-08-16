#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MAXN = 1e5 + 1;
int n, k;
int a[MAXN];

int firstAbove(int x)
{
    // max i : a[i] > x
    // a[l] < a[r]
    // Maintaince
    // a[r] > x
    // a[l] <= x
    int l = 0, r = n + 1;
    while (l < r - 1)
    {
        int m = (l + r) / 2;
        if (a[m] <= x) l = m;
        else r = m;
    }
    return r;
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
        cout << firstAbove(x) - 1 << '\n';
        k--;
    }
    return 0;
}
