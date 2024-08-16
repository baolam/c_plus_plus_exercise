#include <bits/stdc++.h>
#define maxn 10002

using namespace std;
typedef long long ll;

ll m, n, cnt = 0;
ll a[maxn][maxn];

bool check(int i1, int j1, int i2, int j2)
{
    if (a[i1][j1] == a[i1[j2])
        return false;
    if (a[i1][j1] == a[i2][j1])
        return false;
    if (a[i1][j1] == a[i2][j2])
        return false;
    if (a[i1][j2] == a[i2][j1])
        return false;
    if (a[i1][j2] == a[i2][j2])
        return false;
    if (a[i2][j1] == a[i2][j2])
        return false;
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> m >> n;

    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
    for (int i1 = 1; i1 <= m; i1++)
    {
        for (int j1 = 1; j1 <= n; j1++)
        {
            for (int i2 = i1 + 1; i2 <= m; i2++)
            {
                for (int j2 = j1 + 1; j2 <= n; j2++)
                {
                    if (check(i1, j1, i2, j2))
                        cnt++;
                }
            }
        }
    }
    cout << cnt;
    return 0;
}
