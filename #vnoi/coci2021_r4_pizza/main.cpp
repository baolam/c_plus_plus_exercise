#include <bits/stdc++.h>
#define MAXN 101

using namespace std;
typedef long long ll;

int n, a[MAXN];
int m, k, x;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    freopen("TEST.INP", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + 1 + n);

    int ans = 0;
    cin >> m;
    while (m--)
    {
        cin >> k;
        bool skip = false;
        while (k--)
        {
            cin >> x;
            if (skip)
                continue;
            bool exist = binary_search(a + 1, a + 1 + n, x);
            if (exist)
                skip = true;
        }
        if (!skip)
            ans++;
    }

    cout << ans;
    return 0;
}