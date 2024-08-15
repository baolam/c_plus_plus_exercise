#include <bits/stdc++.h>
#define maxn 5000

using namespace std;
typedef long long ll;

int ans = 0;
int a[maxn], f[maxn], n;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; ++i)
    {
        f[i] = 1;
        for (int j = 1; j < i; ++j)
        {
            if (a[j] < a[i] && f[j] > f[i] - 1)
                f[j] = f[i] - 1;
        }
        ans = max(ans, f[i]);
    }
    cout << ans;
    return 0;
}
