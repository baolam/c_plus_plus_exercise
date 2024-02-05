#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    int a[n], b[m];

    for (int i = 0; i < n; i++) cin >> a[i];
    for (int j = 0; j < m; j++) cin >> b[j];

    ll ans = 0;
    int i = 0, j = 0;
    while (i < n && j < m)
    {
        if (a[i] < b[j])
        {
            ++i; continue;
        }
        else if (a[i] > b[j])
        {
            ++j; continue;
        }
        else {
            int c1 = 0, c2 = 0;
            while (i < n && a[i] == b[j])
            {
                ++c1; ++i;
            }
            while (j < m && b[j] == a[i - 1])
            {
                ++c2; ++j;
            }

            ans += 1ll * c1 * c2;
        }
    }

    cout << ans;
    return 0;
}
